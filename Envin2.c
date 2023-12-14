#include "shell.h"
/**
 * _copyinfo - copies info to create a new env or alias
 * @name: name (env or alias)
 * @value: value (env or alias)
 *
 * Return: new env or alias.
 */

char *_copyinfo(char *name, char *value)
{
char *new;
int len_name, len_value, len;

len_name = _strlen(name);
len_value = _strlen(value);
len = len_name + len_value + 2;
new = malloc(sizeof(char) * (len));
strcpy(new, name);
_strcat(new, "=");
_strcat(new, value);
_strcat(new, "\0");

return (new);
}

/**
 * _setsenv - This is used to set an environment variable
 * @name: name of the environment variable
 * @value: value of the environment variable
 * @dat: data structure (envi)
 * Return: no return
 */

void _setsenv(char *name, char *value, data_shell *dat)
{
int i;
char *var_env, *name_env;

for (i = 0; dat->_environ[i]; i++)
{
var_env = _strdup(dat->_environ[i]);
name_env = _strtok(var_env, "=");
if (str_cmp(name_env, name) == 0)
{
free(dat->_environ[i]);
dat->_environ[i] = _copyinfo(name_env, value);
free(var_env);
return;
}
free(var_env);
}

dat->_environ = _reallocdp(dat->_environ, i, sizeof(char *) * (i + 2));
dat->_environ[i] = _copyinfo(name, value);
dat->_environ[i + 1] = NULL;
}

/**
 * set_env - This is used to compare env variables names
 * @dat: env name and env value)
 *
 * Return: 1 on success.
 */
int set_env(data_shell *dat)
{

if (dat->args[1] == NULL || dat->args[2] == NULL)
{
get_error(dat, -1);
return (1);
}

_setsenv(dat->args[1], dat->args[2], dat);

return (1);
}

/**
 * _delsetenv - This is used to
 * delete an environment variable
 *
 * @dat: data (env name)
 *
 * Return: 1 on success.
 */
int _delsetenv(data_shell *dat)
{
char **realloc_environ;
char *var_env, *name_env;
int i, j, k;

if (dat->args[1] == NULL)
{
get_error(dat, -1);
return (1);
}
k = -1;
for (i = 0; dat->_environ[i]; i++)
{
var_env = _strdup(dat->_environ[i]);
name_env = _strtok(var_env, "=");
if (str_cmp(name_env, dat->args[1]) == 0)
{
k = i;
}
free(var_env);
}
if (k == -1)
{
get_error(dat, -1);
return (1);
}
realloc_environ = malloc(sizeof(char *) * (i));
for (i = j = 0; dat->_environ[i]; i++)
{
if (i != k)
{
realloc_environ[j] = dat->_environ[i];
j++;
}
}
realloc_environ[j] = NULL;
free(dat->_environ[k]);
free(dat->_environ);
dat->_environ = realloc_environ;
return (1);
}
