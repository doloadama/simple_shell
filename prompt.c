#include "shell.h"

/**
* read_line - reads the command line
* Return: line
*/

char *read_line(void)
{
char *line = NULL;
size_t size = 0;
int ret = 0;

if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "$ ", 2);


if (getline(&line, &size, stdin) == -1)
{
free(line);
exit(-1);
}
ret = strlen(line);
line[ret - 1] = '\0';

return (line);
}
