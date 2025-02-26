#include "push_swap.h"
// Helper function to get the number of elements in a stack.
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
    int i, j, num;

    // Calculate how many bits are needed for the largest number (assumes numbers are normalized)
    while (((size - 1) >> max_bits) != 0)
        max_bits++;

    // Process each bit position from least significant to most significant.
    for (i = 0; i < max_bits; i++)
    {
        j = 0;
        // Process every element in stack_a
        while (j < size)
        {
            num = (*stack_a)->value;
            // Check the i-th bit of num:
            // If the bit is 1, rotate the element to the bottom of stack_a.
            // Otherwise, push it to stack_b.
            if (((num >> i) & 1) == 1)
                ra(stack_a);
            else
                pb(stack_a, stack_b);
            j++;
        }
        // Now, push all elements from stack_b back to stack_a.
        while (*stack_b)
            pa(stack_a, stack_b);
    }
}
