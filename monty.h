#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>



/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO
*/
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;
/**
* struct instruction_s - opcode and its function
* @opcode: the opcode
* @f: function to handle the opcode
*
* Description: opcode and its function
* for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;



/**
* struct arg_m - argument storing variables in monty
* @conn: parameter for connecting file
* @tkns: parameter for storing token
* @tkns_s: parameter for token stored
* @line: parameter for line
* @line_number: parameter for tracking line
* @comm: parameter for commands in a line
*
* Description: prototype that store temporary the variable in monty.
*/



typedef struct arg_m
{
FILE *conn;
char *line;
instruction_t *comm;
char **tkns;
int tkns_s;
unsigned int line_number;
} arg_m



void check_num(char *ptr_s);
void push(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void get_opcode(void);
void exit_conn(void);
void disp_top(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *head);
void swap(stack_t **stack, unsigned int line_number); 
void add(stack_t **stack, unsigned int line_number);
void free_choice();
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void free_head(void);
void free_tkns();
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void free_bcs(void);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);


#endif

