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

#define SCRIPT "./mount_and_copy.sh "
#define ZI_0 "server"
#define ZI_1 "desktop"
#define ZI_2 "lowlat"
#define ZI_3 "basicRT"
#define ZI_4 "RT"

#define KP_FILE "kp"
#define RES_FILE "results"

#define SHZI(SN, ZI) SN ZI