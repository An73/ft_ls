/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 16:13:34 by dkotenko          #+#    #+#             */
/*   Updated: 2018/02/27 16:13:35 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	readdir_recurs(char *direct, t_flag *flag, DIR *dir, t_pre *pre)
{
	struct dirent *sd;

	if ( (sd=readdir(dir)) == NULL)
		return ;
	readdir_recurs(direct, flag, dir, pre);
	if (flag->fl_l == 1 && (flag->fl_a == 1 || sd->d_name[0] != '.'))
	{
		//ft_printf("d_type = %d\n", sd->d_type);
		if (sd->d_type == 10)
			print_l_link(putb(direct, sd->d_name), sd->d_name, pre);
		else if (sd->d_type == 4 || sd->d_type == 8)
			print_l(putb(direct, sd->d_name), sd->d_name, pre);
	}
	else if ((flag->fl_a == 1 || sd->d_name[0] != '.') && (sd->d_type == 10 || sd->d_type == 4 || sd->d_type == 8))
		ft_printf("%s\n", sd->d_name);
}

void	little_r(char *direct, t_flag *flag)
{
	DIR *dir;
	t_pre pre;

	dir = opendir(direct);
	if (dir == NULL)
	{
		ft_printf("Error_dir.\n");
		exit(1);
	}
	pre = pre_write(direct, flag);
	if (flag->no_dir != 1)
		ft_printf("\n%s:\n", direct);
	flag->no_dir = 0;
	if (flag->fl_l == 1 && pre.size != 0)
		ft_printf("total %d\n", pre.block);
	readdir_recurs(direct, flag, dir, &pre);
	closedir(dir);
}
