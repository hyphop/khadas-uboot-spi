#!/bin/sh

# UBOOT_DIR FIP FIP_BUILD

CMD(){
    echo "[#] $@"
    $@
}

uboot_custom_postprocess() {

	UBOOT_DIR="$1"
	fip="$2"
	cd $UBOOT_DIR

	[ -f $fip/variables.sh ] || {
	    echo "[e] not found $fip/variables.sh">&2
	    exit 1
	}

	source $fip/variables.sh "$UBOOT_DIR" || {
	    echo "[e] source $fip/variables.sh $UBOOT_DIR">&2
	    exit 1
	}

	FIP_FOLDER="$2/"
	FIP_BUILD_FOLDER="$3"

	rm -rf ${FIP_BUILD_FOLDER}

	source $fip/lib.sh
	source $fip/build_bl2.sh
	source $fip/build_bl30.sh
	source $fip/build_bl31.sh
	source $fip/build_bl32.sh
	source $fip/build_bl33.sh
	source $fip/build_bl40.sh

	# source uboot pre-build configs

	source ${SOURCE_FILE}

	export_variables

	CUR_SOC=${CONFIG_SYS_SOC}

	echo "[i] CUR_SOC $CUR_SOC"

	if [ "y" == "${CONFIG_NEED_BL32}" ]; then
		BLX_NEEDFUL[3]="true"
	fi

	source ${FIP_FOLDER}${CUR_SOC}/variable_soc.sh

	# source soc package script
	source ${FIP_FOLDER}${CUR_SOC}/build.sh

	#bin_path_parser

	# source configs
	source ${CONFIG_FILE}
	if [ "y" == "${CONFIG_SUPPORT_CUSOTMER_BOARD}" ]; then
		BOARD_DIR="customer/board/${CONFIG_SYS_BOARD}"
	else
		BOARD_DIR="${CONFIG_BOARDDIR}"
	fi

	CMD mkdir -p ${FIP_BUILD_FOLDER}

	CMD cp ${FIP_FOLDER}${CUR_SOC}/bl2.bin $FIP_BUILD_FOLDER
	CMD cp ${FIP_FOLDER}${CUR_SOC}/bl30.bin $FIP_BUILD_FOLDER
	CMD cp ${FIP_FOLDER}${CUR_SOC}/bl31.bin $FIP_BUILD_FOLDER
	CMD cp ${FIP_FOLDER}${CUR_SOC}/bl31.img $FIP_BUILD_FOLDER
#	CMD cp ${FIP_FOLDER}${CUR_SOC}/bl32.bin $FIP_BUILD_FOLDER

	# cp bl33(uboot)
	#CMD copy_bl33

	#echo "cp $UBOOT_DIR/build/u-boot.bin $FIP_BUILD_FOLDER/bl33.bin">&2
	CMD cp $UBOOT_DIR/build/u-boot.bin $FIP_BUILD_FOLDER/bl33.bin

	# cp other firmwares(soc related)
	copy_other_soc

	# package final bootloader
	package

}