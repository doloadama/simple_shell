#include "shell.h"

/**
 * get_env - prints environment
 * @env: environment
 *
 */

void get_env(char **env)
{

int dem = 0;

while (env[dem]) /* tant que le compteur n'est pas nul ou négatif */
{

write(STDOUT_FILENO, env[dem], strlen(env[dem]));
write(STDOUT_FILENO, "\n", 1);
dem++;
}
}
