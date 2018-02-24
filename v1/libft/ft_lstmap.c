/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:41:57 by dkotenko          #+#    #+#             */
/*   Updated: 2017/11/12 15:54:24 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*new_lst;

	new_lst = (t_list *)malloc(sizeof(t_list));
	if (!new_lst || !lst)
	{
		free(new_lst);
		return (NULL);
	}
	new_lst = f(lst);
	head = new_lst;
	lst = lst->next;
	while (lst != NULL)
	{
		new_lst->next = f(lst);
		if (!new_lst->next)
		{
			free(new_lst->next);
			return (NULL);
		}
		new_lst = new_lst->next;
		lst = lst->next;
	}
	new_lst = NULL;
	return (head);
}
