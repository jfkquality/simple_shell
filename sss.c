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
	ssize_t read = 0, builtslen = 0;
	char **input_args = NULL, **args = av;
	char *line = NULL;
	char *builts[] = {
		"exit", "env", "printenv", "setenv", "unsetenv",
		"pgetenv", "cd", "alias", "help", "history", NULL};
	(void) ac;

	/* fp = STDIN_FILENO; */
	fp = stdin;
	if (args[1])
	{
		_readfile(args[1]);
		return (0);
	}
	builtslen = sizeof(builts) / sizeof(builts[0]);
	while (1)
	{
		type_prompt();
		signal(SIGINT, sigintHandler);
		read = getline(&line, &len, fp);
		check_input(read, line);
		input_args = make_arr(read, line);
		if (!input_args)
			continue;
		if (!isbuilt(input_args, env, builts, builtslen))
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
