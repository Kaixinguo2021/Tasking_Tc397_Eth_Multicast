################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/Ethernet/lwip/src/netif/bridgeif.c \
../Libraries/Ethernet/lwip/src/netif/bridgeif_fdb.c \
../Libraries/Ethernet/lwip/src/netif/ethernet.c \
../Libraries/Ethernet/lwip/src/netif/lowpan6.c \
../Libraries/Ethernet/lwip/src/netif/lowpan6_ble.c \
../Libraries/Ethernet/lwip/src/netif/lowpan6_common.c \
../Libraries/Ethernet/lwip/src/netif/zepif.c 

OBJS += \
./Libraries/Ethernet/lwip/src/netif/bridgeif.o \
./Libraries/Ethernet/lwip/src/netif/bridgeif_fdb.o \
./Libraries/Ethernet/lwip/src/netif/ethernet.o \
./Libraries/Ethernet/lwip/src/netif/lowpan6.o \
./Libraries/Ethernet/lwip/src/netif/lowpan6_ble.o \
./Libraries/Ethernet/lwip/src/netif/lowpan6_common.o \
./Libraries/Ethernet/lwip/src/netif/zepif.o 

COMPILED_SRCS += \
./Libraries/Ethernet/lwip/src/netif/bridgeif.src \
./Libraries/Ethernet/lwip/src/netif/bridgeif_fdb.src \
./Libraries/Ethernet/lwip/src/netif/ethernet.src \
./Libraries/Ethernet/lwip/src/netif/lowpan6.src \
./Libraries/Ethernet/lwip/src/netif/lowpan6_ble.src \
./Libraries/Ethernet/lwip/src/netif/lowpan6_common.src \
./Libraries/Ethernet/lwip/src/netif/zepif.src 

C_DEPS += \
./Libraries/Ethernet/lwip/src/netif/bridgeif.d \
./Libraries/Ethernet/lwip/src/netif/bridgeif_fdb.d \
./Libraries/Ethernet/lwip/src/netif/ethernet.d \
./Libraries/Ethernet/lwip/src/netif/lowpan6.d \
./Libraries/Ethernet/lwip/src/netif/lowpan6_ble.d \
./Libraries/Ethernet/lwip/src/netif/lowpan6_common.d \
./Libraries/Ethernet/lwip/src/netif/zepif.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/Ethernet/lwip/src/netif/%.src: ../Libraries/Ethernet/lwip/src/netif/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -D__CPU__=tc39xb "-fD:/WorkSpace/AurixStudio/Ethernet_1_KIT_TC397_TFT/Debug/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc39xb -o "$@"  "$<"  -cs --dep-file="$(@:.src=.d)" --misrac-version=2012 -N0 -Z0 -Y0 2>&1;
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Ethernet/lwip/src/netif/%.o: ./Libraries/Ethernet/lwip/src/netif/%.src
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -o  "$@" "$<" --list-format=L1 --optimize=gs
	@echo 'Finished building: $<'
	@echo ' '


