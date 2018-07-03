/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 12:10:12 by dkotenko          #+#    #+#             */
/*   Updated: 2018/03/12 12:10:13 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_lsave	*argv_dir(int argc, char **argv, int i, t_lsave *head)
{
	struct stat	line;
	t_lsave		*head_dir;

	head_dir = NULL;
	while (argc > i)
	{
		if (check_afile(head, argv[i]) == 0 || stat(argv[i], &line) == -1)
			i++;
		else if (argc > i && stat(argv[i], &line) != -1)
		{
			pushback(&head_dir, new_argf(line, argv[i]));
			i++;
		}
	}
	return (head_dir);
}
