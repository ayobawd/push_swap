#include "push_swap.h"

void sa(t_node **stack_a)
{
    t_node *first;
    t_node *second;

    if (!stack_a || !*stack_a || !(*stack_a)->next)
        return;
    first = *stack_a;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack_a = second;
    write(1, "sa\n", 3);
}

void sb(t_node **stack_b)
{
    t_node *first;
    t_node *second;

    if (!stack_b || !*stack_b || !(*stack_b)->next)
        return;
    first = *stack_b;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack_b = second;
    write(1, "sb\n", 3);
}

void ss(t_node **stack_a, t_node **stack_b)
{
    sa(stack_a);
    sb(stack_b);
}

void pa(t_node **stack_a, t_node **stack_b)
{
    t_node *tmp;

    if (!stack_b || !*stack_b)
        return;
    tmp = *stack_b;
    *stack_b = tmp->next;
    tmp->next = *stack_a;
    *stack_a = tmp;
    write(1, "pa\n", 3);
}

void pb(t_node **stack_a, t_node **stack_b)
{
    t_node *tmp;

    if (!stack_a || !*stack_a)
        return;
    tmp = *stack_a;
    *stack_a = tmp->next;
    tmp->next = *stack_b;
    *stack_b = tmp;
    write(1, "pb\n", 3);
}

void ra(t_node **stack)
{
    t_node *first;
    t_node *last;

    if (!stack || !*stack || !(*stack)->next)
        return;
    first = *stack;
    *stack = first->next;
    first->next = NULL;
    last = *stack;
    while (last->next)
        last = last->next;
    last->next = first;
    write(1, "ra\n", 3);
}

void rb(t_node **stack)
{
    t_node *first;
    t_node *last;

    if (!stack || !*stack || !(*stack)->next)
        return;
    first = *stack;
    *stack = first->next;
    first->next = NULL;
    last = *stack;
    while (last->next)
        last = last->next;
    last->next = first;
    write(1, "rb\n", 3);
}

void rr(t_node **stack_a, t_node **stack_b)
{
    ra(stack_a);
    rb(stack_b);
}

void rra(t_node **stack)
{
    t_node *prev;
    t_node *last;

    if (!stack || !*stack || !(*stack)->next)
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
    write(1, "rra\n", 4);
}

void rrb(t_node **stack)
{
    t_node *prev;
    t_node *last;

    if (!stack || !*stack || !(*stack)->next)
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
    write(1, "rrb\n", 4);
}

void rrr(t_node **stack_a, t_node **stack_b)
{
    rra(stack_a);
    rrb(stack_b);
}
