#include "monty.h"
/**
* execute - prototype function to executes the opcode
* @stack: parameter for top linked list - stack
* @xval: parameter for line_xval
* @file: poiner to monty file
* @cval: parameter for line cval
* Return: no return
*/
int execute(char *cval, stack_t **stack, unsigned int xval, FILE *file)
{
instruction_t opst[] = {
{"push", mont_push}, {"pall", mont_pall}, {"pint", mont_pint},
{"pop", mont_pop},
{"swap", mont_swap},
{"add", mont_add},
{"nop", mont_nop},
{"sub", mont_sub},
{"div", mont_div},
{"mul", mont_mul},
{"mod", mont_mod},
{"pchar", mont_pchar},
{"pstr", mont_pstr},
{"rotl", mont_rotl},
{"rotr", mont_rotr},
{"queue", mont_queue},
{"stack", mont_stack},
{NULL, NULL}
};
unsigned int i = 0;
char *op;

op = strtok(cval, " \n\t");
if (op && op[0] == '#')
return (0);
mymont.arg = strtok(NULL, " \n\t");
while (opst[i].opcode && op)
{
if (strcmp(op, opst[i].opcode) == 0)
{ opst[i].f(stack, xval);
return (0);
}
i++;
}
if (op && opst[i].opcode == NULL)
{ fprintf(stderr, "L%d: unknown instruction %s\n", xval, op);
fclose(file);
free(cval);
free_stack(*stack);
exit(EXIT_FAILURE); }
return (1);
}

/**
* free_stack - prototype function that frees a doubly linked list
* @top: parameter for top of the stack
*/
void free_stack(stack_t *top)
{
/*Introducing parameter variables*/
stack_t *x;

x = top;
while (top)
{
x = top->next;
free(top);
top = x;
}
}


