#ifndef SHELL_H
#define SHELL_H

#define BUFFER_SIZE 10240
#define SEPARATOR " \t\r\n\a"
#define OUTPUT(c) (write(STDERR_FILENO, c, strlen(c)))
extern char **environ;

#include <ctype.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * struct built_in - Defines a structure that associates built-in commands
 *	with their corresponding function implementations
 * @command: The built-in command as a string
 * @function: A function pointer to the implementation of the built-in command.
 *
 * The function takes an array of strings (the command and its arguments) and 
 *	an integer status as parameters, and returns an integer status.
**/

typedef struct built_in
{
	char *command;
	int (*function)(char **line, int st);
} builtin;

/** error_functions.c **/
void print_error_message(char *input, int counter, char **argv);
void custom_error(char **argv, int c, char **cmd);
void file_error_handler(char **argv, int c);

/**
** 0-string_io_functions.c **
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strncmp(const char *s1, const char *s2, size_t n);

** 1-string_io_function.c **
int _putchar(char c);
void _puts(char *str);
int _atoi(char *s);
char *_strchr(char *s, char c);
char *_strdup(char *str);

** 2-string_io_function.c **
int _isalpha(int c);
void flip_array(char *arr, int len);
int int_count(int num);
char *uint_char(unsigned int n);
int _strcmp(char *s1, char *s2);
**/

/** command_operations.c **/
int find_cmd(char **cmd);
char *build_path(char *token, char *value);
char *get_env(char *name);

/** input_handling.c **/
char *new_line(char *string);
char *white_space(char *str);
void hashtag(char *buff);
unsigned int check_delim(char c, const char *str);

/** parse_command.c **/
char **parse_command(char *input);

/** getline_strtok.c **/
char *get_line(void);
char *_strtok(char *str, const char *separate);

/** 0-builtin_help.c 1-builtin_help.c **/
void display_help_all(void);
void display_alias_help(void);
void display_cd_help(void);
void display_exit_help(void);
void display_help_help(void);
void display_help_env(void);
void display_help_setenv(void);
void display_help_unsetenv(void);
int display_help(char **cmd, __attribute__((unused)) int st);

/** 0-command_handling.c **/
int detect_builtin(char **cmd);
int process_builtin(char **cmd, int st);
void process_exit(char **cmd, char *input, char **argv, int c, int stat);

/** 1-command_handling.c **/
void print_prompt(void);
int record_command(char *input);
char **split_command(char *input);

/** flip_array.c int_count.c uint_char.c **/
void flip_array(char *arr, int len);
int int_count(int num);
char *uint_char(unsigned int n);

/** environment_handlers.c **/
int print_env(__attribute__((unused))
		char **cmd, __attribute__((unused)) int st);
int process_echo(char **cmd, int st);
int print_history(__attribute__((unused))
		char **c, __attribute__((unused))int st);
void init_environment(char **env_vars);
void free_environment(char **env_vars);

/**  file_command_processor.c **/
void process_file(char *file, char **argv);
void process_command(char *line, int count, FILE *fp, char **argv);
void file_exit(char **cmd, char *line, FILE *fd);

/** memory_management.c **/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_calloc(unsigned int size);
void release_memory(char **cmd, char *line);
void *initialize_memory(void *a, int el, unsigned int len);

/** print_and_execute.c **/
void print_unsigned_int(unsigned int n);
void print_int(int n);
int execute_echo(char **cmd);

/** execute_and_handle.c **/
int detect_command(char **cmd, char *input, int c, char **argv);
void ignore_sigint(int sig);

/** main.c **/
int main(__attribute__((unused)) int argc, char **argv);

#endif /** SHELL_H **/
