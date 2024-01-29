/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:09:04 by alli              #+#    #+#             */
/*   Updated: 2024/01/24 16:03:01 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static  void rev_rotate(t_stack **stack)
{
    t_stack *tail;
    
    if (!(*stack) || !(*stack)->next)
        return ;
    tail = find_last(*stack);//find the last node in the stack
    tail->prev->next = NULL; // tail->prev is the new last node and the next of that new last node will be null
    tail->next = *stack; //tail-> will point to the old beginning of the stack
    (*stack) = tail; //tail is now the new head of the stack
    tail->next->prev = tail;//the tail->next points to the old first element of the stack. and we will change the old head's previous to point to new head
    tail->prev = NULL; //finish off by making the new head null.
    
}

void rra(t_stack **a)
{
    rev_rotate(a);
    ft_printf("rra\n");
}

void rrb(t_stack **b)
{
    rev_rotate(b);
    ft_printf("rrb\n");
}

void rrr(t_stack **a, t_stack **b)
{
    rev_rotate(a);
    rev_rotate(b);
    ft_printf("rrr\n");
}