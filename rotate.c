/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:14:43 by alli              #+#    #+#             */
/*   Updated: 2024/01/24 16:02:41 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static  void rotate(t_stack **stack)
{
    t_stack *tail;
    if (!*stack || !(*stack)->next)
        return ;
    tail = find_last(*stack);
    tail->next = *stack;
    *stack = (*stack)->next;
    (*stack)->prev->prev = tail;
    (*stack)->prev->next = NULL;
    (*stack)->prev = NULL;
}

void ra(t_stack **a)
{
    rotate(a);
    ft_printf("ra\n");
}

void rb(t_stack **b)
{
    rotate(b);
        ft_printf("rb\n");
}

void rr(t_stack **a, t_stack **b)
{
    rotate(a);
    rotate(b);
        ft_printf("rr\n");
}