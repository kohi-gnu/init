#define _GNU_SOURCE /* XXX: remove this */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "kinit.h"

/*
 * XXX: 
 */

static void
default_parse_line(char const *line)
{
	char *p;
	char *ident;
	char *value;

	p = (char *)line;
	while (isspace(*p))
	{
		p++;
	}

	if (*p == '#') /* ignore comment */
	{
		return;
	}
	if ((ident = strtok(p, "=")) == NULL)
	{
		return;
	}
	if ((value = strtok(NULL, "=")) == NULL)
	{
		return;
	}

	setenv(ident, value, 1);
}

int
default_read(void)
{
	FILE *fp;
	char *line;
	size_t len;

	fp = fopen(DEFAULT_FILE, "r");
	if (fp == NULL)
	{
		return (-1);
	}

	while (getline(&line, &len, fp) != -1)
	{
		default_parse_line(line);
	}

	if (line)
	{
		free(line);
	}
	fclose(fp);

	return (0);
}
