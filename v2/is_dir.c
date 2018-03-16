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
		//ft_printf("head->nema: %s\n", head->name);
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
	return(i);
}

void	no_dir(t_flag *flag)
{
	flag->no_dir = 1;
	if (flag->fl_R == 1)
		big_r(ft_strdup("."), flag);
	else
		printer(ft_strdup("."), flag);
}

void	yes_dir(t_flag *flag, int argc, char **argv, int i)
{
	int check;
	t_lsave *head;
	t_lsave *head_dir;

	check = 0;
	if (argc == i + 1)
		flag->no_dir = 1;
	head = file_arg(flag, argc, argv, i);
	//printf("cout %d\n", cout_list(head));
	//printf("ooo %d\n", argc - (cout_list(head) + i));


	if (head != NULL && head->next != NULL)
		ft_printf("\n");
	head_dir = argv_dir(argc, argv, i, head);
	if (head_dir != NULL)
	{
		sorting(&head_dir, flag);
	}
	while(head_dir != NULL)
	{
		if (flag->fl_R == 1)
			big_r(head_dir->name, flag);
		else
			printer(head_dir->name, flag);
		head_dir = head_dir->next;
		if (head_dir != NULL)
			ft_printf("\n");
			//if (i < argc && check != 0 && num_d > 0/*check_afile(head, argv[i - 1]) != 0*/)
				//ft_printf("\n");
	}
}











