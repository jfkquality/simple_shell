#include "shell_functions.h"
#include "shell_strings.h"

/**
 * _env - print environment
 * @env: envp
 *
 * Return: nothing
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
	/* exit(EXIT_SUCCESS); */
}

/**
 * _getenv - get requested variable from environ/envp
 * @env: environment (envp)
 * @evar: env variable to get
 *
 * Return: char ptr to env var
 */
int _getenv(char **env, char *evar)
{
	int i = 0;

        if (!evar)
        {
                write (STDOUT_FILENO, "Usage ", 6);
                write (STDOUT_FILENO, "getenv", 6);
                write (STDOUT_FILENO, " <var-name>\n", 12);
                return (EXIT_SUCCESS);
        }

	if (!_strchr(evar, '='))
		_strcat(evar, "=");

	while (env[i])
	{
		if (_strncmp(evar, env[i], _strlen(evar)) == 0)
		{
			write(STDOUT_FILENO, env[i], _strlen(env[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
		i++;
	}
	return (EXIT_SUCCESS);
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

/**
 * getlen - get length of string.
 * @s: string pointer
 * Return: length
 */
int getlen(char *s)
{
	int l = 0;
	char *s11 = s;

	for (; *s11; s11++, l++)
		;
	return (l);
}

/* read_file function */

/**
 * type_prompt - type ($) prompt
 *
 * Return: nothing
 */
void type_prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}
