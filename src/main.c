#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

#include "kinit.h"

int
main(int argc, const char *argv[])
{
	if (getuid() != 0)
	{
		fprintf(stderr, "init: %s\n", strerror(EPERM));
		return (EXIT_FAILURE);
	}

	if (getpid() != 1)
	{
		sysvcompat(argc, argv);
		fprintf(stderr, "init must be run at pid 1\n");
		return (EXIT_FAILURE);
	}

	chdir("/");

	while (1)
	{
		/*
		 * TODO 
		 */
	}

	/*
	 * unreachable 
	 */
	return (EXIT_SUCCESS);
}
