#include "shell.h"

/**
 * print_unsigned_int - Outputs an unsigned integer using
 *		putchar function
 * @n: Unsigned integer to be output
**/

void print_unsigned_int(unsigned int n)
{
	unsigned int x = n;

	if ((x / 10) > 0)
		print_unsigned_int(x / 10);

	putchar(x % 10 + '0');
}

/**
 * print_int - Outputs an integer using _putchar function
 * @n: Integer to be output
**/

void print_int(int n)
{
	unsigned int x = n;

	if (n < 0)
	{
		putchar('-');
		x = -x;
	}

	if ((x / 10) > 0)
		print_unsigned_int(x / 10);

	putchar(x % 10 + '0');
}

/**
 * execute_echo - Runs the built-in echo function
 * @cmd: Parsed Command
 * Return: 0 Upon Success -1 Upon Failure
**/

int execute_echo(char **cmd)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		if (execve("/bin/echo", cmd, environ) == -1)
		{
			return (-1);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		return (-1);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
