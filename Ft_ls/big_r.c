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

void	recursion(char *direct, t_flag *flag)
{
	t_lsave	*current;
	t_lsave	*head;
	char	*fr;

	head = new_lsave(direct, flag);
	current = head;
	sorting(&head, flag);
	while (current != NULL)
	{
		if (ft_strcmp(current->name, ".") == 0 ||\
			ft_strcmp(current->name, "..") == 0)
			;
		else if (current->type == 4 && (flag->fl_a == 1 ||\
			current->name[0] != '.'))
		{
			write(1, "\n", 1);
			fr = putb(direct, current->name);
			big_r(fr, flag);
			free(fr);
		}
		current = current->next;
	}
	free_lst(&head);
}

int		big_r(char *direct, t_flag *flag)
{
	int check;

	check = printer(direct, flag);
	if (check == 0)
		return (check);
	recursion(direct, flag);
	return (check);
}
