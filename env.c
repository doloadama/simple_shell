#include "shell.h"

/**
 * mk_env - prints environment
 * @env: environment
 *
 */


char **mk_env(char **env)
{
char **new_env = NULL;
int i;
for (i = 0; env[i] != NULL; i++)
;
new_env = malloc(sizeof(char *) * (i + 1));
if (new_env == NULL)
{
perror("ERROR");
exit(1);
}
for (i = 0; env[i] != NULL; i++)
new_env[i] = strdup(env[i]);
new_env[i] = NULL;
return (new_env);
}

/**
 * free_env - free the shell's environment
 * @env: shell's environment
 *
 * Return: void
 */
void free_env(char **env)
{
unsigned int i;

for (i = 0; env[i] != NULL; i++)
free(env[i]);
free(env);
}
