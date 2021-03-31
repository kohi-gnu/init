#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

int
main(int argc, const char *argv[])
{
	int             sig;

	if (getuid() != 0)
	{
		fprintf(stderr, "init: %s\n", strerror(EPERM));
		return (EXIT_FAILURE);
	}

	if (getpid() != 1)
	{
		if (argc > 1)
		{
			switch (*argv[1])
			{
			 case '0':
				 sig = SIGUSR2;
				 break;
			 case '6':
				 sig = SIGINT;
				 break;
			 default:
				 return (EXIT_FAILURE);
			}
			kill(1, sig);
			return (EXIT_SUCCESS);
		}
		else
		{
			fprintf(stderr, "init must be run at pid 1\n");
			return (EXIT_FAILURE);
		}
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
