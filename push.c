/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 09:43:35 by alli              #+#    #+#             */
/*   Updated: 2024/01/29 14:25:48 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static  void push(t_stack **src, t_stack **dst)
{
	t_stack *push_node;
	
	if (!(*src))//we want to see if the src has anything in it
	{
        return ;   
    }
	push_node = *src;//take node from src and copy it into pushnode?
	*src = (*src)->next;//take src and make the next one in the src stack the top of the stack
	if (*src)//set the current as head of stack
		(*src)->prev = NULL;
	push_node->prev = NULL;//detach push_node from the stack (the prev)
	if (!*dst)//check if dst stack is empty
	{
		*dst = push_node;//then it will be the first element in the stack
		push_node->next = NULL;
	}
	else
	{ 
		push_node->next = *dst; 
		push_node->next->prev = push_node;
		*dst = push_node;
	} 
}

void pa(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_printf("pa\n");
}

void pb(t_stack **b, t_stack **a)
{
	push(a, b);
	ft_printf ("pb\n");
}