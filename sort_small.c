#include "push_swap.h"


void sort_small(t_node **stack_a, t_node **stack_b)
{
    int size = get_size(*stack_a);

    if (size == 2)
    {
        if (!is_sorted(*stack_a))
            sa(stack_a);
    }
    else if (size == 3)
    {
        int a = (*stack_a)->value;
        int b = (*stack_a)->next->value;
        int c = (*stack_a)->next->next->value;
        if (a > b && a < c)
            sa(stack_a);
        else if (a > b && b > c)
        {
            sa(stack_a);
            rra(stack_a);
        }
        else if (a > c && b < c)
            ra(stack_a);
        else if (a < b && a > c)
            rra(stack_a);
        else if (a < b && b > c)
        {
            sa(stack_a);
            ra(stack_a);
        }
    }
    else if (size > 3 && size <= 5)
    {
        while (get_size(*stack_a) > 3)
        {
            int min = INT_MAX;
            int pos = 0;
            int min_pos = 0;
            t_node *tmp = *stack_a;
            while (tmp)
            {
                if (tmp->value < min)
                {
                    min = tmp->value;
                    min_pos = pos;
                }
                pos++;
                tmp = tmp->next;
            }
            if (min_pos <= get_size(*stack_a) / 2)
            {
                for (int i = 0; i < min_pos; i++)
                    ra(stack_a);
            }
            else
            {
                int count = get_size(*stack_a) - min_pos;
                for (int i = 0; i < count; i++)
                    rra(stack_a);
            }
            pb(stack_a, stack_b);
        }
        /* Now sort the remaining 3 elements */
        if (!is_sorted(*stack_a))
            sort_small(stack_a, stack_b);
        while (*stack_b)
            pa(stack_a, stack_b);
    }
}
