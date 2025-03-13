/* checker.c */
#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/*
 * Checker operations:
 * We create versions of the stack operations that do not print the
 * command (unlike the push_swap ones).
 */
void c_sa(t_node **stack_a)
{
    t_node *first;
    t_node *second;
    if (!stack_a || !*stack_a || !((*stack_a)->next))
        return;
    first = *stack_a;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack_a = second;
}

void c_sb(t_node **stack_b)
{
    t_node *first;
    t_node *second;
    if (!stack_b || !*stack_b || !((*stack_b)->next))
        return;
    first = *stack_b;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack_b = second;
}

void c_ss(t_node **stack_a, t_node **stack_b)
{
    c_sa(stack_a);
    c_sb(stack_b);
}

void c_pa(t_node **stack_a, t_node **stack_b)
{
    t_node *tmp;
    if (!stack_b || !*stack_b)
        return;
    tmp = *stack_b;
    *stack_b = tmp->next;
    tmp->next = *stack_a;
    *stack_a = tmp;
}

void c_pb(t_node **stack_a, t_node **stack_b)
{
    t_node *tmp;
    if (!stack_a || !*stack_a)
        return;
    tmp = *stack_a;
    *stack_a = tmp->next;
    tmp->next = *stack_b;
    *stack_b = tmp;
}

void c_ra(t_node **stack)
{
    t_node *first;
    t_node *last;
    if (!stack || !*stack || !((*stack)->next))
        return;
    first = *stack;
    *stack = first->next;
    first->next = NULL;
    last = *stack;
    while (last->next)
        last = last->next;
    last->next = first;
}

void c_rb(t_node **stack)
{
    t_node *first;
    t_node *last;
    if (!stack || !*stack || !((*stack)->next))
        return;
    first = *stack;
    *stack = first->next;
    first->next = NULL;
    last = *stack;
    while (last->next)
        last = last->next;
    last->next = first;
}

void c_rr(t_node **stack_a, t_node **stack_b)
{
    c_ra(stack_a);
    c_rb(stack_b);
}

void c_rra(t_node **stack)
{
    t_node *prev;
    t_node *last;
    if (!stack || !*stack || !((*stack)->next))
        return;
    prev = NULL;
    last = *stack;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    if (prev)
        prev->next = NULL;
    last->next = *stack;
    *stack = last;
}

void c_rrb(t_node **stack)
{
    t_node *prev;
    t_node *last;
    if (!stack || !*stack || !((*stack)->next))
        return;
    prev = NULL;
    last = *stack;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    if (prev)
        prev->next = NULL;
    last->next = *stack;
    *stack = last;
}

void c_rrr(t_node **stack_a, t_node **stack_b)
{
    c_rra(stack_a);
    c_rrb(stack_b);
}

/*
 * A simple get_next_line implementation that reads one line from standard input.
 * It uses a fixed buffer size and reads character by character until a newline
 * or EOF is encountered.
 */
#define BUFFER_SIZE 1024

char *get_next_line(void)
{
    char *buffer;
    int i = 0;
    char c;
    ssize_t ret;

    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return NULL;
    while ((ret = read(0, &c, 1)) > 0)
    {
        if (c == '\n')
            break;
        buffer[i++] = c;
        if (i >= BUFFER_SIZE)
            break;
    }
    if (ret < 0 || (ret == 0 && i == 0))
    {
        free(buffer);
        return NULL;
    }
    buffer[i] = '\0';
    return buffer;
}

/*
 * Executes a given command (instruction) on the stacks.
 * Returns 1 if the command is valid and executed, 0 otherwise.
 */
int execute_command(char *cmd, t_node **stack_a, t_node **stack_b)
{
    if (strcmp(cmd, "sa") == 0)
        c_sa(stack_a);
    else if (strcmp(cmd, "sb") == 0)
        c_sb(stack_b);
    else if (strcmp(cmd, "ss") == 0)
        c_ss(stack_a, stack_b);
    else if (strcmp(cmd, "pa") == 0)
        c_pa(stack_a, stack_b);
    else if (strcmp(cmd, "pb") == 0)
        c_pb(stack_a, stack_b);
    else if (strcmp(cmd, "ra") == 0)
        c_ra(stack_a);
    else if (strcmp(cmd, "rb") == 0)
        c_rb(stack_b);
    else if (strcmp(cmd, "rr") == 0)
        c_rr(stack_a, stack_b);
    else if (strcmp(cmd, "rra") == 0)
        c_rra(stack_a);
    else if (strcmp(cmd, "rrb") == 0)
        c_rrb(stack_b);
    else if (strcmp(cmd, "rrr") == 0)
        c_rrr(stack_a, stack_b);
    else
        return 0; // Invalid instruction encountered.
    return 1;
}

int main(int argc, char **argv)
{
    t_node *stack_a = NULL;
    t_node *stack_b = NULL;
    char *line;
    int i;

    if (argc < 2)
        return 0; // No arguments provided, do nothing.

    // Parse and add each argument to stack A.
    for (i = 1; i < argc; i++)
    {
        // Use ft_atoi to convert string to integer.
        // Note: ft_atoi (and ft_error_arg) should exit on errors (invalid numbers or overflows).
        int num = ft_atoi(argv[i]);
        t_node *new_node = create_node(num);
        if (!new_node)
            exit(EXIT_FAILURE);
        add_node(&stack_a, new_node);
    }
    // Check for duplicates in stack A.
    ft_errors_duplicates(stack_a);

    // Read and execute instructions from standard input.
    while ((line = get_next_line()) != NULL)
    {
        if (!execute_command(line, &stack_a, &stack_b))
        {
            write(2, "Error\n", 6);
            free(line);
            free_stack(&stack_a);
            free_stack(&stack_b);
            exit(EXIT_FAILURE);
        }
        free(line);
    }

    // After executing all commands, check if stack A is sorted and stack B is empty.
    if (is_sorted(stack_a) && !stack_b)
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);

    free_stack(&stack_a);
    free_stack(&stack_b);
    return 0;
}
