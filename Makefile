###################################################
#工具链定义处
###################################################
TOOLCHAIN_DIR = C:\Program Files\Chipsea\CSU-IDE V5.1.2\chipsea\tools\Compiler\C
ASM	   				= "$(TOOLCHAIN_DIR)\csasm.exe"
CC    				= "$(TOOLCHAIN_DIR)\cscc.exe"
LINKER 				= "$(TOOLCHAIN_DIR)\cslinker.exe"
RM	   				= del /F 1>NUL 2>NUL
ECHO			    = @echo //-----------------------------------------------------------------------



###################################################
#编译选项定义处
###################################################
OUTPUT_DIR            = D:\workspace\projects\acorn\.\Release
INTERTMP_DIR          = D:\workspace\projects\acorn\.\Release
PROJ_PATH			  = D:\workspace\projects\acorn
PROJ_NAME			  = Acron
BODY_NAME			  = CSU8RP3216
CFLAGS                = -cc1 -S -debug-info-kind=limited  -O0 -triple=cscc -fno-inline -chip=CSU8RP3216
ASMFLAGS              = -filetype=obj -arch=cscc -fill=0xffff -chip=CSU8RP3216 -mattr=c16 -BankCount=1
LINKFLAGS             = -bt 16
CODE_OPTION			  = %%CodeOption%%
ASM_FILES			  = "$(INTERTMP_DIR)\adc.asm" \
"$(INTERTMP_DIR)\data.asm" \
"$(INTERTMP_DIR)\delay.asm" \
"$(INTERTMP_DIR)\initialization.asm" \
"$(INTERTMP_DIR)\lowpower.asm" \
"$(INTERTMP_DIR)\main.asm" \
"$(INTERTMP_DIR)\SysRegDefine.asm" \
"D:\workspace\projects\acorn\check_list.asm" \
"D:\workspace\projects\acorn\cstartup.asm"

OBJ_FILES			  = "$(INTERTMP_DIR)\adc.obj" \
"$(INTERTMP_DIR)\data.obj" \
"$(INTERTMP_DIR)\delay.obj" \
"$(INTERTMP_DIR)\initialization.obj" \
"$(INTERTMP_DIR)\lowpower.obj" \
"$(INTERTMP_DIR)\main.obj" \
"$(INTERTMP_DIR)\SysRegDefine.obj" \
"$(INTERTMP_DIR)\check_list.obj" \
"$(INTERTMP_DIR)\cstartup.obj"

OUTPUT_OTHER_FILES	  = "$(INTERTMP_DIR)\*.asm" \
						    "$(INTERTMP_DIR)\*.obj" \
                            "$(INTERTMP_DIR)\*.map"	\
							"$(INTERTMP_DIR)\*.txt"	\
							"$(INTERTMP_DIR)\*.sbms" \
							"$(INTERTMP_DIR)\*.cscc_bk"



###################################################
#.C文件到.ASM文件
###################################################
"$(INTERTMP_DIR)\adc.asm" : "D:\workspace\projects\acorn\adc.c" \
 "D:\workspace\projects\acorn\CSU8RP3216.h" \
 "D:\workspace\projects\acorn\define_function.h" \
 "D:\workspace\projects\acorn\define_data.h"
	$(CC) $(CFLAGS)  "D:\workspace\projects\acorn\adc.c" -o "$(INTERTMP_DIR)\adc.asm" 
	$(ECHO)
"$(INTERTMP_DIR)\data.asm" : "D:\workspace\projects\acorn\data.c"
	$(CC) $(CFLAGS)  "D:\workspace\projects\acorn\data.c" -o "$(INTERTMP_DIR)\data.asm" 
	$(ECHO)
"$(INTERTMP_DIR)\delay.asm" : "D:\workspace\projects\acorn\delay.c" \
 "D:\workspace\projects\acorn\define_function.h" \
 "D:\workspace\projects\acorn\define_data.h" \
 "D:\workspace\projects\acorn\CSU8RP3216.h"
	$(CC) $(CFLAGS)  "D:\workspace\projects\acorn\delay.c" -o "$(INTERTMP_DIR)\delay.asm" 
	$(ECHO)
"$(INTERTMP_DIR)\initialization.asm" : "D:\workspace\projects\acorn\initialization.c" \
 "D:\workspace\projects\acorn\CSU8RP3216.h" \
 "D:\workspace\projects\acorn\define_function.h" \
 "D:\workspace\projects\acorn\define_data.h"
	$(CC) $(CFLAGS)  "D:\workspace\projects\acorn\initialization.c" -o "$(INTERTMP_DIR)\initialization.asm" 
	$(ECHO)
"$(INTERTMP_DIR)\lowpower.asm" : "D:\workspace\projects\acorn\lowpower.c" \
 "D:\workspace\projects\acorn\CSU8RP3216.h" \
 "D:\workspace\projects\acorn\define_function.h" \
 "D:\workspace\projects\acorn\define_data.h"
	$(CC) $(CFLAGS)  "D:\workspace\projects\acorn\lowpower.c" -o "$(INTERTMP_DIR)\lowpower.asm" 
	$(ECHO)
