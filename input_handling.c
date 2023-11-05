#include "shell.h"

/**
 * new_line - Handles new line character input
 * @string: String to be handled
 * Return: Empty string
**/

char *new_line(char *string)
{
	free(string);
	return ("\0");
}

/**
 * white_space - Modifies the input string to remove preceeding white spaces
 * @str: Input to be modifies
 * Return: Returns the modified string
**/

char *white_space(char *str)
{
	int i, j = 0;
	char *buff;

	buff = malloc(sizeof(char) * (_strlen(str) + 1));
	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}
	for (i = 0; str[i] == ' '; i++)
		;
	for (; str[i + 1] != '\0'; i++)
	{
		buff[j] = str[i];
		j++;
	}
	buff[j] = '\0';
	if (buff[0] == '\0' || buff[0] == '#')
	{
		free(buff);
		return ("\0");
	}
	return (buff);
}

/**
 * hashtag - function that removes everything after '#'
 * @buff: input buffer
 * Return: nothing
**/

void hashtag(char *buff)
{
	int i;

	for (i = 0; buff[i] != '\0'; i++)
	{
		if (buff[i] == '#' && buff[i - 1] == ' ' && buff[i + 1] == ' ')
		{
			buff[i] = '\0';
		}
	}
}

/**
 * check_separate - checks if a character matches any
 *	character in a given string
 * @c: character to check
 * @str: string of delimiters
 * Return: 1 on success, 0 on failure
**/

unsigned int check_delim(char c, const char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (c == str[i])
			return (1);
	}
	return (0);
}
