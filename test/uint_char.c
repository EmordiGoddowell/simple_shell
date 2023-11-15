#include "shell.h"

/**
 * uint_char - convert an unsigned integer to character
 * @n: integer to convert
 * Return: character pointer
**/

char *uint_char(unsigned int n)
{
	int len = 0, i = 0;
	char *s;

	len = int_count(n);
	s = malloc(len + 2);

	if (!s)
	{
		free(s);
		return (NULL);
	}
	*s = '\0';

	while (n / 10)
	{
		s[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}

	s[i] = (n % 10) + '0';
	flip_array(s, len);
	s[i + 1] = '\0';

	return (s);
}
