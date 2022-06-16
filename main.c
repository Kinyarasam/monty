#include "monty.h"

char **op_toks = NULL;

/**
 * main - Entry point for Monty Interp
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: Always EXIT_SUCCESS (success)
 * otherwise: EXIT_FAILURE (failure)
 */
int main(int argc, char **argv)
{
	FILE *script_fd = NULL;
	int exit_code = EXIT_SUCCESS;

	if (argc != 2)
		return (usage_error());
	script_fd = fopen(argv[1], "r");
	if (script_fd == NULL)
		return (f_open_error(argv[1]));
	exit_code = monty(script_fd);
	fclose(script_fd);
	return (exit_code);
}
