################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/core_functionality/CoreFunctionality.cpp 

OBJS += \
./src/core_functionality/CoreFunctionality.o 

CPP_DEPS += \
./src/core_functionality/CoreFunctionality.d 


# Each subdirectory must supply rules for building sources it contributes
src/core_functionality/%.o: ../src/core_functionality/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I/usr/local/include/opencv4/ -I/home/kmcgill/eclipse_workspace/opencv_tutorials/src/core_functionality/ -I/home/kmcgill/eclipse_workspace/opencv_tutorials/src/core_functionality2/ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


