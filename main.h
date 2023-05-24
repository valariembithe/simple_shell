#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#define BUFSIZE 1024
#define TOKEN_DELIM " \t\r\n\a"
/**
 * struct data - struct that contains all relevant data on runtime
 * @av: argument vector
 * @input: command line written by the user
 * @args: tokens of the command line
 * @status: last status of the shell
 * @counter: lines counter
 * @_environ: environment variable
 * @pid: process ID of the shell
 */
typedef struct data
{
	char **args;
	char *input;
	char **av;
	int counter;
	int status;
	char **_environ;
	char *pid;
} datash;

/* Points to an array of pointers to strings called the "environment" */
extern char **environ;

/**
 * struct builtin_s - struct for command args.
 * @name: The name of command builtin i.e cd, exit
 * @f: type pointer function.
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(datash *datashell);
}builtin_t;

/* exec.c functions */
void execommand(char **argv);
/* 1_string.c string functions */
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, const char *src);
int _strcmp(char *s1, char *s2);
int _strspn(char *s, char *accept);
int _isdigit(const char *s);

void prompt(void);
/* 2_string.c string functions */
int cmp_chars(char str[], const char *delim);
int _strlen(const char *s);
char *_strtok(char str[], const char *delim);


/* memory.c memory functions */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void _memcpy(void *newptr, const void *ptr, unsigned int size);
<<<<<<< HEAD
typedef struct data
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;
} data_shell;
=======

/* get_location.c */
char *get_location(char *command);

/* builin.c */
int (*get_builtin(char *cmd))(datash *);

/* get_line.c functions */
void assign_line(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);

/* exit_shell.c function */
int exit_shell(datash *datashell);

/* errors1.c functions */
char *error_get_alias(char **args);
char *error_env(datash *datashell);
char *error_syntax(char **args);
char *error_permission(char **args);
char *error_path_126(datash *datashell);

/* errors2.c functions */
char *strcat_cd(datash *, char *, char *, char *);
char *error_get_cd(datash *datashell);
char *error_not_found(datash *datashell);
char *error_exit_shell(datash *datashell);

/* get_error.c function */
int get_error(datash *datashell, int eval);

/* stdlib.c functions */
int _atoi(char *s);
int get_len(int n);
char *_itoa(int n);
>>>>>>> 53e64207a2efd1e14dcc4e6ac9d13261890b4901
#endif
