################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"K:/CWProjectsDEV/Framework/Samples/loop_blink_fb32.c" \

C_SRCS += \
K:/CWProjectsDEV/Framework/Samples/loop_blink_fb32.c \

OBJS += \
./Sources/loop_blink_fb32_c.obj \

OBJS_QUOTED += \
"./Sources/loop_blink_fb32_c.obj" \

C_DEPS += \
./Sources/loop_blink_fb32_c.d \

OBJS_OS_FORMAT += \
./Sources/loop_blink_fb32_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/loop_blink_fb32_c.obj: K:/CWProjectsDEV/Framework/Samples/loop_blink_fb32.c
	@echo 'Building file: $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/loop_blink_fb32.args" -o "Sources/loop_blink_fb32_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/loop_blink_fb32_c.d: K:/CWProjectsDEV/Framework/Samples/loop_blink_fb32.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '


