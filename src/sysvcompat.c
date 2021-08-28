#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

void
sysvcompat(int argc, const char *argv[])
{
	int sig;

	if (argc <= 1)
	{
		return;
	}

	switch (*argv[0])
	{
	 case '0':
		 sig = SIGUSR1;
		 break;
	 case '6':
		 sig = SIGINT;
		 break;
	 default:
		 return;
	}
	kill(1, sig);
	exit(EXIT_SUCCESS);
}
