#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

#include <sys/wait.h>
#include <sys/stat.h>

#include "kinit.h"

static void
signal_handler(int signum)
{
	/* TODO */
	(void)signum;
}

char *const shell[] = { "/bin/ksh", NULL };

int
main(int argc, const char *argv[])
{
	pid_t pid;
	pid_t wpid;
	int status;

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

	/* setup sig handler */
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	signal(SIGUSR1, signal_handler);

	chdir("/");

	default_read();

	umask(0644); /* TODO: set umask from CMASK */

	/*inittab_read();*/

	while (1)
	{
		pid = fork();
		if (pid < 0)
		{
			return (EXIT_FAILURE); /* Oh no */
		}

		if (pid == 0)
		{
			execvp(shell[0], shell);
		}
		else
		{
			do
			{
				wpid = waitpid(pid, &status, WUNTRACED);
				if (wpid == -1) {
					perror("waitpid");
					exit(EXIT_FAILURE);
				}
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
	}

	/*
	 * unreachable 
	 */
	return (EXIT_SUCCESS);
}
