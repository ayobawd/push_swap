#include "push_swap.h"
#include <limits.h>


void finalize_stack_a(t_node **a)
{
    t_node  *smallest;
    int     size;
    int     pos = 0;
    int     i;
    t_node  *temp;

    if (!a || !*a)
        return;
    smallest = find_smallest(*a);
    size = get_size(*a);
    temp = *a;
    while (temp != smallest)
    {
        pos++;
        temp = temp->next;
    }
    if (pos <= size / 2)
    {
        for (i = 0; i < pos; i++)
            ra(a);
    }
    else
    {
        for (i = 0; i < size - pos; i++)
            rra(a);
    }
}


/*
 * Helper: Finds the insertion position in B for value.
 * If value is greater than the max in B or less than the min,
 * the correct position is where the maximum element is (so that when pushed,
 * the new element is placed “above” the maximum).
 * Otherwise, it searches for the first spot where the current element fits.
 */
static int	get_insertion_index(t_node *stack_b, int value)
{
	int		insert_index = 0;
	int		max = INT_MIN;
	int		min = INT_MAX;
	int		pos_max = 0;
	int		j = 0;
	t_node	*temp;

	if (!stack_b)
		return (0);
	
	/* Find max and min in B */
	temp = stack_b;
	while (temp)
	{
		if (temp->value > max)
		{
			max = temp->value;
			pos_max = j;
		}
		if (temp->value < min)
			min = temp->value;
		temp = temp->next;
		j++;
	}
	/* If value is a new extreme, choose the position of max */
	if (value > max || value < min)
		insert_index = pos_max;
	else
	{
		/* Otherwise, find the spot where B[i] > value and B[i+1] < value */
		int found = 0;
		int pos = 0;
		t_node *iter = stack_b;
		while (iter && iter->next)
		{
			if (iter->value > value && iter->next->value < value)
			{
				insert_index = pos + 1;
				found = 1;
				break;
			}
			iter = iter->next;
			pos++;
		}
		if (!found)
			insert_index = 0;
	}
	return (insert_index);
}


/*
 * Calculate the cost (number of rotations) needed to bring a given position
 * to the top of a stack of size 'size'. It chooses the minimal rotations
 * (either forward or reverse).
 */
static int	calc_cost(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	else
		return (size - pos);
}

/*
 * Revised sort_large using the Turk Algorithm approach.
 * This version does not rely on extra indexing fields.
 */
void sort_large(t_node **stack_a, t_node **stack_b)
{
	int	size_a;
	int	size_b;
	int	best_cost;
	int	best_index;
	int	index;
	t_node	*current;

	/* Step 1: Push the first two elements from A to B */
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);

	/* Step 2: While more than 3 elements remain in A, choose the best candidate to push */
	while ((size_a = get_size(*stack_a)) > 3)
	{
		best_cost = INT_MAX;
		best_index = 0;
		index = 0;
		current = *stack_a;
		while (current)
		{
			int	cost_a;
			int	cost_b;
			int	total_cost;
			int	insert_index;

			/* Cost to bring current element to top of A */
			cost_a = calc_cost(index, size_a);
			
			/* Calculate cost in B: determine insertion position for current->value */
			size_b = get_size(*stack_b);
			insert_index = get_insertion_index(*stack_b, current->value);
			cost_b = calc_cost(insert_index, size_b);

			/* If rotations in both stacks can be merged (both forward or both reverse),
			 * total cost is the maximum of cost_a and cost_b; otherwise, sum them.
			 */
			if ((index <= size_a / 2 && insert_index <= size_b / 2)
				|| (index > size_a / 2 && insert_index > size_b / 2))
				total_cost = (cost_a > cost_b ? cost_a : cost_b);
			else
				total_cost = cost_a + cost_b;

			if (total_cost < best_cost)
			{
				best_cost = total_cost;
				best_index = index;
			}
			index++;
			current = current->next;
		}
		/* Rotate A to bring the chosen element (at best_index) to top */
		if (best_index <= size_a / 2)
		{
			for (int i = 0; i < best_index; i++)
				ra(stack_a);
		}
		else
		{
			for (int i = 0; i < size_a - best_index; i++)
				rra(stack_a);
		}
		/* Now, determine where to insert it in B */
		size_b = get_size(*stack_b);
		int insert_index = get_insertion_index(*stack_b, (*stack_a)->value);
		if (insert_index <= size_b / 2)
		{
			for (int i = 0; i < insert_index; i++)
				rb(stack_b);
		}
		else
		{
			for (int i = 0; i < size_b - insert_index; i++)
				rrb(stack_b);
		}
		/* Finally, push the candidate from A to B */
		pb(stack_a, stack_b);
	}
	/* Step 3: Sort the remaining 3 elements in A (using your existing sort_small) */
	sort_small(stack_a, stack_b);
	/* Step 4: Push back all elements from B to A */
	while (get_size(*stack_b) > 0)
		pa(stack_a, stack_b);
	/* Step 5: Final arrangement: rotate A until the smallest element is at the top */
	finalize_stack_a(stack_a);
}