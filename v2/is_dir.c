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
		big_r(".", flag);
	else
		printer(".", flag);
}

void	yes_dir(t_flag *flag, int argc, char **argv, int i)
{
	int check;
	t_lsave *head;
	int num_d;

	check = 0;
	if (argc == i + 1)
		flag->no_dir = 1;
	head = file_arg(flag, argc, argv, i);
	//printf("cout %d\n", cout_list(head));
	//printf("ooo %d\n", argc - (cout_list(head) + i));
	num_d = argc - (cout_list(head) + i);
	if (head != NULL && head->next != NULL)
		ft_printf("\n");
	while (argc > i)
	{
		if (check_afile(head, argv[i]) == 0)
			i++;
		else if (argc > i)
		{
			//ft_printf("i = %d\n", i);
			if (flag->fl_R == 1)
				check = big_r(argv[i], flag);
			else
				check = printer(argv[i], flag);
			i++;
			num_d--;
			//write(1,  "+", 1);
			//printf("check = %d\n", check_afile(head, argv[i]));
			//write(1,  "-", 1);
			if (i < argc && check != 0 && num_d > 0/*check_afile(head, argv[i - 1]) != 0*/)
				ft_printf("\n");
		}
	}
}











