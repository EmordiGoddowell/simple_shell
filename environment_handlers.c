#include "shell.h"

/**
 * print_env - displays the environment variables
 * @cmd: parsed command
 * @st: status of last command executed
 * Return: Always 0
**/

int print_env(__attribute__((unused))
		char **cmd, __attribute__((unused)) int st)
{
	size_t i;
	int len;

	for (i = 0; environ[i] != NULL; i++)
	{
		len = _strlen(environ[i]);
		write(1, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}

/**
 * process_echo - handles different cases for the echo command
 * @st: statue of last command executed
 * @cmd: parsed command
 * Return: Always 1 Or execute normal echo
**/

int process_echo(char **cmd, int st)
{
	char *path;
	unsigned int pid = getppid();

	if (_strncmp(cmd[1], "$?", 2) == 0)
	{
		print_number_int(st);
		OUTPUT("\n");
	}
	else if (_strncmp(cmd[1], "$$", 2) == 0)
	{
		print_number(pid);
		OUTPUT("\n");
	}
	else if (_strncmp(cmd[1], "$PATH", 5) == 0)
	{
		path = _getenv("PATH");
		OUTPUT(path);
		OUTPUT("\n");
		free(path);
	}
	else
		return (print_echo(cmd));

	return (1);
}

/**
 * print_history - displays the command history of the
 *		user's input in the simple_shell
 * @c: parsed command
 * @st: status of last command executed
 * Return: 0 success or -1 if fail
**/

int print_history(__attribute__((unused))
		char **c, __attribute__((unused))int st)
{
	char *filename = ".simple_shell_history";
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int counter = 0;
	char *er;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		return (-1);
	}
	while ((get_line(&line, &len, fp)) != -1)
	{
		counter++;
		er = _itoa(counter);
		PRINT(er);
		free(er);
		PRINT(" ");
		PRINT(line);
	}
	if (line)
		free(line);
	fclose(fp);
	return (0);
}

/**
 * init_environment - Initializes an array to store environment variables
 * @env_vars: Array to store environment variables
 *
 * This function populates an array with environment variables.
**/

void init_environment(char **env_vars)
{
	int i;

	for (i = 0; environ[i]; i++)
		env_vars[i] = _strdup(environ[i]);
	env_vars[i] = NULL;
}

/**
 * free_environment - Frees memory allocated for environment variables array
 * @env_vars: Array of environment variables to be freed
 *
 * This function releases the memory used to store environment variables.
**/

void free_environment(char **env_vars)
{
	int i;

	for (i = 0; env_vars[i]; i++)
	{
		free(env_vars[i]);
	}
}
