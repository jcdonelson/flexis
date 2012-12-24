################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/exceptions_asmex1.c" \

ASM_SRCS += \
../Sources/main_ex1.asm \

C_SRCS += \
../Sources/exceptions_asmex1.c \

ASM_SRCS_QUOTED += \
"../Sources/main_ex1.asm" \

OBJS += \
./Sources/exceptions_asmex1_c.obj \
./Sources/main_ex1_asm.obj \

OBJS_QUOTED += \
"./Sources/exceptions_asmex1_c.obj" \
"./Sources/main_ex1_asm.obj" \

C_DEPS += \
./Sources/exceptions_asmex1_c.d \

OBJS_OS_FORMAT += \
./Sources/exceptions_asmex1_c.obj \
./Sources/main_ex1_asm.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/exceptions_asmex1_c.obj: ../Sources/exceptions_asmex1.c
	@echo 'Building file: $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/exceptions_asmex1.args" -o "Sources/exceptions_asmex1_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/main_ex1_asm.obj: ../Sources/main_ex1.asm
	@echo 'Building file: $<'
	@echo 'Invoking: ColdFire Assembler'
	"$(CF_ToolsDirEnv)/mwasmmcf" @@"Sources/main_ex1.args" -o "Sources/main_ex1_asm.obj" "$<"
	@echo 'Finished building: $<'
	@echo ' '


