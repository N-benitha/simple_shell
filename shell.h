#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <dirent.h>
#include <errno.h>

extern char **environ;

typedef struct arguments
{
	char *line;
	char **tokens;
	size_t len;
}args;

#define ARGS_INIT \
{NULL, 0}

typedef struct builtin_cmds
{
	char *str;
	int (*builtin_fun)(args *);
}blt_in;

typedef struct data
{
	char **av;
	char *input;
	char **args;
	int status;
	char **_environ;
	
} data_shell;

void prompt(void);
int _getline(args *a);
void fork_exec(char **arr);
char **parser(args *a);
int sh_exit(args *a);
int sh_help(args *a);
int sh_cd(args *a);
int _getenv(args *a);
int exit_shell(data_shell *dat);
char *_strtok(char str[], const char *delm);
int get_error(data_shell *dat, int eval);
char *_strcat(char *dest, const char *src);
char *_strdup(const char *s);
char *strcpy(char *dest, char *src);
int str_cmp(char *s1, char *s2);
int isdigit(const char *s);
int strlen(const char *s);
int strtoi(char *s);
void mem_copy(void *newptr, const void *ptr, unsigned int size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int env_comp(const char *invro, const char *name);
char *_env_get(const char *name, char **_envi);
int _env(data_shell *dat);
char *_copyinfo(char *name, char *value);
void _setsenv(char *name, char *value, data_shell *dat);
int set_env(data_shell *dat);
int _delsetenv(data_shell *dat);

#endif
