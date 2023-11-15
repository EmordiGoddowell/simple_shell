#include "shell.h"

/**
 * print_error_message - Displays an error message
 *	with details about the input that caused the error.
 * @input: The input that triggered the error.
 * @counter: The count of shell loop.
 * @argv: Arguments before the program starts
 *	(argv[0] == Shell Program Name).
 */

void print_error_message(char *input, int counter, char **argv)
{
	char *er;

	OUTPUT(argv[0]);
	OUTPUT(": ");
	er = uint_char(counter);
	OUTPUT(er);
	free(er);
	OUTPUT(": ");
	OUTPUT(input);
	OUTPUT(": command not found\n");
}

/**
 * custom_error - Prints a custom error message
 *	with details about an illegal number.
 * @argv: Arguments before the program starts
 *	(argv[0] == Shell Program Name).
 * @c: Error count.
 * @cmd: Array of parsed command strings.
**/

void custom_error(char **argv, int c, char **cmd)
{
	char *er = uint_char(c);

	OUTPUT(argv[0]);
	OUTPUT(": ");
	OUTPUT(er);
	OUTPUT(": ");
	OUTPUT(cmd[0]);
	OUTPUT(": illegal number: ");
	OUTPUT(cmd[1]);
	OUTPUT("\n");
	free(er);
}

/**
 * file_error_handler - Prints a custom
 *	error message when a file cannot be opened.
 * @argv: Arguments before the program starts
 *	(argv[0] == Shell Program Name).
 * @c: Error count.
**/

void file_error_handler(char **argv, int c)
{
	char *er = uint_char(c);

	OUTPUT(argv[0]);
	OUTPUT(": ");
	OUTPUT(er);
	OUTPUT(": file cannot be opened ");
	OUTPUT(argv[1]);
	OUTPUT("\n");
	free(er);
}
