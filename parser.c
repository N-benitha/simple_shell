#include "shell.h"
/**
 * parser - divides up the line inputed into arguments
 * @a: pointer to structure args
 *
 * Return: address of pointer to character
 */
char **parser(data_shell *a)
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

	token = strtok(a->input, " \t\n");
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
void fork_exec(char **arr, data_shell *a)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Unsuccesful\n");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(arr[0], arr, NULL) == -1)
		{
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		waitpid(child_pid, &(a->status), 0);
		if (WIFEXITED(a->status))
		{
			a->status = WEXITSTATUS(a->status);
			if (a->status == 126)
				get_error(a, 126);
		}
	}

}
