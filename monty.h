#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
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

typedef struct help
{
    char *token2;
    char *buffer;
    FILE *fp;
    stack_t *head;
    size_t line_number;
    size_t n;
    char *token1;
    int queueflag;
} helpers;

extern helpers helpy;

void push_handler(stack_t **head, unsigned int line_number);
void pall_handler(stack_t **head, unsigned int line_number);
void pint_handler(stack_t **head, unsigned int line_number);
void free_dlistint_handler(stack_t *head);
int monty_process(void);
void free_everything(void);
int is_number(void);
void pop_handler(stack_t **head, unsigned int line_number);
void swap_handler(stack_t **head, unsigned int line_number);
void add_handler(stack_t **head, unsigned int line_number);
void nop_handler(stack_t **head, unsigned int line_number);
void sub_handler(stack_t **head, unsigned int line_number);
void div_handler(stack_t **head, unsigned int line_number);
void mul_handler(stack_t **head, unsigned int line_number);
void mod_handler(stack_t **head, unsigned int line_number);
void pstr_handler(stack_t **head, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
int compare_instructions(void);
void rotl_handler(stack_t **head, unsigned int line_number);
void rotr_handler(stack_t **head, unsigned int line_number);
int queue_push(stack_t **head, unsigned int line_number);

#endif /* MONTY_H */
