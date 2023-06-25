
#include "monty.h"
/**
 * mont_add - prototype function to adds the top two elements of the stack.
 * @top: parameter for stack top
 * @xval: parameter for line_number
 * Return: no return
*/
void mont_add(stack_t **top, unsigned int xval)
{
/*Introducing parameter variables*/
stack_t *tmp;
int x, len = 0;

tmp = *top;
while (tmp)
{
tmp = tmp->next;
len++;
}
if (len < 2)
{
fprintf(stderr, "L%d: can't add, stack too short\n", xval);
fclose(mymont.file);
free(mymont.cval);
free_stack(*top);
exit(EXIT_FAILURE);
}
tmp = *top;
x = tmp->n + tmp->next->n;
tmp->next->n = x;
*top = tmp->next;
free(tmp);
}

/**
 * mont_div - prototype function to divides the top two elements of the stack.
 * @top: parameter for stack top
 * @xval: parameter for line_number
 * Return: no return
*/
void mont_div(stack_t **top, unsigned int xval)
{
/*Introducing parameter variables*/
stack_t *tmp;
int x, len = 0;

tmp = *top;
while (tmp)
{
tmp = tmp->next;
len++;
}
if (len < 2)
{
fprintf(stderr, "L%d: can't div, stack too short\n", xval);
fclose(mymont.file);
free(mymont.cval);
free_stack(*top);
exit(EXIT_FAILURE);
}
tmp = *top;
if (tmp->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", xval);
fclose(mymont.file);
free(mymont.cval);
free_stack(*top);
exit(EXIT_FAILURE);
}
x = tmp->next->n / tmp->n;
tmp->next->n = x;
*top = tmp->next;
free(tmp);
}

/**
*mont_sub - prototype function for subtraction
*@top: parameter for stack top
*@xval: parameter for line_number
*Return: no return
 */
void mont_sub(stack_t **top, unsigned int xval)
{
/*introducing parameter variable*/
stack_t *x;
int nodes, mval;

x = *top;
for (nodes = 0; x != NULL; nodes++)
x = x->next;
if (nodes < 2)
{
fprintf(stderr, "L%d: can't sub, stack too short\n", xval);
fclose(mymont.file);
free(mymont.cval);
free_stack(*top);
exit(EXIT_FAILURE);
}
x = *top;
mval = x->next->n - x->n;
x->next->n = mval;
*top = x->next;
free(x);
}


/**
 * mont_mod - prototype function for computation
 * @top: parameter for stack top
 * @xval: parameter for line_number
 * Return: no return
*/
void mont_mod(stack_t **top, unsigned int xval)
{
/*Introducing parameter variables*/
stack_t *tmp;
int x, len = 0;

tmp = *top;
while (tmp)
{
tmp = tmp->next;
len++;
}
if (len < 2)
{
fprintf(stderr, "L%d: can't mod, stack too short\n", xval);
fclose(mymont.file);
free(mymont.cval);
free_stack(*top);
exit(EXIT_FAILURE);
}
tmp = *top;
if (tmp->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", xval);
fclose(mymont.file);
free(mymont.cval);
free_stack(*top);
exit(EXIT_FAILURE);
}
x = tmp->next->n % tmp->n;
tmp->next->n = x;
*top = tmp->next;
free(tmp);
}

/**
 * mont_mul - prototype function for multiply top two elements in stack.
 * @top: parameter for stack top
 * @xval: parameter for line_number
 * Return: no return
*/
void mont_mul(stack_t **top, unsigned int xval)
{
/*Introducing parameter variables*/
stack_t *tmp;
int len = 0, x;

tmp = *top;
while (tmp)
{
tmp = tmp->next;
len++;
}
if (len < 2)
{
fprintf(stderr, "L%d: can't mul, stack too short\n", xval);
fclose(mymont.file);
free(mymont.cval);
free_stack(*top);
exit(EXIT_FAILURE);
}
tmp = *top;
x = tmp->next->n * tmp->n;
tmp->next->n = x;
*top = tmp->next;
free(tmp);
}
