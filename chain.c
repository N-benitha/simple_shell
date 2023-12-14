#include "shell.h"

/**
 * is_chain - checks if it is a chain command
 * @info: the parameter struct
 * @buf: the char buffer
 * @p: address of current position in buf
 *
 * Return: 1 if chain delimeter, 0 otherwise
 */
int is_chain(data_shell *d, char *buf, size_t *p)
{
	size_t j = *p;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		d->cmd_buf_type = CMD_OR;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		j++;
		d->cmd_buf_type = CMD_AND;
	}
	else if (buf[j] == ';') /* found end of this command */
	{
		buf[j] = 0; /* replace semicolon with null */
		d->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = j;
	return (1);
}

/**
 * check_chain - checks we should continue chaining based on last status
 * @info: the parameter struct
 * @buf: the char buffer
 * @p: address of current position in buf
 * @i: starting position in buf
 * @len: length of buf
 *
 * Return: Void
 */
void check_chain(data_shell *d, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (d->cmd_buf_type == CMD_AND)
	{
		if (d->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (d->cmd_buf_type == CMD_OR)
	{
		if (!d->status)
		{
			buf[i] = 0;
			j = len;
		}
	}

	*p = j;
}
/**
 * replace_vars - replaces vars in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_vars(data_shell *d)
{
	int i = 0;
	list_t *node;

	for (i = 0; d->av[i]; i++)
	{
		if (d->av[i][0] != '$' || !d->av[i][1])
			continue;

		if (!str_cmp(d->av[i], "$?"))
		{
			replace_string(&(d->av[i]),
				_strdup(convert_number(d->status, 10, 0)));
			continue;
		}
		if (!str_cmp(d->av[i], "$$"))
		{
			replace_string(&(d->av[i]),
				_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(d->_environ, &d->av[i][1], '=');
		if (node)
		{
			replace_string(&(d->av[i]),
				_strdup(strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&d->av[i], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - replaces string
 * @old: address of old string
 * @new: new string
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_string(char **old_str, char *new_str)
{
	free(*old_str);
	*old_str = new_str;
	return (1);
}
