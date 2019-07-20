################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Main.cpp \
../src/ParseUtils.cpp 

OBJS += \
./src/Main.o \
./src/ParseUtils.o 

CPP_DEPS += \
./src/Main.d \
./src/ParseUtils.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I/usr/local/include/opencv4/ -I/home/kmcgill/eclipse_workspace/opencv_tutorials/src/core_functionality/ -I/home/kmcgill/eclipse_workspace/opencv_tutorials/src/core_functionality2/ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


