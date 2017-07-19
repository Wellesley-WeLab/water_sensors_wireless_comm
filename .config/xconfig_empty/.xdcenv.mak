#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = /home/clx/ti/tirtos_cc13xx_cc26xx_2_21_00_06/packages;/home/clx/ti/tirtos_cc13xx_cc26xx_2_21_00_06/products/tidrivers_cc13xx_cc26xx_2_21_00_04/packages;/home/clx/ti/tirtos_cc13xx_cc26xx_2_21_00_06/products/bios_6_46_01_37/packages;/home/clx/ti/tirtos_cc13xx_cc26xx_2_21_00_06/products/uia_2_01_00_01/packages;/home/clx/Software/ti/ccsv7/ccs_base;/home/clx/workspace_v7/empty_CC1310DK_7XD_TI/.config
override XDCROOT = /home/clx/ti/xdctools_3_32_00_06_core
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = /home/clx/ti/tirtos_cc13xx_cc26xx_2_21_00_06/packages;/home/clx/ti/tirtos_cc13xx_cc26xx_2_21_00_06/products/tidrivers_cc13xx_cc26xx_2_21_00_04/packages;/home/clx/ti/tirtos_cc13xx_cc26xx_2_21_00_06/products/bios_6_46_01_37/packages;/home/clx/ti/tirtos_cc13xx_cc26xx_2_21_00_06/products/uia_2_01_00_01/packages;/home/clx/Software/ti/ccsv7/ccs_base;/home/clx/workspace_v7/empty_CC1310DK_7XD_TI/.config;/home/clx/ti/xdctools_3_32_00_06_core/packages;..
HOSTOS = Linux
endif
