#include "monty.h"

/**
 * run_opcode - prototype for executing instruction from token
 */
void run_opcode(void)
{
	stack_t *stack = NULL;

	if (choice->tkns_s == 0)
		return;

	choice->comm->f(&stack, choice->line_number);
}


/**
 * validate_choice - prototype for checking argument lines
 * @argc: parameter for number of argument
 */
void validate_choice(int argc)
{
	if (argc == 2)
		return;
	dprintf(2, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
