/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_stack_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:22:15 by alli              #+#    #+#             */
/*   Updated: 2024/01/29 10:47:15 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	target_node_b(t_stack *b, t_stack *a)
{
	t_stack *current_a;
	t_stack	*target_node;
	long	best_match;
    
	while (b)
	{
		best_match = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->nbr > b->nbr && current_a->nbr < best_match)
			{
				best_match = current_a->nbr;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	prep_b_stack(t_stack *a, t_stack *b)
{
	current_pos(b);
	current_pos(a);
	target_node_b(b, a);
}

void	move_b_to_a(t_stack **a, t_stack **b)
{
	bring_to_top(a, (*b)->target_node, 'a');
	pa(a, b);
}