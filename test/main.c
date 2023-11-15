#include "shell.h"

/**
 * main - Entry point to program
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: Returns stat
**/

int main(__attribute__((unused)) int argc, char **argv)
{
	char *input, **cmd, **commands;
	int count = 0, i, condition = 1, stat = 0;

	if (argv[1] != NULL)
		process_file(argv[1], argv);
	signal(SIGINT, ignore_sigint);
	while (condition)
	{
		count++;
		if (isatty(STDIN_FILENO))
			print_prompt();
		input = get_line();
		if (input[0] == '\0')
			continue;
		record_command(input);
		commands = split_command(input);
		for (i = 0; commands[i] != NULL; i++)
		{
			cmd = parse_command(commands[i]);
			if (strcmp(cmd[0], "exit") == 0)
			{
				free(commands);
				process_exit(cmd, input, argv, count, stat);
			}
			else if (detect_builtin(cmd) == 0)
			{
				stat = process_builtin(cmd, stat);
				free(cmd);
				continue;
			}
			else
				stat = detect_command(cmd, input, count, argv);
			free(cmd);
		}
		free(input);
		free(commands);
		wait(&stat);
	}
	return (stat);
}
