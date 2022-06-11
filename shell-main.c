#include "shell.h"

/**
 * main - Main arguments functions
 * @ac: Count of argumnents
 * @av: Arguments
 * @env: Environment
 * Return: _exit = 0.
 */


int main()
{
int status = 0;
char *ligne = NULL, **commandes = NULL;
/**
 * @ligne: the input
 * @commandes: command token
 */

while (1)
{
errno = 0;

ligne = _getcommandline();

if (ligne == NULL && errno == 0)
return (0);

if (ligne)
{
commandes = tokenize(ligne);
if (!commandes)
free(ligne);
}
else
{
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "\n", 1);
exit(status);
}
free(ligne);
}
return (status);
}
