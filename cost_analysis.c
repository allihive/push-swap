/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_analysis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:38:25 by alli              #+#    #+#             */
/*   Updated: 2024/01/29 10:44:26 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_cheapest(t_stack *stack)
{
	long	cheapest;
	t_stack *cheapest_node;

	if (!stack)
		return ;
	cheapest = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest)
		{
			cheapest = stack->push_cost;
			cheapest_node = stack;
		}
        stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

t_stack	*get_cheapest(t_stack *stack) //Define a function that searches for the cheapest node, that is set by bool
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node && *b != cheapest_node->target_node)
		rr(a, b);
	current_pos(*a);
	current_pos(*b);
}

void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node && *b != cheapest_node->target_node)
		rrr(a, b);
	current_pos(*a);
	current_pos(*b);
}