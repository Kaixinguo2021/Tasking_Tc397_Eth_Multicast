################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Libraries/iLLD/TC39B/Tricore/_PinMap/subdir.mk
-include Libraries/iLLD/TC39B/Tricore/_Lib/DataHandling/subdir.mk
-include Libraries/iLLD/TC39B/Tricore/_Impl/subdir.mk
-include Libraries/iLLD/TC39B/Tricore/Stm/Std/subdir.mk
-include Libraries/iLLD/TC39B/Tricore/Src/Std/subdir.mk
-include Libraries/iLLD/TC39B/Tricore/Scu/Std/subdir.mk
-include Libraries/iLLD/TC39B/Tricore/Port/Std/subdir.mk
-include Libraries/iLLD/TC39B/Tricore/Pms/Std/subdir.mk
-include Libraries/iLLD/TC39B/Tricore/Mtu/Std/subdir.mk
-include Libraries/iLLD/TC39B/Tricore/Gtm/Std/subdir.mk
-include Libraries/iLLD/TC39B/Tricore/Geth/Std/subdir.mk
-include Libraries/iLLD/TC39B/Tricore/Geth/Eth/subdir.mk
-include Libraries/iLLD/TC39B/Tricore/Cpu/Trap/subdir.mk
-include Libraries/iLLD/TC39B/Tricore/Cpu/Std/subdir.mk
-include Libraries/iLLD/TC39B/Tricore/Cpu/Irq/subdir.mk
-include Libraries/iLLD/TC39B/Tricore/Asclin/Std/subdir.mk
-include Libraries/iLLD/TC39B/Tricore/Asclin/Asc/subdir.mk
-include Libraries/UART/subdir.mk
-include Libraries/Service/CpuGeneric/SysSe/Comm/subdir.mk
-include Libraries/Service/CpuGeneric/StdIf/subdir.mk
-include Libraries/Infra/Ssw/TC39B/Tricore/subdir.mk
-include Libraries/Infra/Platform/Tricore/Compilers/subdir.mk
-include Libraries/Ethernet/lwip/src/netif/ppp/polarssl/subdir.mk
-include Libraries/Ethernet/lwip/src/netif/ppp/subdir.mk
-include Libraries/Ethernet/lwip/src/netif/subdir.mk
-include Libraries/Ethernet/lwip/src/core/ipv6/subdir.mk
-include Libraries/Ethernet/lwip/src/core/ipv4/subdir.mk
-include Libraries/Ethernet/lwip/src/core/subdir.mk
-include Libraries/Ethernet/lwip/src/api/subdir.mk
-include Libraries/Ethernet/lwip/port/src/subdir.mk
-include Libraries/Ethernet/Phy_Rtl8211f/subdir.mk
-include Configurations/Debug/subdir.mk
-include Configurations/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_SIZE += \
Ethernet_1_KIT_TC397_TFT.siz \


# All Target
all: Ethernet_1_KIT_TC397_TFT.elf secondary-outputs

# Tool invocations
Ethernet_1_KIT_TC397_TFT.elf: $(OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: TASKING Linker'
	cctc -lrt -lfp_fpu -lcs_fpu  -Wl-Oc -Wl-OL -Wl-Ot -Wl-Ox -Wl-Oy -Wl--map-file="Ethernet_1_KIT_TC397_TFT.map" -Wl-mc -Wl-mf -Wl-mi -Wl-mk -Wl-ml -Wl-mm -Wl-md -Wl-mr -Wl-mu --no-warnings= -Wl--error-limit=42 --exceptions --strict --anachronisms --force-c++ -Ctc39xb   -o"Ethernet_1_KIT_TC397_TFT.elf" -Wl-o"Ethernet_1_KIT_TC397_TFT.hex:IHEX" --lsl-core=vtc  --lsl-file=../Lcf_Tasking_Tricore_Tc.lsl $(OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

Ethernet_1_KIT_TC397_TFT.siz: Ethernet_1_KIT_TC397_TFT.elf
	@echo 'Invoking: Print Size'
	elfsize  "Ethernet_1_KIT_TC397_TFT.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	find . ! -name "*.mk" ! -name "makefile" ! -name "." -type f -delete 
	-@echo ' '

secondary-outputs: $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
