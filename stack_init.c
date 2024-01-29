/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:28:05 by alli              #+#    #+#             */
/*   Updated: 2024/01/29 13:03:30 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *str)
{
	int		sign;
	long	total;
	int		i;

	sign = 1;
	total = 0;
	i = 0;
	while (str[i] == '\n' || str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
			|| str[i] =='\f' || str[i] == '\r')
			i++;
	if ((str[i] == '+' || str[i] == '-') && str[i])
	{
		if (str[i] == '-')
			sign *= -1;
        i++;
	}
	while (ft_isdigit(str[i]) && str[i])
	{
		total = total * 10 + (str[i++] - '0');
	}
	return (total * sign);
}

static void	append_node(t_stack **stack, int n)
{
	t_stack	*node; //pointer node to store a pointer to new node
	t_stack	*last_node;	//pointer to store pointer to current stack of the last node
	if (!stack)//check if the stack is viable or not
		return ;
	node = malloc(sizeof(t_stack)); // allocate memory for the new node
	if (!node)
		return ;
	node->next = NULL; //it will be the last node in the list
	node->nbr = n;//also asign it the value
	if (!(*stack)) 
	{	//now check to see where it can be placed in the stack, if it's the first element or not
		*stack = node;
		node->prev = NULL; //1st element then the -> is null
	}
	else
	{
		last_node = find_last(*stack); //find the last node
		last_node->next = node;//append node to last node.
		node->prev = last_node; //link node to previous node.
	}
}

void init_stack_a(t_stack **stack, char **argv, int split)
{
    long    n;
	int		i;
	i = 0;

    if (!argv[i])
        free_error(stack, argv, split);
    while (argv[i])
    {
        if (check_syntax(argv[i]))
            free_error(stack, argv, split);
        n = ft_atol(argv[i]);  //converting (char) to long integer
        if (n > INT_MAX || n < INT_MIN)//check if number > max or if number is < min
            free_error(stack, argv, split);;
        if (check_dup(*stack, n))
            free_error(stack, argv, split);
        append_node(stack, (int)n); //finally append the node (add it to the stack!!!) repeat
        i++;
    }
    if (split)
        ft_free_split(argv);
}
