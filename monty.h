#ifndef MONTY_H
#define MONTY_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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
 * Function to push an element onto the stack.
 * @stack: The stack.
 * @line_number: The line number.
 * @value: The value to push.
 */
void push(stack_t **stack, unsigned int line_number, int value);

/**
 * Function to print all values on the stack.
 * @stack: The stack.
 * @line_number: The line number.
 */
void pall(stack_t **stack, unsigned int line_number);

/**
 * Function to print the value at the top of the stack.
 * @stack: The stack.
 * @line_number: The line number.
 */
void pint(stack_t **stack, unsigned int line_number);

/**
 * Function to remove the top element from the stack.
 * @stack: The stack.
 * @line_number: The line number.
 */
void pop(stack_t **stack, unsigned int line_number);

/**
 * Function to swap the top two elements of the stack.
 * @stack: The stack.
 * @line_number: The line number.
 */
void swap(stack_t **stack, unsigned int line_number);

/**
 * Function to add the top two elements on the stack.
 * @stack: The stack.
 * @line_number: The line number.
 */
void add(stack_t **stack, unsigned int line_number);

/**
 * Function that doesn't do anything (nop).
 * @stack: The stack.
 * @line_number: The line number.
 */
void nop(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */

