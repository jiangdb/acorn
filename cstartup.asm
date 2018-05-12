;=====================================================================
; File Name   : cstartup.asm
; Description : Startup routine for csu8rp3216
;               This file contains the CSCC startup routine           
;               and must usually be tailored to suit customer's hardware
; Body Name   : csu8rp3216
; Toolchain   : cscc V1.0.x
; Date        : 09/10/2016
;=====================================================================


;=====================================================================
; Register define eare
;=====================================================================
ind0					.equ		0x0
fsr0					.equ		0x2
status					.equ		0x4	
;bsr					.equ		0x8	
eadrh					.equ		0xA
eadrl					.equ		0xB
edat					.equ		0xC



;======================================================================
; macro define : init bank0~1 all sram to zero 
;======================================================================
init_bank01_sram_to_zero .macro bankx_start_addr, bankx_sram_sizes, temp_label
	movlw bankx_sram_sizes-1				; bankx sram sizes(less than 0x100)
	movwf RSP								; temp var(stack var)
	movlw bankx_start_addr					; bankx sram start address
	movwf fsr0
	movlw 0x00
temp_label:
	movwf ind0
	incf fsr0,1
	decfsz RSP, 1
	goto temp_label
.endm



;=====================================================================
; Basic Settings for User
;=====================================================================
LOOP_AT_END				.equ 		1		; Endless waiting after main()
CPU_HALT				.equ 		0		; Exception of invalid instruction
BANK0_SRAM_START_ADDR	.equ		0x80	; Bank0 sram start address
BANK0_SRAM_SIZES		.equ		0x80	; Bank0 sram sizes
RSP						.equ		0xFF	; Pseudo stack point top(only at bank0)



;=====================================================================
; GLOBAL area
;=====================================================================
.global ind0							
.global fsr0
.global status
;.global bsr
.global eadrh
.global eadrl
.global edat


;=====================================================================
; EXTERN area
;=====================================================================
.extern _main							; where to begin execution
.extern CSCC_BANK0_INIT_TAB_START		; address of bank0 init table
.extern CSCC_BANK0_INIT_TAB_SIZE		; size of bank0 init table(word as a unit)
.extern CSCC_INTERRUPT_FUNCTION_ADDR	; interrupt function address






;=====================================================================
; Starting setup/reset code 
; CSCC_INIT_CODE - where the execution actually begins
;=====================================================================
CSCC_INIT_CODE 		.section rom,addr=0x00
V_RESET:
	goto __init_sram_to_zero
.ends



;=====================================================================
; Interrupt vector section 
;=====================================================================
CSCC_INTERRUPT_VECTOR	.section rom,addr=0x04
	goto CSCC_INTERRUPT_FUNCTION_ADDR
.ends



;======================================================================
; Init all sram to zero 
;======================================================================
CSCC_INIT_SRAM_TO_ZERO		.section rom
__init_sram_to_zero:
	;init bank0 sram
	init_bank01_sram_to_zero BANK0_SRAM_START_ADDR, BANK0_SRAM_SIZES, temp_bank0_init_label
	
	;goto init global var
	goto __init_global_var
.ends 	



;======================================================================
; Init all global variables 
;======================================================================
CSCC_INIT_GLOBAL_VAR		.section rom
__init_global_var:
	;set page0 valid
	;bcf bsr,0
	
	;init bank0 global var
	movlw .low(CSCC_BANK0_INIT_TAB_START)	;获取初始化表的低8位地址
	movwf eadrl								;给低字节地址赋值
	movlw .high(CSCC_BANK0_INIT_TAB_START)	;获取初始化表的高8位地址
	movwf eadrh								;给高字节地址赋值
	movlw CSCC_BANK0_INIT_TAB_SIZE			
	movwf RSP								;保存bank0初始化表的大小(word为单位)
	
	sublw 0									;判断初始化表的大小是否大于0
	btfsc status,0							;Z标志等于0代表结果为非0
	goto  __sp_init
	
bank0_init_var:
	;bcf bsr,7								;IRP0=0,间接寻址IND0时，访问bank0地址
	movp									;low to w(value), high to edath(address)
	movfw edat								;edath store var address
	movwf fsr0								;var address to fsr0
	movp
    movwf ind0								;init var
	incf eadrl,1							;address++ (low++)
	movlw 0									;set w to 0
	addwfc eadrh,1							;address high
	decfsz RSP,1							;--size
	goto bank0_init_var
	
__sp_init:									;sp reg init	
	goto __program_startup					
.ends



;=====================================================================	
; Now when we are init all global variables, then goto main function
;=====================================================================
.text
__program_startup:
	goto _main								; execute main()
	
__program_end:
;.if	LOOP_AT_END
;	goto	$								; 1. Endless Loop
;.endif
;.if CPU_HALT
;	halt									; 2. CPU Stop
;.endif
.ends

