#!/bin/sh

echo $0

mount /dev/mmcblk0p1 /mnt
cp /root/TP8/kernels-5.2/zImage_$1 /mnt/zImage
reboot

exit $?
