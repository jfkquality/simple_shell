#ifndef _SHELL_FUNCS
#define _SHELL_FUNCS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

/* ssize_t _getline(char **lineptr, size_t *n, FILE *stream); */
ssize_t _getline(char *buff);
int getlen(char *s);
void type_prompt(void);
void sigintHandler(int signum);
void _execute(char *line, char **args, char **envp);
void _env(char **env);
void _printenv(char **env);
char **make_arr(ssize_t read, char *line);
void check_input(ssize_t read, char *line);
char *_getenv(char **env, char *evar);
char *_path(char **env);
/* char *isbuiltin(char *arg, char **builtins); */
char *isbuiltin(char **args, char **builtins, ssize_t builtslen);
void builtin(char *pgm);
void _readfile(char *file);
char **parsepath(char **env);

extern int errno;

#endif
