#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int
main(void)
{
	if (getpid() != 1)
	{
		fprintf(stderr, "init must be run at pid 1\n");
		return (EXIT_FAILURE);
	}

	chdir("/");
	while (1)
	{
	}

	/* unreachable */
	return (EXIT_SUCCESS);
}
