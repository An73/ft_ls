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

t_lsave		*no_sort_flag(char *direct, t_pre *pre, t_flag *flag)
{
	t_lsave *head;
	t_lsave	*current;

	head = new_lsave(direct);
	if (head == NULL)
		return (NULL);
	sort_name(head);
	current = head;
	while (current != NULL)
	{
		if (flag->fl_l == 1)
		{
			if (current->type == 10)
				print_l_link(current->name, current->name, pre);
			else
				print_l(current->name, current->name, pre);
		}
		else if (flag->fl_a == 1 || current->name[0] != '.')
			ft_printf("%s\n", current->name);
		current = current->next;
	}
	return (head);
}

t_lsave	 *printer(char *direct, t_flag *flag)
{
	t_pre pre;
	t_lsave *list;

	pre = pre_write(direct, flag);
	list = no_sort_flag(direct, &pre, flag);
	if (list == NULL)
		return (NULL);
	/*while (list != NULL)
	{
		ft_printf("name = %s\n", list->name);
		ft_printf("type = %d\n", list->type);
		list = list->next;
	}*/
	return (list);
}
