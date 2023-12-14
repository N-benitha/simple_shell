#include "shell.h"
/**
 * parser - divides up the line inputed into arguments
 * @a: pointer to structure args
 *
 * Return: address of pointer to character
 */
char **parser(args *a)
{
	char *token;
	char **arr;
	int i = 0;

	arr = malloc(sizeof(char *) * 1024);
	if (!arr)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	token = strtok(a->line, " \t\n");
	while (token)
	{
		arr[i] = strdup(token);
		token = strtok(NULL, " \t\n");
		i++;
	}
	arr[i] = NULL;
	a->tokens = arr;

	return (arr);
}
/**
 * fork_exec - executes a program referred to by the pathname
 * @arr: address of pointer to char
 *
 * Return: nothing
 */
void fork_exec(char **arr)
{
	pid_t child_pid;
	int status = 0;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Unsuccesful\n");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(arr[0], arr, NULL) == -1)
			perror("Error");
	}
	else
	{
		wait(&status);
	}

}
