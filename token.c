#include "shell.h"
#include <string.h>

/**
 * tokenize - tokenizes a stirng
 * @pointl: what the user inputed
 * Return: a ptr to arr of ptrs
 */

char **tokenize(char *pointl)
{

char **uticom = NULL;
char *jeton = NULL;

int i = 0;
int taille = 0;

if (pointl == NULL)
return (NULL);

for (i = 0; pointl[i]; i++)
{
if (pointl[i] == ' ')
taille++;
}

if ((taille + 1) == strlen(pointl))
return (NULL);

uticom = malloc(sizeof(char *) *(taille + 2));

if (uticom == NULL)
return (NULL);
   
jeton = strtok(pointl, "\n\t\r"); 

for (i = 0; jeton != NULL; i++)
{
uticom[i] = jeton;
jeton = strtok(NULL, "\n\t\r");
}
uticom[i] = NULL;
return (uticom);
}
