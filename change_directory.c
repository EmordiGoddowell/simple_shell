#include "shell.h"
#include <limits.h>

/**
 * change_directory - Changes the current working  directory
 * @cmd: Parsed command
 * @st: Status of last command executed
 * Return: 0 on success 1 if failed (For OLDPWD Always 0 incase of no OLDPWD)
**/

int change_directory(char **cmd, __attribute__((unused))int st)
{
	int value = -1;
	char cwd[PATH_MAX];

	if (cmd[1] == NULL)
		value = chdir(get_env("HOME"));
	else if (strcmp(cmd[1], "-") == 0)
	{
		value = chdir(get_env("OLDPWD"));
	}
	else
		value = chdir(cmd[1]);

	if (value == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (value != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", get_env("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}
