#include "shell.h"

/**
 * _getcommandline - get the input
 * Return: the argument in input
 */

char *_getcommandline(void){

char *ligne = NULL;
int utilisateur = 0;

if (isatty(STDIN_FILENO))
/**
 * isatty test whether
 * a file descriptor refers to a terminal
 */

write(STDOUT_FILENO, "$ ", 2);
if (getline(&ligne, &utilisateur, stdin) == -1)
{
free(ligne);
return (NULL);
}
return (ligne);
}
