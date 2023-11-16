#include "shell.h"
#include <errno.h>

/**
* process_file - Reads commands from the argument File
* @file: File containing commands
* @argv: Arguments passed
* Return: -1 or 0
**/

void process_file(char *file, char **argv)
{
FILE *fp;
char *line = NULL;
size_t len = 0;
int count = 0;

fp = fopen(file, "r");
if (fp == NULL)
{
file_exit(argv, line, fp);
exit(127);
}
while ((getline(&line, &len, fp)) != -1)
{
count++;
process_command(line, count, fp, argv);
}
if (line)
free(line);
fclose(fp);
exit(0);
}

/**
* process_command - Parse commands and handle their execution
* @line: Line from file
* @count: Error counter
* @fp: File descriptor
* @argv: Command line arguments
**/

void process_command(char *line, int count, FILE *fp, char **argv)
{
char **cmd;
int stat = 0;

cmd = parse_command(line);
if (strncmp(cmd[0], "exit", 4) == 0)
file_exit(cmd, line, fp);
else if (detect_builtin(cmd) == 0)
{
stat = process_builtin(cmd, stat);
free(cmd);
}
else
{
stat = detect_command(cmd, line, count, argv);
free(cmd);
}
}

/**
* file_exit - Exit status handler for file input
* @cmd: Parsed command
* @line: Line from a file
* @fd: File Descriptor
**/

void file_exit(char **cmd, char *line, FILE *fd)
{
int status;
int i = 0;

if (cmd[i] == NULL)
{
free(line);
free(cmd);
fclose(fd);
exit(errno);
}
while (cmd[1][i])
{
if (isalpha(cmd[1][i++]) < 0)
perror("Illegal number");
}
status = atoi(cmd[1]);
free(line);
free(cmd);
fclose(fd);
exit(status);
}
