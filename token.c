#include "shell.h"

/**
 * tokenize - tokenizes a buffer with a delimiter
 * @tampon: buffer to tokenize
 * @delim: delimiter to tokenize along
 *
 * Return: pointer to an array of pointers to the tokens
 */
char **tokenize(char *tampon, char *delim)
{
char **jeton = NULL;
int i = 0, count = 10;

if (tampon == NULL)
return (NULL);
jeton = malloc(sizeof(char *) * count);
if (jeton == NULL)
{
perror("Fatal Error");
return (NULL);
}
while ((jeton[i] = new_strtok(tampon, delim)) != NULL)
{
i++;
if (i == count)
{
jeton = _realloc(jeton, &count);
if (jeton == NULL)
{
perror("Fatal Error");
return (NULL);
}
}
jeton = NULL;
}
return (jeton);
}
