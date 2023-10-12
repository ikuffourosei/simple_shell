#ifndef SIMPLESHELL_H
#define SIMPLESHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define SIZE 1024

/* PRINT CHARACTER OR STRING TO STDOUT */
int _putchar(char c);
int _print(char *str);

/* PRINT ERROR */
int printerror(char *str);
int puterror(char c);

/* STRINGS FUNCTIONS */
int strlength(char *str);
char *str_concat(char *str1, char *str2);
int _check(char *str, char c);
char *_strtok(char *str, char *delim);
char *_strtok2(char *str, char *delim);
int _strncmp(const char *s1, const char *s2, size_t n);
int _atoi(char *str);

/* MEMORY HANDLING */
char *_memcpy(char *dest, char *src, unsigned int n);
void *_calloc(unsigned int nmemb, unsigned int size);
void free_grid(int **grid, int height);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_realloc_(char *str, char *ptr, unsigned int old_size, unsigned int new_size);

/* SETENV */
int _issetenv(char *command);
int tokenize(char *command, char *tokens[], int max_tokens);
int _setenv(char *name, char *value, int overwrite);

/* UNSETENV */
int _unsetenv(char *name);

/*ARGS*/
void _noargv(char *argv[], char *_env[]);
void _readargv(char *argv[], char *_env[]);


/* errors 
 * 
void _printerr(char **p, int loop, int sig, char *v[]);
void _builtinerr(char **p);
void _builtinerr2(char **p);
void _errorcd(char **p);
void _errorexit(char **p);
void _errorhelp(char **p);
void _errorgarbage(char **p);
void print_n(int number); */

#endif
