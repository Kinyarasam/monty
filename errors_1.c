#include "monty.h"

/**
 * usage_error - Prints usage error messages.
 *
 * Return: Always EXIT_FAILURE
 */
int usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * malloc_error - Prints malloc error messages.
 *
 * Return: Always EXIT_FAILURE
 */
int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * f_open_error - Prints file opening error messages w/ filename.
 * @filename: Name of file that failed to open
 *
 * Return: Always EXIT_FAILURE
 */
int f_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * unknown_op_error - Prints unknown instruction error messages.
 * @opcode: opcode where error occured.
 * @line_number: line number in Monty bytecodes file where error occured
 *
 * Return: Always EXIT_FAILURE
 */
int unknown_op_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown Instruction %s\n", line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * no_int_error - Prints invalid monty_push argument error messages.
 * @line_number: Line number in MOnty bytecodes file where error occured.
 *
 * Return: Always EXIT_FAILURE.
 */
int no_int_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: Usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
