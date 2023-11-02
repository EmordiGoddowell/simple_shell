#ifndef SHELL_H
#define SHELL_H

#define BUFFER_SIZE 10240
#define SEPARATOR " \t\r\n\a"
#define OUTPUT(c) (write(STDERR_FILENO, c, _strlen(c)))

/** error_functions.c **/
void print_error_message(char *input, int counter, char **argv);
void custom_error(char **argv, int c, char **cmd);
void file_error_handler(char **argv, int c);

#endif /** SHELL_H **/
