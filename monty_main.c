#include "monty.h"

/**
 * init_choice - prototype function to start pointer.
 */
void init_choice(void)
{
choice = malloc(sizeof(arg_m));
if (choice == NULL)
dprintf(2, "Error: malloc failed\n");
free_choice();
exit(EXIT_FAILURE);

choice->comm = malloc(sizeof(instruction_t));
if (choice->comm == NULL)
dprintf(2, "Error: malloc failed\n");
free_choice();
exit(EXIT_FAILURE);

choice->conn = NULL;
choice->line = NULL;
choice->tkns_s = 0;
choice->line_number = 0;
}

/**
* read_tkns - prototype that read line for tkns from file
*/
void read_tkns(void)
{
/*introducing parameter variable*/
char *tkn = NULL, *cp_line = NULL, i = " \n";
int x = 0;

cp_line = malloc(sizeof(char) * (strlen(choice->line) + 1));
strcpy(cp_line, choice->line);
choice->tkns_s = 0;
tkn = strtok(cp_line, i);
while (tkn)
{
choice->tkns_s += 1;
tkn = strtok(NULL, i);
}

choice->tkns = malloc(sizeof(char *) * (choice->tkns_s + 1));
strcpy(cp_line, choice->line);
tkn = strtok(cp_line, i);
while (tkn)
{
choice->tkns[x] = malloc(sizeof(char) (strlen(tkn) + 1));

if (choice->tkns[x] == NULL)
dprintf(2, "Error: malloc failed\n");
free_choice();
exit(EXIT_FAILURE);
strcpy(choice->tkns[x], tkn);
tkn = strtok(NULL, i);
x++;
}
choice->tkns[x] == NULL;
free(cp_line);
}



/**
* start_conn - function prototype that gets the conn for reading
* @file: parameter for file to open
*/
void start_conn(char *file)
{
int fd;

fd = open(file, O_RDONLY);

if (fd == 1)
dprintf(stderr, "Error: Can't open file %s\n", file);
free_choice();
exit(EXIT FAILURE);

choice->conn = fdopen(fd, "r");

if (choice->conn == NULL)
{
close(fd);
dprintf(stderr, "Error: Can't open file %s\n", file);
free_choice();
exit(EXIT FAILURE);
}
}



/**
* get_opcode - prototype for getting instruction from token
*/
void get_opcode(void)
{
int x = 0;
instruction_t comm[] = {
{"push", &push}, {"pop", &pop},
{"disp_top", &disp_top}, {"swap", &swap},
{"nop", &nop}, {"add", &add},
{"pall", &pall}, {"sub", &sub},
{"div", &_div}, {"mul", &mul},
("rotl", &rotl}, {"rotr", &rotr},
{"stack", &stack}, ("queue", &queue},
{"pstc", &pstr}, {"pchar", &pchar},
{"mod", &mod},
{NULL, NULL}
};

if (argument->tkns_s == 0)
return;

for (; comm[x].opcode != NULL; x++)
{
if (strcmp(comm[x].opcode, choice->tkns[0]) == 0)
{
choice->comm->opcode = comm[x].opcode;
choice->comm->f comm[x].f;
return;
}
}
dprintf(2, "L%d: unknown instruction %s\n",
choice->line_number, choice->tkns[0]);
free_bcs();
exit(EXIT_FAILURE);
}

/**
* main - monty main function.
* @argc: argument count
* @argv: parameter for argument values
* Return: Always 0 (Success).
*/
int main(int argc, char **argv)
{

/*introducing parameter*/
Size_t i = 0;
arg_m *choice = NULL;

validate_choice(argc);
init_choice();
start_conn(argv[1]);

/*accessing the argument and opcode*/
while (getline(&choice->line, &i, choice->conn) != 1)
{
choice->line_number += 1;
read_tkns();
get_opcode();
run_opcode();
free_tkns();
}

exit_conn();
free_choice();

return (0);
}
