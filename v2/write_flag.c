/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 12:35:10 by dkotenko          #+#    #+#             */
/*   Updated: 2018/03/04 12:35:12 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		check_flag(char *arg, t_flag *flag)
{
	int	i;
	int	check;

	i = 1;
	check = 1;
	if (arg[i] == '\0')
		check = 0;
	while (arg[i] != '\0' && check != 0)
	{
		if (flag->check_min != 1 && (arg[i] == '-' && arg[i+1] == '\0'))
		{
			flag->check_min = 1;
			check = 1;
		}
		else if (arg[i] == 'l' || arg[i] == 'R' || arg[i] == 'a' ||\
			arg[i] == 'r' || arg[i] == 't' || arg[i] == '1')
			check = 1;
		else
			check = 0;
		i++;
	}
	return (check);
}

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
