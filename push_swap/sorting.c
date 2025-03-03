#include "push_swap.h"

int get_size(t_node *stack)
{
    int count = 0;
    while (stack)
    {
        count++;
        stack = stack->next;
    }
    return count;
}

void sort(t_node **stack_a, t_node **stack_b)
{
    int size = get_size(*stack_a);
    int max_bits = 0;
    int max_val = size - 1;  // Assuming numbers are normalized.
    int i, j;
    int mask;

    // Determine the number of bits needed for the largest value.
    while ((max_val >> max_bits) != 0)
        max_bits++;

    // Process each bit from LSB to MSB.
    for (i = 0; i < max_bits; i++)
    {
        mask = 1 << i;
        // For each element in stack_a, use the mask to decide the operation.
        for (j = 0; j < size; j++)
        {
            if (((*stack_a)->value & mask) != 0)
                ra(stack_a);  // Bit is 1: rotate stack_a.
            else
                pb(stack_a, stack_b);  // Bit is 0: push element to stack_b.
        }
        // Bring all elements from stack_b back to stack_a.
        while (*stack_b)
            pa(stack_a, stack_b);
    }
}
