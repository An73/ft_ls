/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 18:26:22 by dkotenko          #+#    #+#             */
/*   Updated: 2018/02/23 18:26:23 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	pre_w(t_pre *pre, char *direct, t_flag *flag)
{
	DIR *dir;
	struct dirent *sd;
	struct stat line;

	stat(direct, &line);
	dir = opendir(direct);
	if (dir == NULL)
	{
		ft_printf("Error_dir.\n");
		exit(1);
	}
	while ( (sd=readdir(dir)) != NULL)
	{
		if (flag->fl_a == 1 || sd->d_name[0] != '.')
		{
			stat(putb(direct, sd->d_name), &line);
			if (l_xattr(direct) == 1)
				pre->xtr = 1;
			if (line.st_nlink > pre->nlink)
				pre->nlink = line.st_nlink;
			if (line.st_size > pre->size)
				pre->size = line.st_size;
			pre->block += line.st_blocks;
		}
	}
	closedir(dir);
}

t_pre	pre_write(char *direct, t_flag *flag)
{
	t_pre pre;

	pre.nlink = 0;
	pre.size = 0;

	pre_w(&pre, direct, flag);
	return (pre);
}


