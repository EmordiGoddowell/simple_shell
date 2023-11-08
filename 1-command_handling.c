#include "shell.h"

/**
 * print_prompt - Outputs a '$'
 *	symbol to standard output as a command prompt
**/

void print_prompt(void)
{
	OUTPUT("$ ");
}

/**
 * record_command - Stores user input in a
 *	file for command history
 * @input: User input to be stored
 * Return: 0 on success, -1 on failure
**/

int record_command(char *input)
{
	char *filename = ".simple_shell_history";
	ssize_t fd, w;
	int len = 0;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (fd < 0)
		return (-1);
	if (input)
	{
		while (input[len])
			len++;
		w = write(fd, input, len);
		if (w < 0)
			return (-1);
	}
	return (1);
}

/**
 * split_command - Separates a user input string into commands by semicolons
 * @input: User input string to be parsed
 * Return: Array of parsed commands
*/

char **split_command(char *input)
{
	char **commands;
	char *command;
	int i;
	int buffsize = BUFSIZE;

	if (input[0] == ' ' && input[_strlen(input)] == ' ')
		exit(0);
	if (input == NULL)
		return (NULL);

	commands = malloc(sizeof(char *) * buffsize);
	if (!commands)
	{
		free(commands);
		perror("hsh");
		return (NULL);
	}

	command = _strtok(input, ";&");
	for (i = 0; command; i++)
	{
		commands[i] = command;
		command = _strtok(NULL, ";&");
	}
	commands[i] = NULL;

	return (commands);
}
