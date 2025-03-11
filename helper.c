

/* Error handling and printing */

#include "push_swap.h"


void print_stack(t_node *stack)
{
    if (!stack)
    {
        printf("Stack is EMPTY!\n");
        return;
    }
    printf("Stack: ");
    while (stack)
    {
        printf("%d -> ", stack->value);
        stack = stack->next;
    }
    printf("NULL\n");
}



int is_sorted(t_node *stack)
{
    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}



void ft_errors_write(void)
{
    write(2, "Error\n", 6);
    exit(EXIT_FAILURE);
}

int ft_isdigit(int c)
{
    return (c >= '0' && c <= '9');
}

void ft_error_arg(const char *str)
{
    int i = 0;
    
    if (str[i] == '-' || str[i] == '+')
        i++;
    
    if (!str[i])
        ft_errors_write();
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            ft_errors_write();
        i++;
    }
}

void ft_errors_duplicates(t_node *stack)
{
    t_node *current;
    t_node *runner;
    
    current = stack;
    while (current)
    {
        runner = current->next;
        while (runner)
        {
            if (runner->value == current->value)
                ft_errors_write();
            runner = runner->next;
        }
        current = current->next;
    }
}



