/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:34:00 by alli              #+#    #+#             */
/*   Updated: 2024/01/24 11:07:04 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *find_last(t_stack *stack)
{
	while (stack != '\0')
	{
		if (stack->next == '\0')
			return (stack);
		stack = stack->next;
	}
	return (stack);
}
int stack_len(t_stack *stack)
{
    int count;
    
    if (!stack)
        return (0);
    count = 0;
    while (stack)
    {
        stack = stack->next;
        count++;
    }
    return (count);
}

bool stack_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}
/*int stack_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}*/

t_stack *find_min(t_stack *stack)
{
    t_stack    *min_node;
    long        min;

    if (!(stack))
        return (NULL);
    min = LONG_MAX;
    while (stack)
    {
        if (stack->nbr < min)
		{
			min = stack->nbr;
			min_node = stack;
		}
        stack = stack->next;
    }
    return (min_node);
}

t_stack *find_max(t_stack *stack)
{
    t_stack    *max_node;
    long        max;

    if (!(stack))
        return (NULL);
    max = LONG_MIN;
    while (stack)
    {
        if (stack->nbr > max)
		{
			max = stack->nbr;
			max_node = stack;
		}
        stack = stack->next;
    }
    return (max_node);
}
