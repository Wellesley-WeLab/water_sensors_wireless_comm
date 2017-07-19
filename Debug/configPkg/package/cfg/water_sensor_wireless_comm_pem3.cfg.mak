# invoke SourceDir generated makefile for water_sensor_wireless_comm.pem3
water_sensor_wireless_comm.pem3: .libraries,water_sensor_wireless_comm.pem3
.libraries,water_sensor_wireless_comm.pem3: package/cfg/water_sensor_wireless_comm_pem3.xdl
	$(MAKE) -f /media/DATA/Docs/programas/water_sensor/water_sensor_wireless_comm/src/makefile.libs

clean::
	$(MAKE) -f /media/DATA/Docs/programas/water_sensor/water_sensor_wireless_comm/src/makefile.libs clean

