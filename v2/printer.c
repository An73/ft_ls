/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 14:17:29 by dkotenko          #+#    #+#             */
/*   Updated: 2018/03/04 14:17:31 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*putb(char *direct, char *d_name)
{
	direct = ft_strjoin(direct, "/");
	direct = ft_strjoin(direct, d_name);
	//ft_printf("%s\n", direct);
	return (direct);
}

int		no_sort_flag(char *direct, t_pre pre, t_flag *flag)
{
	t_lsave *head;
	t_lsave	*current;

	head = new_lsave(direct, flag);
	if (head == NULL)
		return (0);

	sort_name(head);
	if (flag->fl_r == 1)
		sort_recur(head);
	if (flag->fl_r == 1 && flag->fl_t == 1)
		sort_time_recurs(head);
	else if (flag->fl_t == 1)
		sort_time(head);

	current = head;
	if (flag->no_dir != 1)
		ft_printf("%s:\n", direct);
	flag->no_dir = 0;
	if (flag->fl_l == 1 && pre.size != 0)
		ft_printf("total %d\n", pre.block);
	while (current != NULL)
	{
		if (flag->fl_l == 1 && (flag->fl_a == 1 || current->name[0] != '.'))
		{
			if (current->type == 10)
				print_l_link(putb(direct, current->name), current->name, pre);
			else
				print_l(putb(direct, current->name), current->name, pre);
		}
		else if (flag->fl_a == 1 || current->name[0] != '.')
			ft_printf("%s\n", current->name);
		current = current->next;
	}
	return (1);
}

int	 printer(char *direct, t_flag *flag)
{
	t_pre pre;
	int check;

	pre = pre_write(direct, flag);
	check = no_sort_flag(direct, pre, flag);
	/*if (list == NULL)
		return (NULL);*/
	return (check);
}
