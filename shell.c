#include "shell.h"


unsigned int flag;

/**
 * ctrlD - handles ^C signal interupt
 * @uuv: unused variable (required for signal function prototype)
 *
 * Return: void
 */
static void ctrlD(int uuv)
{
(void) uuv;
if (flag == 0)
puts("\n$ ");
else
puts("\n");
}


/**
 * main - Main arguments functions
 * @argc: Count of argumnents
 * @argv: Arguments
 * @env: Environment
 * Return: _exit = 0.
 */


int main(int argc __attribute__((unused)), char **argv, char **env)
{
size_t len_buffer = 0;
unsigned int is_pipe = 0, i;
vars_t vars = {NULL, NULL, NULL, 0, NULL, 0, NULL};

vars.argv = argv;
vars.env = mk_env(env);
signal(SIGINT, ctrlD);
if (!isatty(STDIN_FILENO))
is_pipe = 1;
if (is_pipe == 0)
puts("$ ");
flag = 0;
while (getline(&(vars.buffer), &len_buffer, stdin) != -1)
{
flag = 1;
vars.count++;
vars.commands = tokenize(vars.buffer, ";");
for (i = 0; vars.commands && vars.commands[i] != NULL; i++)
{
vars.av = tokenize(vars.commands[i], "\n \t\r");
if (vars.av && vars.av[0])
if (check_for_builtins(&vars) == NULL)
check_for_path(&vars);
free(vars.av);
}
free(vars.buffer);
free(vars.commands);
flag = 0;
if (is_pipe == 0)
puts("$ ");
vars.buffer = NULL;
	}
if (is_pipe == 0)
puts("\n");
free_env(vars.env);
free(vars.buffer);
exit(vars.status);
}
