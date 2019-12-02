#include "mesures.h"

int main(void)
{
	// need to use init_kp first
	int  fd_kp, fd_res;
	char kernel_preempt;
	// create file with char inside, read its value, after reboot we know which
	// kernel to copy and reboot to

	if ((fd_res = open(RES_FILE, O_CREAT | O_RDWR | O_APPEND, 0644)) == -1)
		perr_exit("open res");

	if (close(fd_res) == -1)
		perr_exit("close");

	// if the above worked : open, read, increment, write, close.
	if ((fd_kp = open(KP_FILE, O_RDWR, 0644)) == -1)
		perr_exit("open kp");

	if (read(fd_kp, &kernel_preempt, sizeof(kernel_preempt)) == -1)
		perr_exit("read");

	kernel_preempt++;

	if (write(fd_kp, &kernel_preempt, sizeof(kernel_preempt)) == -1)
		perr_exit("read");

	if (close(fd_kp) == -1)
		perr_exit("close");

	switch (kernel_preempt) {
	case 1:
		system(SHZI(SCRIPT, ZI_1));
		break;
	case 2:
		system(SHZI(SCRIPT, ZI_2));
		break;
	case 3:
		system(SHZI(SCRIPT, ZI_3));
		break;
	case 4:
		system(SHZI(SCRIPT, ZI_4));
		break;
	case 5:
		if (remove(KP_FILE) == -1)
			perr_exit("remove");
		break;
	default:
		errx(EXIT_FAILURE, "can't read which kernel to run !!!\n");
		break;
	}

	return EXIT_SUCCESS;
}