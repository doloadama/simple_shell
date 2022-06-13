#include "shell.h"
#include <string.h>
#include <stdio.h>

/* global variable for ^C handling */
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
