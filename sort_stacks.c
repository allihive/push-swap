/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:56:49 by alli              #+#    #+#             */
/*   Updated: 2024/01/29 10:41:46 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void current_pos(t_stack *stack)
{
    int i;
	int	median;
	
	if (!stack)
		return ;
	i = 0;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->position = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	bring_to_top(t_stack **stack, t_stack *top_node, char stack_name)//some sort of infinite loop here
{
	// ft_printf("btt function stacks before");//del
	// ft_printf("stack b = ");//del
	// print_stack(*stack); //del
	// // ft_printf("stack a = ");//del
	// // print_stack(*stack); //del
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack); //ra(stack)
			else
				rra(stack); //rra(stack)
		}
		if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

static void	min_to_top(t_stack **stack)
{
	int	min_num;
	
	min_num = find_min(*stack)->nbr;
	while ((*stack)->nbr != min_num)
	{
		if (find_min(*stack)->above_median)
			ra(stack);//ra(stack);
		else
			rra(stack);//rra(stack);
	}
}

void sort_stacks(t_stack **a, t_stack **b)
{
	int	len;
	
	len = stack_len(*a);
	if (len-- > 3 && !stack_sorted(*a))
		pb(b, a);
	if (len-- > 3 && !stack_sorted(*a))
		pb(b, a);
	while (len-- > 3 && !stack_sorted(*a))
    {
    	prep_a_stack(*a, *b);
		move_a_to_b(a, b);
    }
    //ft_printf("before sort_ 3 stack_a = "); //del
	//print_stack(*a); //del
    sort_three(a);
    //ft_printf("after sort_ 3 stack_a = "); //del
	//print_stack(*a); //del
    while (*b)
    {
        prep_b_stack(*a, *b);
		move_b_to_a(a, b);
    }
	current_pos(*a);
	min_to_top(a);
	//print_stack(*a);//del
}
