#include "monty.h"

#include <stdlib.h>
#include <stdio.h>

/**
 * Function to push an element onto the stack.
 * @stack: The stack.
 * @line_number: The line number.
 * @value: The value to push.
 */
void push(stack_t **stack,__attribute__((unused)) unsigned int line_number, int value)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;
    if (*stack)
        (*stack)->prev = new_node;
    *stack = new_node;
}

/**
 * Function to print all values on the stack.
 * @stack: The stack.
 * @line_number: The line number.
 */
void pall(stack_t **stack, unsigned int line_number)
{
    (void)line_number;
    stack_t *current = *stack;
    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

/**
 * Function to print the value at the top of the stack.
 * @stack: The stack.
 * @line_number: The line number.
 */
void pint(stack_t **stack, unsigned int line_number)
{
    if (!stack || !*stack)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*stack)->n);
}

/**
 * Function to remove the top element from the stack.
 * @stack: The stack.
 * @line_number: The line number.
 */
void pop(stack_t **stack, unsigned int line_number)
{
    if (!stack || !*stack)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }
    stack_t *top = *stack;
    *stack = top->next;
    if (*stack)
        (*stack)->prev = NULL;
    free(top);
}

/**
 * Function to swap the top two elements of the stack.
 * @stack: The stack.
 * @line_number: The line number.
 */
void swap(stack_t **stack, unsigned int line_number)
{
    if (!stack || !*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    int temp = (*stack)->n;
    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = temp;
}

/**
 * Function to add the top two elements on the stack.
 * @stack: The stack.
 * @line_number: The line number.
 */
void add(stack_t **stack, unsigned int line_number)
{
    if (!stack || !*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    (*stack)->next->n += (*stack)->n;
    pop(stack, line_number);
}

/**
 * Function that doesn't do anything (nop).
 * @stack: The stack.
 * @line_number: The line number.
 */
void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}

