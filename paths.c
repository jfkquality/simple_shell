#include "shell_functions.h"
#include "shell_strings.h"

/**
 * _getpath - get correct path for executable
 * @args: command line input args
 * @env: environment variable
 *
 * Return: a path string
 */
char *_getpath(char **args, char **env)
{
	char **paths;

	paths = _paths(env);
	args[0] = _which(args[0], paths);
	if (!args[0])
		return (0);
	return (args[0]);
}

/**
 * _paths -counts # of paths in the PATH environment variable
 * @env: environment variable
 *
 * Return: a path string
 */
char **_paths(char **env)
{
	int paths = 0;
	char *prefix = "PATH=", *path = NULL;
	char *nextcolon = NULL,  **patharr;

	path = _getenv(env, prefix);
	nextcolon = path;

	/* loop to find # of paths */
	while (nextcolon)
	{
		paths++;
		nextcolon++;
		nextcolon = _strchr(nextcolon, ':');  /* + 1; */
	}

	/* # of paths found; loop again and create path array */
	patharr = malloc(paths * sizeof(char *));
	patharr = parsepaths(path, patharr);
	return (patharr);
}
/**
 * parsepaths - parse paths in the PATH environment variable into array
 * @path: PATHenvironment variable
 * @patharr: path array malloc'd prior to call
 *
 * Return: a path string
 */
char **parsepaths(char *path, char **patharr)
{
	int i = 0, j = 0, pathlen = 0, colons = 0;
	char *nextcolon = NULL, *lastpath = NULL;

	/* nextpath = path; */
	lastpath = path;
	nextcolon = path;
	i = 0;
	while (nextcolon != NULL)
	{
		nextcolon = _strchr(lastpath, ':');
		if (!nextcolon)
			continue;
		pathlen = nextcolon - lastpath;
		patharr[i] = malloc((pathlen + 1) * sizeof(char));
		j = 0;
		while (lastpath < nextcolon)
		{
			patharr[i][j] = *lastpath;
			lastpath++;
			j++;
		}
		patharr[i][j] = '\0';
		lastpath++;
		colons++;
		i++;
	}
	if (!nextcolon) /* last path (end of path has no colon) */
	{
		pathlen = _strlen(lastpath);
		patharr[i] = malloc((pathlen + 1) * sizeof(char));
		patharr[i] = lastpath;
		patharr[i + 1] = NULL;
	}
	return (patharr);
}

/**
 * _which - find path or executable
 * @pgm: pgm/com to find
 * @paths: paths array
 *
 * Return: full path.
 */
char *_which(char *pgm, char **paths)
{
	unsigned int i;
	struct stat st;
	char *fullpath;

	if (_strchr(pgm, '/') == pgm)
		return (pgm);
	i = 0;
	while (paths[i])
	{
		fullpath = _strcat(paths[i], "/");
		fullpath = _strcat(fullpath, pgm);
		if (stat(fullpath, &st) == 0)
			return (fullpath);
		i++;
	}
	return (0);
}
