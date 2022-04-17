################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Tp_1.c \
../src/libreria.c 

C_DEPS += \
./src/Tp_1.d \
./src/libreria.d 

OBJS += \
./src/Tp_1.o \
./src/libreria.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Tp_1.d ./src/Tp_1.o ./src/libreria.d ./src/libreria.o

.PHONY: clean-src

