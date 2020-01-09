#!/bin/sh

echo $0

rm /etc/init.d/S99tp8.sh
# K2000 here for notification
/root/TP7/K2000 100 &

echo $?