#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_node
{
    int             value;
    long            index;
    struct s_node   *next;

   
}   t_node;

/* Utility functions */
t_node  *create_node(int value);
void    add_node(t_node **stack, t_node *new_node);
void    free_stack(t_node **stack);
int     ft_atoi(const char *str);
int     is_sorted(t_node *stack);
int     get_size(t_node *stack);
void    ft_error_arg(const char *str);
void    ft_errors_write(void);
void    ft_errors_duplicates(t_node *stack);
void print_stack(t_node *stack);
t_node *find_smallest(t_node *stack);

/* Stack operations */
void    sa(t_node **stack_a);
void    sb(t_node **stack_b);
void    ss(t_node **stack_a, t_node **stack_b);
void    pa(t_node **stack_a, t_node **stack_b);
void    pb(t_node **stack_a, t_node **stack_b);
void    ra(t_node **stack);
void    rb(t_node **stack);
void    rr(t_node **stack_a, t_node **stack_b);
void    rra(t_node **stack);
void    rrb(t_node **stack);
void    rrr(t_node **stack_a, t_node **stack_b);

/* Sorting functions */
void    sort(t_node **stack_a, t_node **stack_b);
void    sort_small(t_node **stack_a, t_node **stack_b);
void sort_large(t_node **stack_a, t_node **stack_b);
void    assign_indexes(t_node **stack_a);

#endif
