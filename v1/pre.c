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

void	pre(t_pre *pre, char *direct)
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
	if (flag->no_dir != 1)
		ft_printf("%s:\n", direct);
	flag->no_dir = 0;
	while ( (sd=readdir(dir)) != NULL)
	{
		if (l_xattr(direct) == 1)
			pre->xtr = 1;
	}
	closedir(dir);

}


