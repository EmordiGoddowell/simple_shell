#include "shell.h"

/**
 * detect_builtin - checks if the parsed command is a built-in command
 * @cmd: Parsed command to be check
 * Return: 0 Succes -1 Fail
**/

int detect_builtin(char **cmd)
{
	builtin fun[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"env", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int i = 0;

	if (*cmd == NULL)
	{
		return (-1);
	}
	while ((fun + i)->command)
	{
		if (_strcmp(cmd[0], (fun + i)->command) == 0)
			return (0);
		i++;
	}
	return (-1);
}

/**
 * process_builtin - handles predefined built-in commands
 * @cmd: Array of parsed command strings
 * @st: Status of last execution
 * Return: -1 Failure 0 Success
**/

int process_builtin(char **cmd, int st)
{
	builtin built_in[] = {
		{"cd", change_directory},
		{"env", print_environment},
		{"help", display_help},
		{"echo", execute_echo},
		{"history", print_history},
		{NULL, NULL}
	};
	int i = 0;

	for (i = 0; (built_in + i)->command; i++)
	{
		if (strcmp(cmd[0], (built_in + i)->command) == 0)
		{
			return ((built_in + i)->function(cmd, st));
		}
	}

	return (-1);
}

/**
 * process_exit - handles the exit status for built-in commands
 * @cmd: Array of parsed command strings
 * @input: Input recieved from user (to be freed)
 * @argv: Arguments before program starts(argv[0] == Shell Program Name)
 * @c: Shell execution count
 * @stat: Exit status
 */

void process_exit(char **cmd, char *input, char **argv, int c, int stat)
{
	int status, i = 0;

	if (cmd[1] == NULL)
	{
		free(input);
		free(cmd);
		exit(stat);
	}
	while (cmd[1][i])
	{
		if (isalpha(cmd[1][i++]) != 0)
		{
			custom_error(argv, c, cmd);
			free(input);
			free(cmd);
			exit(2);
		}
		else
		{
			status = atoi(cmd[1]);
			if (status == 2)
			{
				custom_error(argv, c, cmd);
				free(input);
				free(cmd);
				exit(status);
			}
			free(input);
			free(cmd);
			exit(status);
		}
	}
}
