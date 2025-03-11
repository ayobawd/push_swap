#include "push_swap.h"
#include <stdlib.h>

t_node *create_node(int value)
{
    t_node *new_node = malloc(sizeof(t_node));
    if (!new_node)
        return (NULL);
    new_node->value = value;
    new_node->index = 0;
    new_node->next = NULL;
    return (new_node);
}

void add_node(t_node **stack, t_node *new_node)
{
    t_node *temp;

    if (!*stack)
    {
        *stack = new_node;
        return;
    }
    temp = *stack;
    while (temp->next)
        temp = temp->next;
    temp->next = new_node;
}

void free_stack(t_node **stack)
{
    t_node *tmp;
    while (*stack)
    {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
}

int ft_atoi(const char *str)
{
    int sign = 1;
    long result = 0;

    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        if (result * sign > INT_MAX || result * sign < INT_MIN)
            ft_errors_write();  /* Exit on integer overflow */
        str++;
    }
    return ((int)(result * sign));
}
int	get_size(t_node *stack)
{
	int	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}
t_node *find_smallest(t_node *stack)
{
    t_node *smallest_node = NULL;
    long smallest = LONG_MAX;
    while (stack)
    {
        if (stack->value < smallest)
        {
            smallest = stack->value;
            smallest_node = stack;
        }
        stack = stack->next;
    }
    return smallest_node;
}
