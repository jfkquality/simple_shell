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
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char **input_args = NULL, **args = av;
	char *builtins[] = {
	"exit", "env", "setenv", "unsetenv",
	"cd", "alias", "help", "history", NULL};
	ssize_t builtinslen = 0;
	/* ssize_t inputslen; */
	/* char *builtin = NULL; */
	(void) ac;

	/* fp = STDIN_FILENO; */
	fp = stdin;
	if (args[1])
		_readfile(args[1]);
	builtinslen = sizeof(builtins) / sizeof(builtins[0]);
	while (1)
	{
		type_prompt();
		signal(SIGINT, sigintHandler);
		read = getline(&line, &len, fp);
		if (read == 1)
			continue;
		check_input(read, line);
		input_args = make_arr(read, line);
		if (!input_args)
		{
			continue;
		}
		isbuiltin(input_args, builtins, builtinslen);
		_execute(line, input_args, env);
	}
	free(line);
	for (i = 0; i < sizeof(input_args); i++)
		free(input_args[i]);
	free(input_args);
	exit(EXIT_SUCCESS);
}
