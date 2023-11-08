#include "shell.h"

/**
 * parse_command - Separates command recieved from stdin by ;
 * @input: String gathered from stdin
 * Return: Parsed strings to be used as commands
**/

char **parse_command(char *input)
{
	char **commands;
	char *command;
	int i;
	int buffsize = BUFFER_SIZE;

	if (input[0] == ' ' && input[strlen(input)] == ' ')
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
