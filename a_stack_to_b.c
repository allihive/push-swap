/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_stack_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:18:52 by alli              #+#    #+#             */
/*   Updated: 2024/01/29 10:44:32 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void calc_cost(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;
	
	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->position; //if it's 6th on the list, then if we were to bring it to the top, would have to rotate 6 times to the top
		if (!a->above_median)//check if above median is true or false
			a->push_cost = len_a - (a->position);//update push_cost_a = stack_len - index (the length - where it is will show how much it would need to rotate)
		if (a->target_node->above_median)//now check if a node is above the median or not.
			a->push_cost += a->target_node->position;//if so update a node push cost sum of (current index + target node index)
		else
			a->push_cost += len_b - (a->target_node->position); //update a node push cost and the sum of (current index + stacklen_b - b_index)
		a = a->next;
	}
}

void target_node_a(t_stack *a, t_stack *b)
{ 
	t_stack	*current_b; //this will iterate through and store the value of where b is. B only points to the start
	t_stack	*target_node;
	long	best_match;

	while (a)
	{
		best_match = LONG_MIN;
		current_b = b; //restarts b again to iterate through all the numbers
		while (current_b)
		{
			if (current_b->nbr < a->nbr && current_b->nbr > best_match) //checks to see if b < a && b > best match
			{
				best_match = current_b->nbr; //then we store b number into best match
				target_node = current_b; //that will become the new target node for b
			}
			current_b = current_b->next; //move to the next to see if there is a better b number in the stack
		}
		if (best_match == LONG_MIN) //I would check this if it doens't work? could be if best_match == LONG_MIN
			a->target_node = find_max(b);
		else 
			a->target_node = target_node;
		a = a->next;
	}
}
void    prep_a_stack(t_stack *a, t_stack *b)
{
    current_pos(a);
    current_pos(b);
    target_node_a(a, b);
    calc_cost(a, b);
    push_cheapest(a);
}
void	move_a_to_b(t_stack **a, t_stack **b)// I should check this today
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	if(!(cheapest_node->above_median) && !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	bring_to_top(a, cheapest_node, 'a');
	bring_to_top(b, cheapest_node->target_node, 'b');
    pb(b, a);
}