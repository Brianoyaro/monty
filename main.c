#include "monty.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    char *line;
    unsigned int line_number = 0;
    stack_t *stack = NULL;

    line = malloc(100000);
    while (fgets(line, 100000, file) != NULL) {
        line_number++;
        char *token = strtok(line, " \t\n");
        if (token == NULL || *token == '#') {
            continue;  // Skip empty lines and comments
        }

        char *opcode = token;
        int value = 0;

        if (strcmp(opcode, "push") == 0) {
            // Parse the argument for the push instruction
            token = strtok(NULL, " \t\n");
            if (token == NULL) {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }
            value = atoi(token);
            push(&stack, line_number, value);
        } else if (strcmp(opcode, "pall") == 0) {
            pall(&stack, line_number);
        } else if (strcmp(opcode, "pint") == 0) {
            pint(&stack, line_number);
        } else if (strcmp(opcode, "pop") == 0) {
            pop(&stack, line_number);
        } else if (strcmp(opcode, "swap") == 0) {
            swap(&stack, line_number);
        } else if (strcmp(opcode, "add") == 0) {
            add(&stack, line_number);
        } else if (strcmp(opcode, "nop") == 0) {
            nop(&stack, line_number);
        } else {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);

    // Clean up the stack
    while (stack != NULL) {
        pop(&stack, line_number);
    }

    return EXIT_SUCCESS;
}
