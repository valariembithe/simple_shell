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
/* exec.c functions */
void execommand(char **argv);
/* 1_string.c string functions */
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, const char *src);
char *_strchr(char *s, char c);
int _strcmp(char *s1, char *s2);
int _strspn(char *s, char *accept);

/* _strtok.c string functions */
void *_strtok(char str[], const char *delim);

/* 2_string.c string functions */
int cmp_chars(char str[], const char *delim);
int _strlen(const char *s);
char *_strdup(const char *s);

/* memory.c memory functions */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void _memcpy(void *newptr, const void *ptr, unsigned int size);
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
#endif
