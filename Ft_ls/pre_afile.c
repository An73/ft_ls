/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_afile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 17:32:33 by dkotenko          #+#    #+#             */
/*   Updated: 2018/03/18 17:32:35 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		pre_s(struct stat line, t_pre *pre)
{
	if (!(S_ISDIR(line.st_mode)))
	{
		if (line.st_nlink > pre->nlink)
			pre->nlink = line.st_nlink;
		if (line.st_size > pre->size)
			pre->size = line.st_size;
	}
}

t_pre		pre_afile(int argc, char **argv, t_flag *flag)
{
	struct stat	line;
	t_pre		pre;
	int			i;

	i = 1;
	pre.nlink = 0;
	pre.size = 0;
	pre.block = 0;
	while (argc > i)
	{
		if (readlink(argv[i], NULL, 0) != -1 &&\
			(lstat(argv[i], &line) != -1 &&\
				(flag->fl_a == 1 || argv[1][0] != '.')))
			pre_s(line, &pre);
		else if ((stat(argv[i], &line) != -1 &&\
			(flag->fl_a == 1 || argv[1][0] != '.')))
			pre_s(line, &pre);
		i++;
	}
	return (pre);
}
