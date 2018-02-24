/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 12:38:54 by dkotenko          #+#    #+#             */
/*   Updated: 2018/02/22 12:38:58 by dkotenko         ###   ########.fr       */
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

void	recursion(char *direct, t_flag *flag)
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
			big_r(putb(direct, sd->d_name), flag);
		}
	}
	closedir(dir);
}
//big_r(putb(direct, sd->d_name));