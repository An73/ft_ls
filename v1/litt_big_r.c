/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   litt_big_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 17:09:55 by dkotenko          #+#    #+#             */
/*   Updated: 2018/02/27 17:09:58 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void 	Rec(char *direct, t_flag *flag, DIR *dir);

void	recursion_litt(char *direct, t_flag *flag)
{
	DIR *dir;
	struct dirent *sd;

	dir = opendir(direct);
	if (dir == NULL)
	{
		ft_printf("Error_dir.\n");
		exit(1);
	}
	while ( (sd=readdir(dir)) != NULL)
	{
		if (ft_strcmp(sd->d_name, ".") == 0 || ft_strcmp(sd->d_name, "..") == 0)
			continue;
		else if (sd->d_type == 4 && sd->d_name[0] != '.'/*&& ft_printf("DIR = %s\n", sd->d_name)*/)
		{
			write(1, "\n", 1);
			litt_big_r(putb(direct, sd->d_name), flag);
		}
	}
	closedir(dir);
}

void	litt_big_r(char *direct, t_flag *flag)
{
	//little_r(direct, flag);
	DIR *dir;

	dir = opendir(direct);
	Rec(direct, flag, dir);
	//recursion_litt(direct, flag);
	//little_r(direct, flag);
}


void 	Rec(char *direct, t_flag *flag, DIR *dir)
{
	struct dirent *sd;
	if ((sd=readdir(dir)) == NULL)
	{
		little_r(direct, flag);
		return ;
	}
	Rec(direct, flag, dir);
	if (sd->d_type == 4 && sd->d_name[0] != '.' && (dir = opendir(putb(direct, sd->d_name))))
	{
		Rec(putb(direct, sd->d_name), flag, dir);
		closedir(dir);
		//little_r(direct, flag);
	}

	//little_r(direct, flag);
}