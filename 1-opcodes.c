#include "monty.h"

/**
 * push - pushes a node to the top of stack
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 *
 * Return: (0).
 */
void push(stack_t **stack, unsigned int nline)
{
	stack_t *new;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: stack not found\n", nline);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	new->next = *stack;
	new->prev = NULL;
	new->n = arg.arg;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * pall - prints all values in stack starting from top
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 *
 * Return: Nothing.
 */
void pall(stack_t **stack, unsigned int nline)
{
	stack_t *temp;
	(void)nline;

	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * free_stack - frees all nodes in a stack
 * @stack: pointer to the head node pointer of stack
 *
 * Return: Nothing.
 */
void free_stack(stack_t **stack)
{
	stack_t *temp = NULL;

	if (stack == NULL || *stack == NULL)
		return;

	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}
