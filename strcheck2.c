#include "shell.h"
/**
 * _strtok - This is used to
 * split a string by
 * some delimiter.
 * @str: input string.
 * @delim: delimiter.
 *
 * Return: string splited.
 */
char *_strtok(char str[], const char *delim)
{
static char *splitted, *str_end;
char *str_start;
unsigned int i, bool;

if (str != NULL)
{
if (cmp_chars(str, delim))
return (NULL);
splitted = str; /*Store first address*/
i = _strlen(str);
str_end = &str[i]; /*Store last address*/
}
str_start = splitted;
if (str_start == str_end) /*Reaching the end*/
return (NULL);

for (bool = 0; *splitted; splitted++)
{
/*Breaking loop finding the next token*/
if (splitted != str_start)
if (*splitted && *(splitted - 1) == '\0')
break;
/*Replacing delimiter for null char*/
for (i = 0; delim[i]; i++)
{
if (*splitted == delm[i])
{
*splitted = '\0';
if (splitted == str_start)
str_start++;
break;
}
}
if (bool == 0 && *splitted) /*Str != Delim*/
bool = 1;
}
if (bool == 0) /*Str == Delim*/
return (NULL);
return (str_start);
}

char *aux_itoa(int n)
{
unsigned int n1;
int lenght = get_len(n);
char *buffer;

buffer = malloc(sizeof(char) * (lenght + 1));
if (buffer == 0)
return (NULL);

*(buffer + lenght) = '\0';

if (n < 0)
{
n1 = n * -1;
buffer[0] = '-';
}
else
{
n1 = n;
}

lenght--;
do {
*(buffer + lenght) = (n1 % 10) + '0';
n1 = n1 / 10;
lenght--;
}
while (n1 > 0)
		;
return (buffer);
}

/**
 * get_len - This code is used
 * to get the lenght of a number.
 * @n: type int number.
 * Return: Lenght of a number.
 */

int get_len(int n)
{
unsigned int n1;
int lenght = 1;

if (n < 0)
{
lenght++;
n1 = n * -1;
}
else
{
n1 = n;
}
while (n1 > 9)
{
lenght++;
n1 = n1 / 10;
}

return (lenght);
}
