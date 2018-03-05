/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 12:46:05 by dkotenko          #+#    #+#             */
/*   Updated: 2018/03/05 12:46:07 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	recursion(char *direct, t_flag *flag, t_lsave *head)
{
	t_lsave	*current;

	current = head;
	while (current != NULL)
	{
		if (ft_strcmp(current->name, ".") == 0 || ft_strcmp(current->name, "..") == 0)
			;
		else if (current->type == 4 && current->name[0] != '.')
		{
			write(1, "\n", 1);
			big_r(putb(direct, current->name), flag);
		}
		current = current->next;
	}
}

void	big_r(char *direct, t_flag *flag)
{
	t_lsave *head;
	head = printer(direct, flag);
	if (head == NULL)
		return ;
	recursion(direct, flag, head);
}