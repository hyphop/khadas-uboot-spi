# make mainline uboot VIM1 VIM2 VIM3 VIM3L

https://github.com/hyphop/fenix/tree/hyphop

    git clone https://github.com/hyphop/fenix.git
    git checkout hyphop
    cd fenix
    ./scripts/make_uboots.sh

# output

    ls /tmp/uboot-mainline/ 

    u-boot.VIM1.bin     u-boot.VIM2.bin     u-boot.VIM3.bin   u-boot.VIM3L.sd.bin
    u-boot.VIM1.sd.bin  u-boot.VIM2.sd.bin  u-boot.VIM3L.bin  u-boot.VIM3.sd.bin

    