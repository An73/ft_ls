/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 14:12:34 by dkotenko          #+#    #+#             */
/*   Updated: 2018/03/18 14:12:35 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_lsave		*new_err(char *name)
{
	t_lsave	*new;

	new = (t_lsave*)malloc(sizeof(t_lsave));
	new->name = ft_strdup(name);
	new->next = NULL;
	return (new);
}

int			error_push(int i, int argc, char **argv, t_lsave **head_err)
{
	DIR		*dir;
	int		n;

	n = 0;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
		{
			ft_putstr_fd("ls: fts_open: No such file or directory\n", 2);
			exit(1);
		}
		errno = 0;
		dir = opendir(argv[i]);
		if (errno == 2 && readlink(argv[i], NULL, 0) == -1)
		{
			pushback(head_err, new_err(argv[i]));
			n++;
		}
		if (dir != NULL)
			closedir(dir);
		i++;
	}
	return (n);
}

int			error_check(char **argv, int argc, int i)
{
	int			n;
	t_lsave		*head_err;
	DIR			*dir;

	head_err = NULL;
	n = error_push(i, argc, argv, &head_err);
	if (head_err != NULL)
		sort_name(head_err);
	while (head_err != NULL)
	{
		errno = 0;
		dir = opendir(head_err->name);
		if (errno == 2 && readlink(head_err->name, NULL, 0) == -1)
		{
			ft_printf("ls: %s: ", head_err->name);
			perror("");
		}
		head_err = head_err->next;
		if (dir != NULL)
			closedir(dir);
	}
	return (n);
}
