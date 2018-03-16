/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 14:02:09 by dkotenko          #+#    #+#             */
/*   Updated: 2018/03/16 14:02:10 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_lst(t_lsave **head)
{
	t_lsave *current;
	t_lsave	*buff;

	current = *head;
	while (current != NULL)
	{
		buff = current->next;
		free(current->name);
		free(current);
		current = buff;
	}
	*head = NULL;
}
