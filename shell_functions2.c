#include "shell_functions.h"
#include "shell_strings.h"

/**
 * _path - reads and parses the PATH environment variable into an array
 * @env: environment variable
 *
 * Return: a path string
 */

char *_path(char **env)
{
	(void) env;
	return (EXIT_SUCCESS);
}

/**
 * isbuiltin - check if arg is a built-in
 * @args: args arry for builtin to check for
 * @builtins: list of builtins
 * @builtslen: length of builtins array
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
char *isbuiltin(char **args, char **builtins, ssize_t builtslen)
{
	int i;
	(void) builtslen;

	while (builtins[i])
	{
		if (_strcmp(args[0], builtins[i]) == 0)
		{
			return (builtins[i]);
		}
		i++;
		/* strcat args array to create command with args */
	}
	return (0);
}
/**
 * builtin - execute the built in function
 * @pgm: pgrm to execute
 *
 * Return: nothing
 */
void builtin(char *pgm)
{
	(void) pgm;
	printf("builtin()\n");
}
/**
 * _readfile - read a text file containing command and execute them.
 * @file: file to read
 *
 * Return: success or failure
 */
void _readfile(char *file)
{
	/* See lat project on file i/o */
	/* Open file. Execute each command as is */
	(void) file;
	printf("_readfile()\n");
}
