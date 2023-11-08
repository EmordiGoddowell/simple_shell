#include "shell.h"

/**
 * display_help_env - Provides information about
 *	the 'env' command
**/

void display_help_env(void)

{
	char *msg = "env: env\n\tPrints the current environment.\n";

	write(STDOUT_FILENO, msg, strlen(msg));
}

/**
 * display_help_setenv - Provides information about
 *	the 'setenv' command
**/

void display_help_setenv(void)
{
	char *msg = "setenv: setenv [VARIABLE] [VALUE]\n\tInitializes a new";

	write(STDOUT_FILENO, msg, strlen(msg));
	msg = "environment variable, or modifies an existing one.\n\n";
	write(STDOUT_FILENO, msg, strlen(msg));
	msg = "\tUpon failure, prints a message to stderr.\n";
	write(STDOUT_FILENO, msg, strlen(msg));
}

/**
 * display_help_unsetenv - Provides information about
 *	the 'unsetenv' command
**/

void display_help_unsetenv(void)
{
	char *msg = "unsetenv: unsetenv [VARIABLE]\n\tRemoves an ";

	write(STDOUT_FILENO, msg, strlen(msg));
	msg = "environmental variable.\n\n\tUpon failure, prints a ";
	write(STDOUT_FILENO, msg, strlen(msg));
	msg = "message to stderr.\n";
	write(STDOUT_FILENO, msg, strlen(msg));
}

/**
 * display_help - display help information for builtin commands
 * @cmd: parsed command
 * @st: Status of last command executed
 *
 * Return: 0 Successful execution
**/

int display_help(char **cmd, __attribute__((unused))int st)
{
	if (!cmd[1])
		display_help_all();
	else if (strcmp(cmd[1], "alias") == 0)
		display_alias_help();
	else if (strcmp(cmd[1], "cd") == 0)
		display_cd_help();
	else if (strcmp(cmd[1], "exit") == 0)
		display_exit_help();
	else if (strcmp(cmd[1], "env") == 0)
		display_help_env();
	else if (strcmp(cmd[1], "setenv") == 0)
		display_help_setenv();
	else if (strcmp(cmd[1], "unsetenv") == 0)
		display_help_unsetenv();
	else if (strcmp(cmd[1], "help") == 0)
		display_help_help();
	return (0);
}
