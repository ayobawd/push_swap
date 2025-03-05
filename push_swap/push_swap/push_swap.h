/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-awa <ayal-awa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:52:28 by ayal-awa          #+#    #+#             */
/*   Updated: 2025/03/03 23:54:59 by ayal-awa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

t_node				*create_node(int value);
void				add_node(t_node **stack, t_node *new_node);
void				free_stack(t_node **stack);

int					ft_atoi(const char *str);
int					is_sorted(t_node *stack);
void sort(t_node **stack_a, t_node **stack_b);
void print_stack(t_node *stack);
void ft_errors_duplicates(t_node *stack);
void ft_error_arg(const char *str);
int get_size(t_node *stack);

void				sa(t_node **stack_a);
void				sb(t_node **stack_b);
void				ss(t_node **stack_a, t_node **stack_b);
void				pa(t_node **stack_a, t_node **stack_b);
void				pb(t_node **stack_a, t_node **stack_b);
void				ra(t_node **stack);
void				rb(t_node **stack);
void				rr(t_node **stack_a, t_node **stack_b);
void				rra(t_node **stack);
void				rrb(t_node **stack);
void				rrr(t_node **stack_a, t_node **stack_b);

#endif
