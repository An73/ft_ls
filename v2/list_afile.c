/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_afile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:12:15 by dkotenko          #+#    #+#             */
/*   Updated: 2018/03/07 15:12:17 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_pre		pre_afile(int argc, char **argv, t_flag *flag)
{
	struct stat line;
	t_pre		pre;
	int			i;

	i = 1;
	pre.nlink = 0;
	pre.size = 0;
	pre.block = 0;
	while (argc > i)
	{
		if (stat(argv[i], &line) != -1 && (flag->fl_a == 1 || argv[1][0] != '.'))
		{
			if (!(S_ISDIR(line.st_mode)))
			{
				if (line.st_nlink > pre.nlink)
					pre.nlink = line.st_nlink;
				if (line.st_size > pre.size)
					pre.size = line.st_size;
			}
		}
		i++;
	}
	return (pre);
}

t_lsave 	*new_argf(struct stat line, char *argv)
{
	t_lsave *new;

	new = (t_lsave*)malloc(sizeof(t_lsave));
	new->type = line.st_mode;
	new->name = ft_strdup(argv);
	new->time = line.st_mtime;
	new->marker = 0;
	new->next = NULL;
	return (new);
}

void	print_arg_file(t_lsave *head, t_flag *flag, t_pre pre)
{
	t_lsave	*current;

	current = head;
	while (current != NULL)
	{
		if (flag->fl_l == 1 && (flag->fl_a == 1 || current->name[0] != '.'))
		{
			if (current->type == 10)
				print_l_link(current->name, current->name, pre);
			else
				print_l(current->name, current->name, pre);
		}
		else if (flag->fl_a == 1 || current->name[0] != '.')
			ft_printf("%s\n", current->name);
		current = current->next;
	}
}

void	sorting(t_lsave **head, t_flag *flag)
{
	sort_name(*head);
	if (flag->fl_r == 1)
		sort_recur(*head);
	if (flag->fl_r == 1 && flag->fl_t == 1)
		sort_time_recurs(*head);
	else if (flag->fl_t == 1)
		sort_time(*head);
}

t_lsave *file_arg(t_flag *flag, int argc, char **argv)
{
	t_lsave *head;
	struct stat line;
	int 	i;
	t_pre 	pre;

	pre = pre_afile(argc, argv, flag);
	head = NULL;
	i = 1;
	while (argc > i)
	{
		if(stat(argv[i], &line) != -1)
		{
			if (!(S_ISDIR(line.st_mode)))
				pushback(&head, new_argf(line, argv[i]));
		}
		i++;
	}
	if (head != NULL)
	{
		sorting(&head, flag);
		print_arg_file(head, flag, pre);
	}
	return (head);
}
