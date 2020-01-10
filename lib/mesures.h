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

#define MNTCPY "/root/TP8/scripts/mnt_cpy_zimg.sh "
#define ADDINIT "/root/TP8/scripts/add_init.sh"
#define RMINIT "/root/TP8/scripts/rm_init.sh"

#define ZI_0 "server"
#define ZI_1 "desktop"
#define ZI_2 "lowlat"
#define ZI_3 "basicRT"
#define ZI_4 "RT"

#define KP_FILE "/root/TP8/kp"
#define RES_FILE "/root/TP8/results"

#define SHZI(SN, ZI) SN ZI