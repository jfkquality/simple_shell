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
int _env(char **env);
void _printenv(char **env);
char **make_arr(ssize_t read, char *line);
void check_input(ssize_t read, char *line);
int _getenv(char **env, char *evar);
char *_path(char **env);
/* char *isbuiltin(char *arg, char **builtins); */
int isbuilt(char **args, char **env, char **builtins, ssize_t builtslen);
/* void builtin(char *pgm); */
int builtcheck1(char *pgm, char **args, char **env);
int builtcheck2(char *pgm, char **args, char **env);
int built(char *pgm, char **env, char **args);
void _readfile(char *file);
char **parsepath(char **env);

extern int errno;

#endif
