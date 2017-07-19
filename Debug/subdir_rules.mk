################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
CC1310DK_7XD.obj: ../CC1310DK_7XD.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/home/clx/Software/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.1.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="/media/DATA/Docs/programas/water_sensor/water_sensor_wireless_comm" --include_path="/media/DATA/Docs/programas/water_sensor/water_sensor_wireless_comm" --include_path="/home/clx/ti/tirtos_cc13xx_cc26xx_2_21_00_06/products/cc13xxware_2_04_03_17272" --include_path="/home/clx/Software/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.1.LTS/include" --define=ccs -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="CC1310DK_7XD.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

RF_Com.obj: ../RF_Com.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/home/clx/Software/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.1.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="/media/DATA/Docs/programas/water_sensor/water_sensor_wireless_comm" --include_path="/media/DATA/Docs/programas/water_sensor/water_sensor_wireless_comm" --include_path="/home/clx/ti/tirtos_cc13xx_cc26xx_2_21_00_06/products/cc13xxware_2_04_03_17272" --include_path="/home/clx/Software/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.1.LTS/include" --define=ccs -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="RF_Com.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

ToServer_Com.obj: ../ToServer_Com.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/home/clx/Software/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.1.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="/media/DATA/Docs/programas/water_sensor/water_sensor_wireless_comm" --include_path="/media/DATA/Docs/programas/water_sensor/water_sensor_wireless_comm" --include_path="/home/clx/ti/tirtos_cc13xx_cc26xx_2_21_00_06/products/cc13xxware_2_04_03_17272" --include_path="/home/clx/Software/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.1.LTS/include" --define=ccs -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="ToServer_Com.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

ccfg.obj: ../ccfg.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/home/clx/Software/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.1.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="/media/DATA/Docs/programas/water_sensor/water_sensor_wireless_comm" --include_path="/media/DATA/Docs/programas/water_sensor/water_sensor_wireless_comm" --include_path="/home/clx/ti/tirtos_cc13xx_cc26xx_2_21_00_06/products/cc13xxware_2_04_03_17272" --include_path="/home/clx/Software/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.1.LTS/include" --define=ccs -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="ccfg.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/home/clx/Software/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.1.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="/media/DATA/Docs/programas/water_sensor/water_sensor_wireless_comm" --include_path="/media/DATA/Docs/programas/water_sensor/water_sensor_wireless_comm" --include_path="/home/clx/ti/tirtos_cc13xx_cc26xx_2_21_00_06/products/cc13xxware_2_04_03_17272" --include_path="/home/clx/Software/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.1.LTS/include" --define=ccs -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="main.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

util.obj: ../util.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/home/clx/Software/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.1.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="/media/DATA/Docs/programas/water_sensor/water_sensor_wireless_comm" --include_path="/media/DATA/Docs/programas/water_sensor/water_sensor_wireless_comm" --include_path="/home/clx/ti/tirtos_cc13xx_cc26xx_2_21_00_06/products/cc13xxware_2_04_03_17272" --include_path="/home/clx/Software/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.1.LTS/include" --define=ccs -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="util.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

build-1651658767:
	@$(MAKE) -Onone -f subdir_rules.mk build-1651658767-inproc

build-1651658767-inproc: ../water_sensor_wireless_comm.cfg
	@echo 'Building file: $<'
	@echo 'Invoking: XDCtools'
	"/home/clx/ti/xdctools_3_32_00_06_core/xs" --xdcpath="/home/clx/ti/tirtos_cc13xx_cc26xx_2_21_00_06/packages;/home/clx/ti/tirtos_cc13xx_cc26xx_2_21_00_06/products/tidrivers_cc13xx_cc26xx_2_21_00_04/packages;/home/clx/ti/tirtos_cc13xx_cc26xx_2_21_00_06/products/bios_6_46_01_37/packages;/home/clx/ti/tirtos_cc13xx_cc26xx_2_21_00_06/products/uia_2_01_00_01/packages;/home/clx/Software/ti/ccsv7/ccs_base;" xdc.tools.configuro -o configPkg -t ti.targets.arm.elf.M3 -p ti.platforms.simplelink:CC1310F128 -r release -c "/home/clx/Software/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.1.LTS" --compileOptions "-mv7M3 --code_state=16 --float_support=vfplib -me --include_path=\"/media/DATA/Docs/programas/water_sensor/water_sensor_wireless_comm\" --include_path=\"/media/DATA/Docs/programas/water_sensor/water_sensor_wireless_comm\" --include_path=\"/home/clx/ti/tirtos_cc13xx_cc26xx_2_21_00_06/products/cc13xxware_2_04_03_17272\" --include_path=\"/home/clx/Software/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.1.LTS/include\" --define=ccs -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi  " "$<"
	@echo 'Finished building: $<'
	@echo ' '

configPkg/linker.cmd: build-1651658767 ../water_sensor_wireless_comm.cfg
configPkg/compiler.opt: build-1651658767
configPkg/: build-1651658767


