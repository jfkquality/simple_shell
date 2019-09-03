#include "shell_functions.h"
#include "shell_strings.h"

/**
 * _env - print environment
 * @env: envp
 *
 * Return: success
 */
int _env(char **env)
{
	char **env1;

	env1 = env;
	while (*env1)
	{
		write(STDOUT_FILENO, *env1, _strlen(*env1));
		write(STDOUT_FILENO, "\n", 1);
		env1++;
	}
	return (EXIT_SUCCESS);
}

/**
 * _getenv - get requested variable from environ/envp
 * @env: environment (envp)
 * @evar: env variable to get
 *
 * Return: char ptr to env var
 */
char *_getenv(char **env, char *evar)
{
	int i = 0;

	if (!evar)
	{
		return (0);
	}

	if (!_strchr(evar, '='))
		_strcat(evar, "=");

	while (env[i])
	{
		if (_strncmp(evar, env[i], _strlen(evar)) == 0)
		{
			return (env[i] + _strlen(evar));
		}
		i++;
	}
	return (0);
}
/**
 * _pgetenv - get requested variable from environ/envp
 * @env: environment (envp)
 * @evar: env variable to get
 *
 * Return: char ptr to env var
 */
int _pgetenv(char **env, char *evar)
{
	int evarlen = 0;

	if (!evar)
	{
		write(STDOUT_FILENO, "Usage ", 6);
		write(STDOUT_FILENO, "pgetenv", 7);
		write(STDOUT_FILENO, " <VAR-NAME>\n", 12);
		return (0);
	}
	evarlen = _strlen(_getenv(env, evar));
	write(STDOUT_FILENO, _getenv(env, evar), evarlen);
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
/**
 * _printenv - prints the environment
 * @env: environment variable
 *
 * Return: Always 0.
 */
void _printenv(char **env)
{
	_env(env);
}
