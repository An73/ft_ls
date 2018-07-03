/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 15:27:00 by dkotenko          #+#    #+#             */
/*   Updated: 2018/03/01 15:27:02 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	arg_file(char *direct, t_flag *flag)
{
	struct stat		line;
	struct passwd	*pwd;
	struct group	*grp;
	int				i;

	i = stat(direct, &line);
	if (i == -1)
		return ;
	pwd = getpwuid(line.st_uid);
	grp = getgrgid(line.st_gid);
	if (flag->fl_l == 1)
	{
		print_st_mode(direct, line.st_mode);
		ft_printf("%*d %s  %s %*d %s ", (numb_len(line.st_nlink) + 1),\
		line.st_nlink, pwd->pw_name, grp->gr_name, (numb_len(line.st_size)\
		+ 1), line.st_size, str_t(ctime(&line.st_mtime)));
	}
	if (S_IFDIR & line.st_mode)
	{
		ft_printf("ls: %s: ", direct);
		ft_putstr_fd(strerror(13), 2);
		ft_putstr_fd("\n", 2);
	}
	else
		ft_printf("%s\n", direct);
}
