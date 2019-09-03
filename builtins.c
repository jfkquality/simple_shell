#include "shell_functions.h"
#include "shell_strings.h"

/**
 * isbuilt - check if arg is a built-in and execute it
 * @args: args arry for builtin to check for
 * @envp: environment variable
 * @builtins: list of builtins
 * @builtslen: length of builtins array
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int isbuilt(char **args, char **envp)
{
	int i = 0;
	char *pgm = args[0];
	char *builts[] = {
		"exit", "env", "printenv", "setenv", "unsetenv",
		"pgetenv", "cd", "alias", "help", "history", NULL};
	ssize_t builtslen = sizeof(builts) / sizeof(builts[0]);
	(void) builtslen;

	while (builts[i])
	{
		if (_strcmp(pgm, builts[i]) == 0)
		{
			if (!builtcheck1(pgm, args, envp))
				return (EXIT_SUCCESS);
			if (!builtcheck2(pgm, args, envp))
				return (EXIT_SUCCESS);
		}
		i++;
	}
	return (EXIT_FAILURE);
}
/**
 * builtcheck1 - check if arg is a built-in and execute it
 * @pgm: pgm/cmd to find
 * @args: args arry for builtin to check for
 * @envp: environment variable
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int builtcheck1(char *pgm, char **args,  char **envp)
{
	if (!_strcmp(pgm, "env"))
	{
		_env(envp);
		return (EXIT_SUCCESS);
	}
	if (!_strcmp(pgm, "printenv"))
	{
		_env(envp);
		return (EXIT_SUCCESS);
	}
	if (!_strcmp(pgm, "getenv"))
	{
		_getenv(envp, args[1]);
		return (0);
	}
	if (!_strcmp(pgm, "pgetenv"))
	{
		_pgetenv(envp, args[1]);
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
/**
 * builtcheck2 - check if arg is a built-in and execute it
 * @pgm: pgm/cmd to find
 * @args: args arry for builtin to check for
 * @envp: environment variable
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
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
