#include "mesures.h"

int main(void)
{
	int  fd_kp, fd_res;
	char val = '0';

	if ((fd_res = open(RES_FILE, O_CREAT | O_RDWR | O_APPEND, 0644)) == -1)
		perr_exit("open res");

	if (close(fd_res) == -1)
		perr_exit("close");

	if ((fd_kp = open(KP_FILE, O_CREAT | O_RDWR, 0644)) == -1)
		perr_exit("open");

	if (write(fd_kp, &val, sizeof(val)) == -1)
		perr_exit("write");

	if (close(fd_kp) == -1)
		perr_exit("close");

	// copy S99tp8.sh by using add_init.sh
	system(ADDINIT);
	// copy the first kernel and reboot
	system(SHZI(SH_ZIMG, ZI_0));

	return EXIT_SUCCESS;
}