################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/Ethernet/lwip/src/core/ipv6/dhcp6.c \
../Libraries/Ethernet/lwip/src/core/ipv6/ethip6.c \
../Libraries/Ethernet/lwip/src/core/ipv6/icmp6.c \
../Libraries/Ethernet/lwip/src/core/ipv6/inet6.c \
../Libraries/Ethernet/lwip/src/core/ipv6/ip6.c \
../Libraries/Ethernet/lwip/src/core/ipv6/ip6_addr.c \
../Libraries/Ethernet/lwip/src/core/ipv6/ip6_frag.c \
../Libraries/Ethernet/lwip/src/core/ipv6/mld6.c \
../Libraries/Ethernet/lwip/src/core/ipv6/nd6.c 

OBJS += \
./Libraries/Ethernet/lwip/src/core/ipv6/dhcp6.o \
./Libraries/Ethernet/lwip/src/core/ipv6/ethip6.o \
./Libraries/Ethernet/lwip/src/core/ipv6/icmp6.o \
./Libraries/Ethernet/lwip/src/core/ipv6/inet6.o \
./Libraries/Ethernet/lwip/src/core/ipv6/ip6.o \
./Libraries/Ethernet/lwip/src/core/ipv6/ip6_addr.o \
./Libraries/Ethernet/lwip/src/core/ipv6/ip6_frag.o \
./Libraries/Ethernet/lwip/src/core/ipv6/mld6.o \
./Libraries/Ethernet/lwip/src/core/ipv6/nd6.o 

COMPILED_SRCS += \
./Libraries/Ethernet/lwip/src/core/ipv6/dhcp6.src \
./Libraries/Ethernet/lwip/src/core/ipv6/ethip6.src \
./Libraries/Ethernet/lwip/src/core/ipv6/icmp6.src \
./Libraries/Ethernet/lwip/src/core/ipv6/inet6.src \
./Libraries/Ethernet/lwip/src/core/ipv6/ip6.src \
./Libraries/Ethernet/lwip/src/core/ipv6/ip6_addr.src \
./Libraries/Ethernet/lwip/src/core/ipv6/ip6_frag.src \
./Libraries/Ethernet/lwip/src/core/ipv6/mld6.src \
./Libraries/Ethernet/lwip/src/core/ipv6/nd6.src 

C_DEPS += \
./Libraries/Ethernet/lwip/src/core/ipv6/dhcp6.d \
./Libraries/Ethernet/lwip/src/core/ipv6/ethip6.d \
./Libraries/Ethernet/lwip/src/core/ipv6/icmp6.d \
./Libraries/Ethernet/lwip/src/core/ipv6/inet6.d \
./Libraries/Ethernet/lwip/src/core/ipv6/ip6.d \
./Libraries/Ethernet/lwip/src/core/ipv6/ip6_addr.d \
./Libraries/Ethernet/lwip/src/core/ipv6/ip6_frag.d \
./Libraries/Ethernet/lwip/src/core/ipv6/mld6.d \
./Libraries/Ethernet/lwip/src/core/ipv6/nd6.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/Ethernet/lwip/src/core/ipv6/%.src: ../Libraries/Ethernet/lwip/src/core/ipv6/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -D__CPU__=tc39xb "-fD:/WorkSpace/AurixStudio/Ethernet_1_KIT_TC397_TFT/Debug/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc39xb -o "$@"  "$<"  -cs --dep-file="$(@:.src=.d)" --misrac-version=2012 -N0 -Z0 -Y0 2>&1;
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Ethernet/lwip/src/core/ipv6/%.o: ./Libraries/Ethernet/lwip/src/core/ipv6/%.src
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -o  "$@" "$<" --list-format=L1 --optimize=gs
	@echo 'Finished building: $<'
	@echo ' '


