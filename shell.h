#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>



char *_getcommandline(void);
void get_env(char **env);
int ctrld(char **args);











#endif /* _SHELL_H_ */
