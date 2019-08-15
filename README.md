# khadas u-boot-spi

special u-boot for spi usage on Khadas VIMs boards based on legacy u-boot from amlogic

## Features

+ extreme fast load from spi flash at maximum 104Mhz speed
+ fully work from spi flash or sd card
+ env + dtb + logo  located at spi flash or loaded from sd
+ ready for only spi usage and boot linux whole from spi flash
+ removed many amlogic emmc and other parts
+ some extra commands like `script`
+ lzma compression
+ ....

## usage & install

just put on same dir level as fenix https://github.com/khadas/fenix

```
git clone https://github.com/khadas/fenix
# prepare source
# source source env/setenv.sh
# make uboot
git clone https://github.com/hyphop/khadas-uboot-spi
cd khadas-uboot-spi/scripts
# build mainline uboot
./make_uboot_mainline_vim2

```
## scripts

+ [scripts](scripts)

## Downloads

https://github.com/hyphop/khadas-uboot-spi/releases

## spi usage 

for spi usage u can use this link https://github.com/hyphop/khadas-rescue for build full spi images

## related projects

+ https://github.com/hyphop/khadas-rescue
+ https://github.com/hyphop/khadas-openwrt
+ https://github.com/hyphop/khadas-linux-kernel
+ https://github.com/khadas/fenix

## Status

experemental

