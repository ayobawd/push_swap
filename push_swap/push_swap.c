/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-awa <ayal-awa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:01:25 by ayal-awa          #+#    #+#             */
/*   Updated: 2025/03/03 23:55:15 by ayal-awa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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
    sort(&stack_a,&stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
    
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}
