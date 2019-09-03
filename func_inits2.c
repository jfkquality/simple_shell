#include "shell_functions.h"
#include "shell_strings.h"

/**
 * type_prompt - type ($) prompt
 *
 * Return: nothing
 */
void type_prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}

/**
 * _readfile - read a text file containing command and execute them.
 * @filename: file to read
 *
 * Return: success or failure
 */
ssize_t _readfile(const char *filename, char **env)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char **file_args = NULL;

	if (!filename)
		return (0);

	/* fp = fopen("/etc/motd", "r"); */
	fp = fopen(filename, "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);

	while ((read = getline(&line, &len, fp)) != -1)
	{
		file_args = make_arr(read, line);
		if (!file_args)
			continue;
		if (!isbuilt(file_args, env))
                        continue;
                file_args[0] = _getpath(file_args, env);
                _execute(line, file_args, env);
	}
	free(line);
	return (EXIT_SUCCESS);
}
