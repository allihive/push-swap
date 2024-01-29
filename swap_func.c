/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:52:32 by alli              #+#    #+#             */
/*   Updated: 2024/01/24 16:02:24 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void swap(t_stack **head)
{
    if (!(*head) || !(*head)->next)
        return ;
    *head = (*head)->next;
    (*head)->prev->prev = *head;
    (*head)->prev->next = (*head)->next;
    if ((*head)->next)
        (*head)->next->prev = (*head)->prev;
    (*head)->next = (*head)->prev;
    (*head)->prev = NULL;
}

void    sa(t_stack **a)
{
    swap(a);
    ft_printf("sa\n");
}

void    sb(t_stack **b)
{
    swap(b);
    ft_printf("sb\n");
}

void    ss(t_stack **a, t_stack **b)
{
    swap(a);
    swap (b);
    ft_printf ("ss\n");
}