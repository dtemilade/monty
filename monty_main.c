#include "monty.h"
#include <stdio.h>
/**
* main - prototype function for monty code interpreter
* @argc: parameter for number of arguments
* @argv: parameter for monty file location
* Return: 0 on success
*/
mymont_t mymont = {NULL, NULL, NULL, 0};
int main(int argc, char *argv[])
{
/*Introducing parameter variables*/
FILE *file;
stack_t *stack = NULL;
size_t size = 0;
ssize_t rval = 1;
unsigned int xval = 0;
char *cval;

if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
file = fopen(argv[1], "r");
mymont.file = file;
if (!file)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}
while (rval > 0)
{
cval = NULL;
rval = getline(&cval, &size, file);
mymont.cval = cval;
xval++;
if (rval > 0)
{
execute(cval, &stack, xval, file);
}
free(cval);
}
free_stack(stack);
fclose(file);
return (0);
}

/**
 * mont_pchar - prints the char at the top of the stack,
 * followed by a new line
 * @top: parameter for stack top
 * @xval: parameter for line_number
 * Return: no return
*/
void mont_pchar(stack_t **top, unsigned int xval)
{
/*Introducing parameter variables*/
stack_t *tmp;

tmp = *top;
if (!tmp)
{
fprintf(stderr, "L%d: can't pchar, stack empty\n", xval);
fclose(mymont.file);
free(mymont.cval);
free_stack(*top);
exit(EXIT_FAILURE);
}
if (tmp->n > 127 || tmp->n < 0)
{
fprintf(stderr, "L%d: can't pchar, value out of range\n", xval);
fclose(mymont.file);
free(mymont.cval);
free_stack(*top);
exit(EXIT_FAILURE);
}
printf("%c\n", tmp->n);
}

/**
 * mont_pall - prototype function for printing the stack
 * @top: parameter for stack top
 * @xval: parameter for no used
 * Return: no return
*/
void mont_pall(stack_t **top, unsigned int xval)
{
/*Introducing parameter variables*/
stack_t *tmp;
(void)xval;

tmp = *top;
/*Introducing conditional statement*/
if (tmp == NULL)
return;
while (tmp)
{
printf("%d\n", tmp->n);
tmp = tmp->next;
}
}

/**
*mont_nop- prototype function for dissolve.
*@top: parameter for stack top
*@xval: parameter for line_number
*Return: no return
 */
void mont_nop(stack_t **top, unsigned int xval)
{
(void) xval;
(void) top;
}

/**
 * mont_stack - prototype function
 * @top: parameter for stack top
 * @xval: parameter for line_number
 * Return: no return
*/
void mont_stack(stack_t **top, unsigned int xval)
{
(void)top;
(void)xval;
mymont.lifi = 0;
}
