/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-awa <ayal-awa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:28:05 by ayal-awa          #+#    #+#             */
/*   Updated: 2025/03/03 23:55:43 by ayal-awa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *create_node(int value)
{
    t_node *new_node = malloc(sizeof(t_node));
    if (!new_node)
        return (NULL);
    new_node->value = value;
    new_node->next = NULL;
    return (new_node);
}

void add_node(t_node **stack, t_node *new_node)
{
    t_node *temp;

    if (!*stack)
    {
        *stack = new_node;
        return;
    }
    temp = *stack;
    while (temp->next)
        temp = temp->next;
    temp->next = new_node;
}

void free_stack(t_node **stack)
{
    t_node *tmp;
    while (*stack)
    {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
}

int ft_atoi(const char *str)
{
    int sign = 1;
    long result = 0;

    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        str++;
    }
    return ((int)(result * sign));
}

int is_sorted(t_node *stack)
{
    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}
