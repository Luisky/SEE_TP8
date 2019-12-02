#include "mesures.h"

int main(void)
{
	int  fd_kp;
	char val = 0;

	if ((fd_kp = open(KP_FILE, O_CREAT | O_RDWR, 0644)) == -1)
		perr_exit("open");

	if (write(fd_kp, &val, sizeof(val)) == -1)
		perr_exit("write");

	if (close(fd_kp) == -1)
		perr_exit("close");

	system(SHZI(SCRIPT, ZI_0));

	return EXIT_SUCCESS;
}