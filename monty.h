#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: parameter for integer
 * @prev: parameter for points to the previous element of the stack (or queue)
 * @next: parameter for points to the next element of the stack (or queue)
 *
 * Description: parameter for doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * @f: parameter for function to handle the opcode
 *
 * Description: parameter for opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct mymont_s - variables -args, file, line cval
 * @arg: parameter for value
 * @file: pointer to monty file
 * @cval: parameter for line cval
 * @lifi: parameter for flag change stack <-> queue
 * Description: parameter for carries values through the program
 */
typedef struct mymont_s
{
	char *arg;
	FILE *file;
	char *cval;
	int lifi;
} mymont_t;

extern mymont_t mymont;


ssize_t getline(char **lineptr, size_t *n, FILE *stream);
void mont_add(stack_t **top, unsigned int xval);
void mont_nop(stack_t **top, unsigned int xval);
void mont_mod(stack_t **top, unsigned int xval);
char *clean_line(char *cval);
void mont_pchar(stack_t **top, unsigned int xval);
int execute(char *cval, stack_t **top, unsigned int xval, FILE *file);
void free_stack(stack_t *top);
void mont_sub(stack_t **top, unsigned int xval);
void mont_q(stack_t **top, int n);
void mont_queue(stack_t **top, unsigned int xval);
void mont_pint(stack_t **top, unsigned int number);
void mont_rotr(stack_t **top, __attribute__((unused)) unsigned int xval);
void addnode(stack_t **top, int n);
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
void mont_stack(stack_t **top, unsigned int xval);
void mont_div(stack_t **top, unsigned int xval);
void mont_mul(stack_t **top, unsigned int xval);
void mont_pop(stack_t **top, unsigned int xval);
void mont_swap(stack_t **top, unsigned int xval);
void mont_pstr(stack_t **top, unsigned int xval);
void mont_rotl(stack_t **top, unsigned int xval);
void mont_push(stack_t **top, unsigned int number);
void mont_pall(stack_t **top, unsigned int number);

#endif
