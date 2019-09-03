#include "shell_strings.h"
#include "shell_functions.h"

/**
 * main - primary function to run shell from
 * @ac: arguement count
 * @av: arguement vector
 * @env: environment
 *
 * Return: nothing
 */
int main(int ac, char **av, char **env)
{
	FILE *fp;
	unsigned int i = 0;
	size_t len = 0;
	ssize_t read = 0;
	char **input_args = NULL, **args = av;
	char *line = NULL;
	(void) ac;

	/* fp = STDIN_FILENO; */
	fp = stdin;
	if (args[1])
	{
		_readfile(args[1], env);
		return (0);
	}
	while (1)
	{
		type_prompt();
		signal(SIGINT, sigintHandler);
		read = getline(&line, &len, fp);
		check_input(read, line);
		input_args = make_arr(read, line);
		if (!input_args)
			continue;
		if (!isbuilt(input_args, env))
			continue;
		input_args[0] = _getpath(input_args, env);
		_execute(line, input_args, env);
	}
	free(line);
	for (i = 0; i < sizeof(input_args); i++)
		free(input_args[i]);
	free(input_args);
	exit(EXIT_SUCCESS);
}
