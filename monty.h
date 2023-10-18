#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

typedef struct global
{
	FILE *stream;
	char *buffer;
	char *push_val;
} global;
extern global globe;
void function_find(stack_t **head, char *token, unsigned int line_no);
void push(stack_t **head, unsigned int line_no);
void pop(stack_t **head, unsigned int line_no);
void pall(stack_t **head, __attribute__((unused))unsigned int line_no);
void pint(stack_t **head, unsigned int line_no);
void nop(__attribute__((unused))stack_t **head, __attribute__((unused))unsigned int line_no);
void swap(stack_t **head, unsigned int line_no);
int total_nodes(stack_t **head);
void add(stack_t **head, unsigned int line_no);
void sub(stack_t **head, unsigned int line_no);
void div(stack_t **head, unsigned int line_no);
void mod(stack_t **head, unsigned int line_no);


#endif
