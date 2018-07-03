/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 16:53:30 by dkotenko          #+#    #+#             */
/*   Updated: 2018/02/22 16:53:31 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*str_t(char *time)
{
	char	*str_tm;
	int		i;

	i = 0;
	time += 4;
	str_tm = (char*)malloc(sizeof(char) * 13);
	while (i < 12)
	{
		str_tm[i] = *time;
		time++;
		i++;
	}
	str_tm[i] = '\0';
	return (str_tm);
}

char	*str_btf(char *time)
{
	char	*str_tm;
	int		i;

	i = 0;
	time += 4;
	str_tm = (char*)malloc(sizeof(char) * 13);
	while (i < 7)
	{
		str_tm[i] = *time;
		time++;
		i++;
	}
	str_tm[i++] = ' ';
	time += 8;
	while (*time != '\n')
	{
		if (*time != ' ')
		{
			str_tm[i] = *time;
			i++;
		}
		time++;
	}
	str_tm[i] = '\0';
	return (str_tm);
}

int		numb_len(int numb)
{
	int		i;

	i = 0;
	if (numb == 0)
		i++;
	while (numb)
	{
		numb = numb / 10;
		i++;
	}
	return (i);
}

void	print_l(char *putb_file, char *name_file, t_pre pre)
{
	struct stat		line;
	struct passwd	*pwd;
	struct group	*grp;
	char			*str_time;

	stat(putb_file, &line);
	pwd = getpwuid(line.st_uid);
	grp = getgrgid(line.st_gid);
	print_st_mode(putb_file, line.st_mode);
	ft_printf("%*d %s  %s %*d ", (numb_len(pre.nlink) + 1),\
	line.st_nlink, pwd->pw_name,\
		grp->gr_name, (numb_len(pre.size) + 1), line.st_size);
	if ((time(NULL) < line.st_mtime) ||\
		((time(NULL) - line.st_mtime) > 15780000))
	{
		str_time = str_btf(ctime(&line.st_mtime));
		ft_printf("%s ", str_time);
	}
	else
	{
		str_time = str_t(ctime(&line.st_mtime));
		ft_printf("%s ", str_time);
	}
	ft_printf("%s\n", name_file);
	free(str_time);
}
