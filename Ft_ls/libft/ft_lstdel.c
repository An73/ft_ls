/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 02:41:23 by dkotenko          #+#    #+#             */
/*   Updated: 2017/11/11 04:17:22 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*newlist;
	t_list	*buff;

	if (alst != NULL)
	{
		newlist = *alst;
		while (newlist != NULL)
		{
			buff = newlist->next;
			ft_lstdelone(&newlist, del);
			newlist = buff;
		}
		*alst = NULL;
	}
}
