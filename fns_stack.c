
#include "monty.h"
/**
 * addnode - add node to the top stack
 * @top: parameter for top of the stack
 * @n: parameter for new_value
 * Return: no return
*/
void addnode(stack_t **top, int n)
{
/*Introducing parameter variables*/
stack_t *x, *nodval;

x = *top;
nodval = malloc(sizeof(stack_t));
if (nodval == NULL)
{ printf("Error\n");
exit(0);
}
if (x)
x->prev = nodval;
nodval->n = n;
nodval->next = *top;
nodval->prev = NULL;
*top = nodval;
}

/**
*mont_rotr - prototype function to rotates the stack to the bottom
*@top: parameter for stack top
*@xval: parameter for line_number
*Return: no return
 */
void mont_rotr(stack_t **top, __attribute__((unused)) unsigned int xval)
{
/*Introducing parameter variables*/
stack_t *tmp;

tmp = *top;
if (*top == NULL || (*top)->next == NULL)
{
return;
}
while (tmp->next)
{
tmp = tmp->next;
}
tmp->next = *top;
tmp->prev->next = NULL;
tmp->prev = NULL;
(*top)->prev = tmp;
(*top) = tmp;
}


/**
 * mont_swap - prototype function to swap top two elements in stack.
 * @top: parameter for stack top
 * @xval: parameter for line_number
 * Return: no return
*/
void mont_swap(stack_t **top, unsigned int xval)
{
/*Introducing parameter variables*/
stack_t *tmp;
int x, len;

len = 0;
tmp = *top;
while (tmp)
{
tmp = tmp->next;
len++;
}
if (len < 2)
{
fprintf(stderr, "L%d: can't swap, stack too short\n", xval);
fclose(mymont.file);
free(mymont.cval);
free_stack(*top);
exit(EXIT_FAILURE);
}
tmp = *top;
x = tmp->n;
tmp->n = tmp->next->n;
tmp->next->n = x;
}

/**
 * mont_pstr - prototype function to print starting string on stack,
 * @top: parameter for stack top
 * @xval: parameter for line_number
 * Return: no return
*/
void mont_pstr(stack_t **top, unsigned int xval)
{
/*Introducing parameter variables*/
stack_t *tmp;
(void)xval;

tmp = *top;
while (tmp)
{
if (tmp->n > 127 || tmp->n <= 0)
{
break;
}
printf("%c", tmp->n);
tmp = tmp->next;
}
printf("\n");
}

/**
*mont_rotl- prototype function to rotates the stack to the top
*@top: parameter for stack top
*@xval: parameter for line_number
*Return: no return
 */
void mont_rotl(stack_t **top, __attribute__((unused)) unsigned int xval)
{
stack_t *tval = *top, *x;

if (*top == NULL || (*top)->next == NULL)
{
return;
}
x = (*top)->next;
x->prev = NULL;
while (tval->next != NULL)
{
tval = tval->next;
}
tval->next = *top;
(*top)->next = NULL;
(*top)->prev = tval;
(*top) = x;
}
