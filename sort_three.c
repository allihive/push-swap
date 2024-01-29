/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:28:30 by alli              #+#    #+#             */
/*   Updated: 2024/01/24 15:59:52 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_stack **a)
{
    t_stack *biggest_node;

    biggest_node = find_max(*a);
    // ft_printf("biggest_node = %d\n", biggest_node->nbr);
    // ft_printf("a->nbr = %d\n", (*a)->nbr);
    if ((*a) == biggest_node)
        ra(a);//ra(a);
    if ((*a)->next == biggest_node)
        rra(a);//rra(a, false);
    if ((*a)->nbr > (*a)->next->nbr)
        sa(a);//sa(a, false);
}

//for testing, delete it before submitting
/*void    ftt_lstiter(t_stack *lst)
{
    while (lst)
   {
        printf("%d\n", lst->nbr);
        lst = lst->next;
    }
}

int main()
{
    t_stack    *lst;
    t_stack    first;
    t_stack    second;
    t_stack    third;
    //t_stack    fourth;

    first.nbr = 2;
    second.nbr = -33;
    third.nbr = 45;
    //fourth.nbr = 1;

    first.prev = NULL;
    first.next = &second;
    second.prev = &first;
    second.next = &third;
    third.prev = &second;
    third.next = NULL;
   // fourth.prev = &third;
   // fourth.next = NULL;

    lst = &first;
    
    printf("before sort 3");
    ftt_lstiter(lst);
    printf("after sort 3");
    sort_three(lst);
    
}*/
