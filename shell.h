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

void prompt(void);
int _getline(args *a);
void fork_exec(char **arr);
char **parser(args *a);
int sh_exit(args *a);
int sh_help(args *a);
int sh_cd(args *a);
int _getenv(args *a);

#endif
