#include "monty.h"
/**
 * mont_pop - prototype function in stack
 * @top: parameter for stack top
 * @xval: parameter for line_number
 * Return: no return
*/
void mont_pop(stack_t **top, unsigned int xval)
{
/*Introducing parameter variables*/
stack_t *tmp;

if (*top == NULL)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", xval);
fclose(mymont.file);
free(mymont.cval);
free_stack(*top);
exit(EXIT_FAILURE);
}
tmp = *top;
*top = tmp->next;
free(tmp);
}

/**
 * mont_q - prototype function to add node to the tail stack
 * @n: parameter for new_value
 * @top: parameter for top of the stack
 * Return: no return
*/
void mont_q(stack_t **top, int n)
{
/*Introducing parameter variables*/
stack_t *nodval, *x;

x = *top;
nodval = malloc(sizeof(stack_t));
if (nodval == NULL)
{
printf("Error\n");
}
nodval->n = n;
nodval->next = NULL;
if (x)
{
while (x->next)
x = x->next;
}
if (!x)
{
*top = nodval;
nodval->prev = NULL;
}
else
{
x->next = nodval;
nodval->prev = x;
}
}

/**
 * mont_push - prototype function to add node to the stack
 * @top: parameter for stack top
 * @xval: parameter for line_number
 * Return: no return
*/
void mont_push(stack_t **top, unsigned int xval)
{
/*Introducing parameter variables*/
int n, j = 0, flag = 0;

if (mymont.arg)
{
if (mymont.arg[0] == '-')
j++;
for (; mymont.arg[j] != '\0'; j++)
{
if (mymont.arg[j] > 57 || mymont.arg[j] < 48)
flag = 1;
}
if (flag == 1)
{ fprintf(stderr, "L%d: usagE: push integer\n", xval);
fclose(mymont.file);
free(mymont.cval);
free_stack(*top);
exit(EXIT_FAILURE);
}
}
else
{ fprintf(stderr, "L%d: usagE: push integer\n", xval);
fclose(mymont.file);
free(mymont.cval);
free_stack(*top);
exit(EXIT_FAILURE);
}
n = atoi(mymont.arg);
if (mymont.lifi == 0)
addnode(top, n);
else
mont_q(top, n);
}

/**
 * mont_queue - prototype function to prints the stack
 * @top: parameter for stack top
 * @xval: parameter for line_number
 * Return: no return
*/
void mont_queue(stack_t **top, unsigned int xval)
{
(void)top;
(void)xval;
mymont.lifi = 1;
}

/**
 * mont_pint - prototype function for printing the stack top
 * @top: parameter for stack top
 * @xval: parameter for line_number
 * Return: no return
*/
void mont_pint(stack_t **top, unsigned int xval)
{
if (*top == NULL)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", xval);
fclose(mymont.file);
free(mymont.cval);
free_stack(*top);
exit(EXIT_FAILURE);
}
printf("%d\n", (*top)->n);
}
