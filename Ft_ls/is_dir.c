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

int		cout_list(t_lsave *head)
{
	int		i;

	i = 0;
	while (head != NULL)
	{
		head = head->next;
		i++;
	}
	return (i);
}

void	no_dir(t_flag *flag)
{
	char	*direct;

	direct = ft_strdup(".");
	flag->no_dir = 1;
	if (flag->fl_bg == 1)
		big_r(direct, flag);
	else
		printer(direct, flag);
	free(direct);
}

void	print(char *name, t_flag *flag)
{
	if (flag->fl_bg == 1)
		big_r(name, flag);
	else
		printer(name, flag);
}

void	yes_dir(t_flag *flag, int argc, char **argv, int i)
{
	int		check;
	t_lsave	*head;
	t_lsave	*head_dir;
	t_lsave	*fr;

	check = 0;
	if (argc == i + 1)
		flag->no_dir = 1;
	head = file_arg(flag, argc, argv, i);
	if (head != NULL && head->next != NULL)
		ft_printf("\n");
	head_dir = argv_dir(argc, argv, i, head);
	free_lst(&head);
	if (head_dir != NULL)
		sorting(&head_dir, flag);
	fr = head_dir;
	while (head_dir != NULL)
	{
		print(head_dir->name, flag);
		head_dir = head_dir->next;
		if (head_dir != NULL)
			ft_printf("\n");
	}
	free_lst(&fr);
}
