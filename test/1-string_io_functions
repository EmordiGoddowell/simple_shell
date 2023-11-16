#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
**/

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - function that prints a string
 * @str: pointer to string
 * Return: void
**/

void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}

/**
* _atoi - converts a string to an integer
* @s: string to be converte
* Return: the int converted from the string
*/

int _atoi(char *s)
{
	int i, d, n, len, f, digit;

	i = 0;
	d = 0;
	n = 0;
	len = 0;
	f = 0;
	digit = 0;

	while (s[len] != '\0')

		len++;

	while (i < len && f == 0)
	{

		if (s[i] == '-')
			++d;
		if (s[i] >= '0' && s[i] <= '9')
		{

			digit = s[i] - '0';
			if (d % 2)
				digit = -digit;
			n = n * 10 + digit;
			f = 1;

			if (s[i + 1] < '0' || s[i + 1] > '9')

				break;
			f = 0;
		}
		i++;
	}
	if (f == 0)
		return (0);
	return (n);
}

/**
 * _strchr - locates a character in a string
 * @s: string to be checked
 * @c: character to be located
 * Return: pointer to character
**/

char *_strchr(char *s, char c)
{
	int i = 0;

	for (; s[i] >= '\0'; i++)
	{
		if (s[i] == c)
			return (&s[i]);
	}
	return (0);
}

/**
 * _strdup - Duplicates a string in a new memory space.
 * @str: The input string to be duplicated.
 *
 * Return: Pointer to the duplicated string, or NULL on failure.
**/

char *_strdup(char *str)
{
	char *dup;
	unsigned int i, length;

	if (str == NULL)
		return (NULL);

	length = strlen(str) + 1;
	dup = malloc(sizeof(char) * length);

	if (dup == NULL)
		return (NULL);

	for (i = 0; i < length; i++)
		dup[i] = str[i];

	return (dup);
}
