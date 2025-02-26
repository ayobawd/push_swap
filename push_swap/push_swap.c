/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-awa <ayal-awa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:01:25 by ayal-awa          #+#    #+#             */
/*   Updated: 2025/02/25 18:24:26 by ayal-awa         ###   ########.fr       */
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
        num = ft_atoi(argv[i]);
        add_node(&stack_a, create_node(num));
        i++;
    }

  
    if (is_sorted(stack_a))
        return (0); 
    sort(&stack_a);

    
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}
