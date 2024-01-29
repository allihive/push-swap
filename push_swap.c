/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:10:41 by alli              #+#    #+#             */
/*   Updated: 2024/01/29 13:27:58 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_stack(t_stack *stack) //do not include in the final
{
    t_stack *current = stack;

    while (current != NULL)
    {
        printf("%d ", current->nbr);
        current = current->next;
    }
    printf("\n");
}

/*static int	count_words(const char *s, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	if (s[i] == '0')
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			words++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (words);
}*/

void    ft_free_split(char **result)
{
    int    i;

    i = 0;
    while (result[i])
    {
        free(result[i]);
        result[i] = NULL;
        i++;
    }
    free(result);
}

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

	a = NULL;
	b = NULL;
    if (argc == 1) 
        return (1);
    if (argc == 2) // && numbers > 1
        init_stack_a(&a, ft_split(argv[1], ' '), 1);
    if (argc > 2)
        init_stack_a(&a, argv + 1, 0);
    if (!stack_sorted(a))//check to see if the stack is sorted
    {
        if (stack_len(a) == 2)
            sa(&a);
        else if (stack_len(a) == 3)
            sort_three(&a);
        else
            sort_stacks(&a, &b);
    }
   free_stack(&a);
}