"$(INTERTMP_DIR)\main.asm" : "D:\workspace\projects\acorn\main.c" \
 "D:\workspace\projects\acorn\CSU8RP3216.h" \
 "D:\workspace\projects\acorn\define_function.h" \
 "D:\workspace\projects\acorn\define_data.h"
	$(CC) $(CFLAGS)  "D:\workspace\projects\acorn\main.c" -o "$(INTERTMP_DIR)\main.asm" 
	$(ECHO)
"$(INTERTMP_DIR)\SysRegDefine.asm" : "D:\workspace\projects\acorn\SysRegDefine.c"
	$(CC) $(CFLAGS)  "D:\workspace\projects\acorn\SysRegDefine.c" -o "$(INTERTMP_DIR)\SysRegDefine.asm" 
	$(ECHO)

#main.asm :
#	$(CC) $(CFLAGS) "$(PROJ_PATH)\main.c" -o "$(PROJ_PATH)\main.asm"
#	$(ECHO)

###################################################
#.ASM文件到.OBJ文件
###################################################
"$(INTERTMP_DIR)\adc.obj" : "$(INTERTMP_DIR)\adc.asm"
	$(ASM) $(ASMFLAGS)  "$(INTERTMP_DIR)\adc.asm" -o "$(INTERTMP_DIR)\adc.obj" 
	$(ECHO)
"$(INTERTMP_DIR)\data.obj" : "$(INTERTMP_DIR)\data.asm"
	$(ASM) $(ASMFLAGS)  "$(INTERTMP_DIR)\data.asm" -o "$(INTERTMP_DIR)\data.obj" 
	$(ECHO)
"$(INTERTMP_DIR)\delay.obj" : "$(INTERTMP_DIR)\delay.asm"
	$(ASM) $(ASMFLAGS)  "$(INTERTMP_DIR)\delay.asm" -o "$(INTERTMP_DIR)\delay.obj" 
	$(ECHO)
"$(INTERTMP_DIR)\initialization.obj" : "$(INTERTMP_DIR)\initialization.asm"
	$(ASM) $(ASMFLAGS)  "$(INTERTMP_DIR)\initialization.asm" -o "$(INTERTMP_DIR)\initialization.obj" 
	$(ECHO)
"$(INTERTMP_DIR)\lowpower.obj" : "$(INTERTMP_DIR)\lowpower.asm"
	$(ASM) $(ASMFLAGS)  "$(INTERTMP_DIR)\lowpower.asm" -o "$(INTERTMP_DIR)\lowpower.obj" 
	$(ECHO)
"$(INTERTMP_DIR)\main.obj" : "$(INTERTMP_DIR)\main.asm"
	$(ASM) $(ASMFLAGS)  "$(INTERTMP_DIR)\main.asm" -o "$(INTERTMP_DIR)\main.obj" 
	$(ECHO)
"$(INTERTMP_DIR)\SysRegDefine.obj" : "$(INTERTMP_DIR)\SysRegDefine.asm"
	$(ASM) $(ASMFLAGS)  "$(INTERTMP_DIR)\SysRegDefine.asm" -o "$(INTERTMP_DIR)\SysRegDefine.obj" 
	$(ECHO)
"$(INTERTMP_DIR)\check_list.obj" : "D:\workspace\projects\acorn\check_list.asm"
	$(ASM) $(ASMFLAGS) -gstab "D:\workspace\projects\acorn\check_list.asm" -o "$(INTERTMP_DIR)\check_list.obj" 
	$(ECHO)
"$(INTERTMP_DIR)\cstartup.obj" : "D:\workspace\projects\acorn\cstartup.asm"
	$(ASM) $(ASMFLAGS) -gstab "D:\workspace\projects\acorn\cstartup.asm" -o "$(INTERTMP_DIR)\cstartup.obj" 
	$(ECHO)

#main.obj :
#	$(ASM) $(ASMFLAGS) "$(PROJ_PATH)\main.asm" -o "$(PROJ_PATH)\main.obj"
#	$(ECHO)

###################################################
#命令定义处
###################################################
.PHONY : build
build  : prebuild outputdir compiler_all_c_files compiler_all_asm_files binfile postbuild

.PHONY : rebuild
rebuild: prebuild outputdir clean_buildfile build postbuild

.PHONY : clean
clean :
	$(RM)  "$(INTERTMP_DIR)\dee"
	$(RM)  "$(INTERTMP_DIR)\*.lik"
	$(RM)  "$(INTERTMP_DIR)\*.lst"
	$(RM)  $(OUTPUT_OTHER_FILES)
	$(RM)  "$(OUTPUT_DIR)\$(PROJ_NAME).hex"
	$(RM)  "$(INTERTMP_DIR)\$(PROJ_NAME).dat"
	$(ECHO)

clean_buildfile :
	$(RM)  $(OUTPUT_OTHER_FILES)
	$(RM)  "$(OUTPUT_DIR)\$(PROJ_NAME).hex"
	$(ECHO)
    
outputdir:
	if not exist "$(OUTPUT_DIR)/$(NULL)" mkdir "$(OUTPUT_DIR)"
	if not exist "$(INTERTMP_DIR)/$(NULL)" mkdir "$(INTERTMP_DIR)"
	$(ECHO)
	
binfile: 
	$(LINKER) $(LINKFLAGS) -s "$(INTERTMP_DIR)\Script.lik"
	$(ECHO)
	
compiler_all_c_files : $(ASM_FILES)

compiler_all_asm_files: $(OBJ_FILES)

prebuild :
	

postbuild :
	

