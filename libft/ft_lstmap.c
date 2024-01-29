/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:21:23 by alli              #+#    #+#             */
/*   Updated: 2024/01/12 15:25:08 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*add;
	void	*func;

	if (!lst || !f || !del)
		return (NULL);
	head = NULL;
	while (lst)
	{
		func = (f(lst->content));
		add = ft_lstnew(func);
		if (!add)
		{
			del(func);
			ft_lstclear(&head, (del));
			return (head);
		}
		ft_lstadd_back(&head, add);
		lst = lst->next;
	}
	return (head);
}
