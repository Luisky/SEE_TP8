#!/bin/sh
#
# Start the TP8 main program
#

# echo the kernel version 0,1,2,3 or 4
echo "kernel number : $(cat /root/TP8/kp)" >> /root/TP8/results
# do the calculations (with or without perturbator)
#/root/TP2/perturbator &
/root/TP2/ordo >> /root/TP8/results
# switch kernels
/root/TP8/switch_kp

exit $?