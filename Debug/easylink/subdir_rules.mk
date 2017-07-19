################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
easylink/EasyLink.obj: ../easylink/EasyLink.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/home/clx/Software/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.1.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="/media/DATA/Docs/programas/water_sensor/water_sensor_wireless_comm" --include_path="/media/DATA/Docs/programas/water_sensor/water_sensor_wireless_comm" --include_path="/home/clx/ti/tirtos_cc13xx_cc26xx_2_21_00_06/products/cc13xxware_2_04_03_17272" --include_path="/home/clx/Software/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.1.LTS/include" --define=ccs -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="easylink/EasyLink.d" --obj_directory="easylink" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


