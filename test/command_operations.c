#include "shell.h"

/**
 * find_cmd -  Search In $PATH for executable command
 * @cmd: Parsed input
 * Return: 0 on success or  1 on failure  0
**/

int find_cmd(char **cmd)
{
	char *path, *value, *cmd_path;
	struct stat buf;

	path = get_env("PATH");
	value = _strtok(path, ":");
	while (value != NULL)
	{
		cmd_path = build_path(*cmd, value);
		if (stat(cmd_path, &buf) == 0)
		{
			*cmd = strdup(cmd_path);
			free(cmd_path);
			free(path);
			return (0);
		}
		free(cmd_path);
		value = _strtok(NULL, ":");
	}
	free(path);
	free(value);
	return (1);
}

/**
 * build_path - Build the full path of a command
 * @token: Executable command
 * @value: Directory conatining Command
 * Return: Parsed full path of command or NULL if failed
**/

char *build_path(char *token, char *value)
{
	char *cmd;
	size_t len;

	len = strlen(value) + strlen(token) + 2;

	cmd = malloc(sizeof(char) * len);

	if (cmd == NULL)
	{
		free(cmd);
		return (NULL);
	}

	memset(cmd, 0, len);

	cmd = strcat(cmd, value);
	cmd = strcat(cmd, "/");
	cmd = strcat(cmd, token);

	return (cmd);
}

/**
 * get_env - Gets the value of environment variable by name
 * @name: Environment variable name
 * Return: The value of the environment variable or NULL if failed
**/

char *get_env(char *name)
{
	size_t name_len, value_len;
	char *value;
	int i, j, k;

	name_len = strlen(name);
	for (i = 0 ; environ[i]; i++)
	{
		if (strncmp(name, environ[i], name_len) == 0)
		{
			value_len = strlen(environ[i]) - name_len;

			value = malloc(sizeof(char) * value_len);

			if (!value)
			{
				free(value);
				perror("unable to alloc");
				return (NULL);
			}

			j = 0;
			for (k = name_len + 1; environ[i][k]; k++, j++)
			{
				value[j] = environ[i][k];
			}
			value[j] = '\0';

			return (value);
		}
	}
	return (NULL);
}
