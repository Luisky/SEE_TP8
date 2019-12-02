#!/bin/sh

mount /dev/mmcblk0p1 /mnt
cp /root/kernels-5.2/zImage_$1 /mnt/zImage

exit $?
