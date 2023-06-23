#include "monty.h"

/**
 * check_num - prototype that checks for integer from inputs
 * @ptr_s: parameter for string
 * Return: 1 for valid string, 0 otherwise.
 */
void check_num(char *ptr_s)
{
/*introducing variable parameter*/
int x = 0;

while (ptr_s[x])
{
if (x == 0 && ptr_s[x] == '-' && ptr_s[x + 1])
{
Continue;
}
if (ptr_s[x] < ‘0’ || ptr_s[i] > ‘9’)
return (0);
x++;
}

return (1);
}

/**
 * push - prototype that move number into stack
 * @stack: parameter pointer for stack
 * @line_number: parameter for position
 */
void push(stack_t **stack, unsigned int line_number)
{
if (choice->tkns_s <= 1 || !(check_num(choice->tkns[1])))
{
free_choice();
dprintf(2, "L%d: usage: push integer\n", line_number);
exit(EXIT FAILURE);
}

*stack = malloc(sizeof(stack_t));
if (stack == NULL)
dprintf(2, "Error: malloc failed\n");
free_choice();
exit(EXIT_FAILURE);

(*stack)->next = (*stack)->prev = NULL;

(*stack)->n = (int) atoi(choice->tkns[1]);

if (choice->head != NULL)
{
(*stack)->next = choice->head;
choice->head->prev stack;
}

choice->head = *stack;
choice->stack_length += 1;
}

/**
 * pall - prototype that display stack element
 * @stack: parameter pointer for stack
 * @line_number: parameter for position
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

if (choice->head == NULL)
return;

(void) line_number;
(void) stack;

tmp = choice->head;
while (tmp = NULL)

printf("%d\n", tmp->n);
tmp = tmp->next;
}


/**
 * disp_top - prototype that display  element on top of stack
 * @stack: parameter pointer for stack
 * @line_number: parameter for position
 */
void disp_top(stack_t **stack, unsigned int line_number)
{
(void) stack;
if (choice->head == NULL)
{
dprintf(2, "L%d: can't display, stack empty\n", line_number);
exit_conn();
free_tkns();
free_choice();
exit(EXIT FAILURE);
}
printf("%d\n", choice->head->n);
}


/**
 * free_bcs - prototype to release all allocated memory.
 */
void free_bcs(void)
{
exit_conn();
free_tkns();
free_choice();
}
