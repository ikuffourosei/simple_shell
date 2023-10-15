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

/* PRINT NUMBER */
void print_n(int number);

/* PRINT ERROR */
int printerror(char *str);
int puterror(char c);

/* STRINGS FUNCTIONS */
int strlength(char *str);
char *str_concat(char *str1, char *str2);
int _check(char *str, char c);
char *_strtok(char *str, char *delim);
char *_strtok2(char *str, char *delim);
int _strncmp(char *s1, char *s2, size_t n);
int _atoi(char *str);
char **parsing(char *line);

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

/*ARGS FUNCTIONS*/
void _readargv(char *argv[], char *_env[]);
void _read(char *argv[], char *_env[]);
int cui(char **input, int loop, char *iu, char **arg, char ***env_copy, int *j, char *result);
void shfunc(char *line, int loop, char *argv[], char ***env_copy, int *j, char *result);

/* BUFFER */
#define BUFSIZE 2048
void buf_clean(char *c);
void buf_fil(char *c, char *a);

/* WORKING DIRECTORY */
void old_dir(char *buffer, char **myenv);
void _dir(char *buffer, char **myenv);

/* PATH */
char **checkbin(char **buffer, char **env_copy);
char *verify_path(char *path, char *pwd);
char *get_path(char **env_copy);

/* HANDLE COMMENTS AND SEMICOLON */
char *_comments(char *line);
int semicolon(char *line, int loop, char **argv);

/* SHELL BUILTIN COMMANDS CHECKS */
int _isenv(char **input, char **env_copy);
int _iscd(char **input, int loop, char *arg[], char **env_copy);
int _isexit(char **input, int loop, char *line, char **arg, char **env_copy, char *result);
int _ishelp(char **input, int loop, char *arg[], char **env_copy);

/* SHELL BUILTIN COMMANDS */
void _cd(char **input, int loop, char *arg[], char **myenv);
void _type(char **input, int loop, char *line, int i, char **arg, char **envcopy, int e, char *result);
void _help_(char **input, int loop, char *arg[], char **envcopy);
void _help(char **input, int loop, char *arg[], char **envcopy);

/* SHELL BUILTIN FUNCTIONS */
char *_gethome(char **envcopy);
char **create_env(char *en_v[]);
void _env(char **myenv);
void foork(char **arg, char *input, int ptc, int loop, char **v, int e, char **envcopy, char *result);

/* GETLINE */
char  *_getline(int *loop, char **envcopy, int e);
char  *_getlineav(int *loop, char **envcopy, int e, char **arg);


/* ERROR MESSAGES */  
void _errorcd(char **input);
void _errorexit(char **input);
void _errorhelp(char **input);
void _errornotfound(char **input);
void _put_err(char **input, int loop, int signal, char *arg[]);
void _builtinerr(char **input);
void _builtinerr2(char **input);

/* SIGNAL */
void _signal(int sig);

#endif
