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
	char	*fr;
	char	*new_direct;

	new_direct = ft_strjoin(direct, "/");

	fr = new_direct;
	new_direct = ft_strjoin(new_direct, d_name);
	free(fr);
	//ft_printf("%s\n", direct);
	return (new_direct);
}

int		no_sort_flag(char *direct, t_pre pre, t_flag *flag)
{
	t_lsave *head;
	t_lsave	*current;
	char	*fr;

	head = new_lsave(direct, flag);
	if (head == NULL)
	{
		/*if (flag->fl_R != 1)
			ft_printf("ls: %s: No such file or directory\n", direct);*/
		return (0);
	}

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
	if (flag->fl_l == 1 && pre.size != -1)
		ft_printf("total %d\n", pre.block);
	while (current != NULL)
	{
		if (flag->fl_l == 1 && (flag->fl_a == 1 || current->name[0] != '.'))
		{
			if (current->type == 10)
			{
				fr = putb(direct, current->name);
				print_l_link(fr, current->name, pre);
				free(fr);
			}
			else
			{
				fr = putb(direct, current->name);
				print_l(putb(direct, current->name), current->name, pre);
				free(fr);
			}
		}
		else if (flag->fl_a == 1 || current->name[0] != '.')
			ft_printf("%s\n", current->name);
		current = current->next;
	}
	free_lst(&head);
	return (1);
}

int	 printer(char *direct, t_flag *flag)
{
	t_pre pre;
	int check;

	pre = pre_write(direct, flag);
	check = no_sort_flag(direct, pre, flag);
	//system("leaks ft_ls");
	/*if (list == NULL)
		return (NULL);*/
	//free(direct);
	return (check);
}
