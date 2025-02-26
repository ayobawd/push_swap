#include "push_swap.h"

void sort(t_node **stack)
{
    int a = (*stack)->value;
    int b = (*stack)->next->value;
    int c = (*stack)->next->next->value;

    if (a > b && a > c)
        ra(stack);   
    if (b > a && b > c)
        rra(stack);  

    a = (*stack)->value;
    b = (*stack)->next->value;

    if (a > b)
        sa(stack);   
}