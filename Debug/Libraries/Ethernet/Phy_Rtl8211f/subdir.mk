################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/Ethernet/Phy_Rtl8211f/IfxGeth_Phy_Rtl8211f.c 

OBJS += \
./Libraries/Ethernet/Phy_Rtl8211f/IfxGeth_Phy_Rtl8211f.o 

COMPILED_SRCS += \
./Libraries/Ethernet/Phy_Rtl8211f/IfxGeth_Phy_Rtl8211f.src 

C_DEPS += \
./Libraries/Ethernet/Phy_Rtl8211f/IfxGeth_Phy_Rtl8211f.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/Ethernet/Phy_Rtl8211f/%.src: ../Libraries/Ethernet/Phy_Rtl8211f/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -D__CPU__=tc39xb "-fD:/WorkSpace/AurixStudio/Ethernet_1_KIT_TC397_TFT/Debug/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc39xb -o "$@"  "$<"  -cs --dep-file="$(@:.src=.d)" --misrac-version=2012 -N0 -Z0 -Y0 2>&1;
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Ethernet/Phy_Rtl8211f/%.o: ./Libraries/Ethernet/Phy_Rtl8211f/%.src
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -o  "$@" "$<" --list-format=L1 --optimize=gs
	@echo 'Finished building: $<'
	@echo ' '


