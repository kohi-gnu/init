#ifndef KINIT_H
# define KINIT_H 1

# define DEFAULT_FILE "/etc/default/init"
# define INITTAB_FILE "/etc/inittab"

/*
 * -----------------------------------------------------------------------------
 * default.c
 * -----------------------------------------------------------------------------
 * parse `/etc/default/init` file
 */
int default_read(void);

/*
 * -----------------------------------------------------------------------------
 * sysvcompat.c 
 * -----------------------------------------------------------------------------
 * sysvinit command line compatibility
 */
void sysvcompat(int, const char **);

#endif /* !KINIT_H */
