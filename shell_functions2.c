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
 * isbuilt - check if arg is a built-in and execute it
 * @args: args arry for builtin to check for
 * @builtins: list of builtins
 * @builtslen: length of builtins array
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int isbuilt(char **args, char **envp, char **builtins, ssize_t builtslen)
{
	int i = 0;
	char *pgm = args[0];
	(void) builtslen;

	while (builtins[i])
	{
		if (_strcmp(pgm, builtins[i]) == 0)
		{
			/* printf("\nbuilt match %s\n\n", args[0]); */
			if (!builtcheck1(pgm, args, envp))
				return (EXIT_SUCCESS);
			if (!builtcheck2(pgm, args, envp))
				return (EXIT_SUCCESS);
		}
		i++;
	}
	return(EXIT_FAILURE);
}

int builtcheck1(char *pgm, char **args,  char **envp)
{
	if (!_strcmp(pgm, "env") || !_strcmp(pgm, "printenv"))
	{	_env(envp);
		return (EXIT_SUCCESS);
	}
	if (!_strcmp(pgm, "getenv"))
	{
		_getenv(envp, args[1]);
		return (0);
	}
	if (!_strcmp(pgm, "setenv"))
	{
		/* _setenv(); */
		return (EXIT_SUCCESS);
	}
	if (!_strcmp(pgm, "unsetenv"))
	{
		/* _unsetenv(); */
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
int builtcheck2(char *pgm, char **args, char **envp)
{
	(void) args;
	(void) envp;

	if (!_strcmp(pgm, "cd"))
	{
		/* _cd(); */
		return (EXIT_SUCCESS);
	}
	if (!_strcmp(pgm, "alias"))
	{
		/* _alias(); */
		return (EXIT_SUCCESS);
	}
	if (!_strcmp(pgm, "help"))
	{
		/* _help(); */
		return (EXIT_SUCCESS);
	}
	if (!_strcmp(pgm, "history"))
	{
		/* _history(); */
		return (EXIT_SUCCESS);
	}
	/* strcat args array to create command with args? */

	return (EXIT_FAILURE);
}
/**
 * _readfile() - read a text file containing command and execute them.
 * @file: file to read
 *
 * Return: success or failure
 */
void _readfile(char *file)
{
	(void) file;
	/* See lat project on file i/o */
	/* Open file. Execute each command as is */
	/* (void*) file; */
	printf("_readfile()\n");
	exit(EXIT_SUCCESS);
}
