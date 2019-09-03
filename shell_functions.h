#ifndef _SHELL_FUNCS
#define _SHELL_FUNCS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "shell_functions.h"
#include "shell_strings.h"

/* ssize_t _getline(char **lineptr, size_t *n, FILE *stream); */
ssize_t _getline(char *buff);
int getlen(char *s);
void type_prompt(void);
void sigintHandler(int signum);
void _execute(char *line, char **args, char **envp);
int _env(char **env);
void _printenv(char **env);
char **make_arr(ssize_t read, char *line);
void check_input(ssize_t read, char *line);
char * _getenv(char **env, char *evar);
int _pgetenv(char **env, char *evar);
/* char *isbuiltin(char *arg, char **builtins); */
int isbuilt(char **args, char **env);
/* void builtin(char *pgm); */
int builtcheck1(char *pgm, char **args, char **env);
int builtcheck2(char *pgm, char **args, char **env);
int built(char *pgm, char **env, char **args);
/* void _readfile(char *file); */
ssize_t _readfile(const char *filename, char **);
char *_getpath(char **arg, char **env);
char **_paths(char **env);
char **parsepaths(char *, char **);
char *_which(char *pgm, char **paths);

extern int errno;

#endif
