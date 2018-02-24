/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 12:48:21 by dkotenko          #+#    #+#             */
/*   Updated: 2018/02/21 12:48:22 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	write_flag(t_flag *flag, char *arg)
{
	if (ft_strchr(arg, 'l') != NULL)
		flag->fl_l = 1;
	if (ft_strchr(arg, 'R') != NULL)
		flag->fl_R = 1;
	if (ft_strchr(arg, 'a') != NULL)
		flag->fl_a = 1;
	if (ft_strchr(arg, 'r') != NULL)
		flag->fl_r = 1;
	if (ft_strchr(arg, 't') != NULL)
		flag->fl_t = 1;
}

void	printer(char *direct, t_flag *flag)
{
	DIR *dir;
	struct dirent *sd;

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
		if (ft_strcmp(sd->d_name, ".") == 0 || ft_strcmp(sd->d_name, "..") == 0)
			continue;
		if (flag->fl_l == 1 && sd->d_name[0] != '.')
			print_l(putb(direct, sd->d_name), sd->d_name);
		else if (sd->d_name[0] != '.')
			ft_printf("%s\n", sd->d_name);
	}
	closedir(dir);
}

void	big_r(char *direct, t_flag *flag)
{
	printer(direct, flag);
	recursion(direct, flag);
}

int		main(int argc, char **argv)
{
	t_flag	flag;
	int		i;

	i = 1;
	while (argc > 1 && i < argc && argv[i][0] == '-')
	{
		write_flag(&flag, argv[i]);
		i++;
	}
	if (argc == i)
	{
		flag.no_dir = 1;
		if (flag.fl_R == 1)
			big_r(".", &flag);
		else if (flag.fl_l == 1)
			printer(".", &flag);
	}
	else
	{
		if (argc == i + 1)
			flag.no_dir = 1;
		while (argc > i)
		{
			if (flag.fl_R == 1)
				big_r(argv[i], &flag);
			i++;
		}
	}
	//write(1, "\n", 1);
	//ft_printf("l = %d\nR = %d\na = %d\nr = %d\nt = %d\n", flag.fl_l, flag.fl_R, flag.fl_a, flag.fl_r, flag.fl_t);
}
