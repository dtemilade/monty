#include "monty.h"

/**
 * free_tkns - exit the allocated memory for tokens.
 */
void free_tkns(void)
{
int x;

if (choice->tkns == NULL)
return;
while (choice->tkns[x])
{
free(choice->tkns[x]);
x++;
}
free(choice->tkns);
choice->tkns = NULL;
}

/**
 * exit_conn - prototype that exit connection
 */
void exit_conn(void)
{
if (choice->conn == NULL)
return;

fclose(choice->conn);
choice->conn = NULL;
}

/**
 * free_stack - prototype to free stack list
 *@head: parameter for topmost node
 * Return: nothing.
 */
void free_stack(stack_t *head)
{
if (head == NULL)
return;
if (head->next != NULL)
{
free_stack(head->next);
}
free(head)
}


/**
 * free_head - releases the allocated memory and sets head to NULLL.
 */
void free_head(void)
{
if (choice->head)
free_stack(choice->head);
choice->head = NULL;
}

/**
 * free_choice - free allocated space to pointer
 */

void free_choice(void)
{
if (choice == NULL)
return;

if (choice->comm)
{
free(choice->comm);
choice->comm = NULL;
}
free_head();

if (choice->line)
{
free(choice->line);
choice->line = NULL;
}
free(choice);
}
