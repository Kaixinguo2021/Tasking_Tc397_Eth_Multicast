################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Infra.c \
../Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc0.c \
../Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc1.c \
../Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc2.c \
../Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc3.c \
../Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc4.c \
../Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc5.c 

OBJS += \
./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Infra.o \
./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc0.o \
./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc1.o \
./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc2.o \
./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc3.o \
./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc4.o \
./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc5.o 

COMPILED_SRCS += \
./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Infra.src \
./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc0.src \
./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc1.src \
./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc2.src \
./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc3.src \
./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc4.src \
./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc5.src 

C_DEPS += \
./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Infra.d \
./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc0.d \
./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc1.d \
./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc2.d \
./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc3.d \
./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc4.d \
./Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc5.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/Infra/Ssw/TC39B/Tricore/%.src: ../Libraries/Infra/Ssw/TC39B/Tricore/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -D__CPU__=tc39xb "-fD:/WorkSpace/AurixStudio/Ethernet_1_KIT_TC397_TFT/Debug/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc39xb -o "$@"  "$<"  -cs --dep-file="$(@:.src=.d)" --misrac-version=2012 -N0 -Z0 -Y0 2>&1;
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Infra/Ssw/TC39B/Tricore/%.o: ./Libraries/Infra/Ssw/TC39B/Tricore/%.src
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -o  "$@" "$<" --list-format=L1 --optimize=gs
	@echo 'Finished building: $<'
	@echo ' '


