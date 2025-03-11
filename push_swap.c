#include "push_swap.h"

void sort(t_node **stack_a, t_node **stack_b)
{
    int size = get_size(*stack_a);

    if (size <= 5)
        sort_small(stack_a, stack_b);
    else
        sort_large(stack_a, stack_b);
}

int main(int argc, char **argv)
{
    t_node *stack_a = NULL;
    t_node *stack_b = NULL;
    int i;
    int num;

    if (argc < 2)
        return (0);

    i = 1;
    while (i < argc)
    {
        ft_error_arg(argv[i]);
        num = ft_atoi(argv[i]);
        add_node(&stack_a, create_node(num));
        i++;
    }

    ft_errors_duplicates(stack_a);
    if (is_sorted(stack_a))
        return (0);
    sort(&stack_a, &stack_b);
    print_stack(stack_a);
    print_stack(stack_b);
    /* According to project requirements, do not print extra output. */
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}
