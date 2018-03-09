/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 12:42:21 by dkotenko          #+#    #+#             */
/*   Updated: 2018/03/05 12:42:24 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		check_afile(t_lsave *head, char *arg)
{
	while (head != NULL)
	{
		if (ft_strcmp(head->name, arg) == 0)
			return (0);
		head = head->next;
	}
	return (1);
}

void	no_dir(t_flag *flag)
{
	flag->no_dir = 1;
	if (flag->fl_R == 1)
		big_r(".", flag);
	else
		printer(".", flag);
}

void	yes_dir(t_flag *flag, int argc, char **argv, int i)
{
	int check;
	t_lsave *head;

	check = 0;
	if (argc == i + 1)
		flag->no_dir = 1;
	head = file_arg(flag, argc, argv, i);
	if (head != NULL && head->next != NULL)
		ft_printf("\n");
	while (argc > i)
	{
		if (check_afile(head, argv[i]) == 0)
			i++;
		else
		{
			if (flag->fl_R == 1)
				check = big_r(argv[i], flag);
			else
				check = printer(argv[i], flag);
			i++;
			if (i != argc && check != 0 && check_afile(head, argv[i]) != 0)
				ft_printf("\n");
		}
	}
}











