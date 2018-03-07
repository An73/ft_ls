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
	t_lsave *head;

	head = new_lsave(direct, flag);
	current = head;

	sort_name(head);
	if (flag->fl_r == 1)
		sort_recur(head);
	if (flag->fl_r == 1 && flag->fl_t == 1)
		sort_time_recurs(head);
	else if (flag->fl_t == 1)
		sort_time(head);

	while (current != NULL)
	{
		if (ft_strcmp(current->name, ".") == 0 || ft_strcmp(current->name, "..") == 0)
			;
		else if (current->type == 4 && (flag->fl_a == 1 || current->name[0] != '.'))
		{
			write(1, "\n", 1);
			big_r(putb(direct, current->name), flag);
		}
		current = current->next;
	}
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