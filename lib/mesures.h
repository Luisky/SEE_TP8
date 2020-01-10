#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <err.h>

#define perr_exit(msg)                                                         \
	do {                                                                   \
		perror(msg);                                                   \
		exit(EXIT_FAILURE);                                            \
	} while (0)

#define KP_FILE "/root/TP8/kp"
#define RES_FILE "/root/TP8/results"

#define ADDINIT "cp /root/TP8/scripts/S99tp8.sh /etc/init.d/."
#define RMINIT "rm /etc/init.d/S99tp8.sh"
#define RUN_K2K "/root/TP7/K2000 100"

#define SH_ZIMG "/root/TP8/scripts/mnt_cpy_zimg.sh "

#define ZI_0 "server"
#define ZI_1 "desktop"
#define ZI_2 "lowlat"
#define ZI_3 "basicRT"
#define ZI_4 "RT"

#define SHZI(SN, ZI) SN ZI