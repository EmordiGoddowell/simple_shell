#ifndef SHELL_H
#define SHELL_H

#define BUFFER_SIZE 10240
#define SEPARATOR " \t\r\n\a"
#define OUTPUT(c) (write(STDERR_FILENO, c, _strlen(c)))

#include <ctype.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

/** command_handling.c **/
int detect_builtin(char **cmd);
int process_builtin(char **cmd, int st);
void process_exit(char **cmd, char *input, char **argv, int c, int stat);

/** flip_array.c int_count.c uint_char.c **/
void flip_array(char *arr, int len);
int int_count(int num);
char *uint_char(unsigned int n);

#endif /** SHELL_H **/
