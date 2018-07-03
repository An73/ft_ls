/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 12:29:26 by dkotenko          #+#    #+#             */
/*   Updated: 2018/03/04 12:29:28 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	t_flag	flag;
	int		i;

	flag.check_min = 0;
	i = 1;
	while (argc > 1 && i < argc &&\
		argv[i][0] == '-' && check_flag(argv[i], &flag) != 0)
	{
		write_flag(&flag, argv[i]);
		i++;
	}
	flag.num_err = error_check(argv, argc, i);
	if (argc == i)
		no_dir(&flag);
	else
		yes_dir(&flag, argc, argv, i);
	return (0);
}
