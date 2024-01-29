/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 08:53:10 by alli              #+#    #+#             */
/*   Updated: 2024/01/29 13:00:23 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_syntax(char *a)
{
    if (!(*a == '+'|| *a == '-'
			|| (*a >= '0' && *a <= '9'))) //Check if the first character of the input string does not contain a sign or a digit
            return (1);
	if ((*a == '+' || *a == '-') && !(a[1] >= '0' && a[1] <= '9'))
            return (1);
	while(*++a)
		if (!(*a >= '0' && *a <= '9'))
            return (1);
	return (0);
}

int    check_dup(t_stack *a, int n)
{
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void    free_stack(t_stack **stack)
{
    t_stack *tmp;
    t_stack *current;
    
    tmp = NULL;
    if (!*stack)
        return ;
    current = *stack;
    while (current)
    {
        tmp = current->next;
        free(current);
        current = tmp;
    }
    *stack = NULL;
}

void free_error(t_stack **a, char **argv, int split)
{
	free_stack(a);
    if (split)
        ft_free_split(argv);
    write(2, "Error\n", 6);
	exit(1) ;
}