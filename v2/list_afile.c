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
		if (readlink(argv[i], NULL, 0) != -1 &&\
			(lstat(argv[i], &line) != -1 && (flag->fl_a == 1 || argv[1][0] != '.')))
		{
			if (!(S_ISDIR(line.st_mode)))
			{
				if (line.st_nlink > pre.nlink)
					pre.nlink = line.st_nlink;
				if (line.st_size > pre.size)
					pre.size = line.st_size;
			}
		}
		else if ((stat(argv[i], &line) != -1 && (flag->fl_a == 1 || argv[1][0] != '.')))
		{
			if (!(S_ISDIR(line.st_mode)))
			{
				if (line.st_nlink > pre.nlink)
					pre.nlink = line.st_nlink;
				if (line.st_size > pre.size)
					pre.size = line.st_size;
			}
		}
		/*if (stat(argv[i], &line) != -1 && (flag->fl_a == 1 || argv[1][0] != '.'))
		{
			if (!(S_ISDIR(line.st_mode)))
			{
				if (line.st_nlink > pre.nlink)
					pre.nlink = line.st_nlink;
				if (line.st_size > pre.size)
					pre.size = line.st_size;
			}
		}*/
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

void	print_arg_file(t_lsave *head, t_flag *flag, t_pre pre, int numb)
{
	t_lsave	*current;
	int		i;

	i = 0;
	current = head;
	while (current != NULL)
	{
		if (flag->fl_l == 1 && (flag->fl_a == 1 || current->name[0] != '.'))
		{
			if (readlink(current->name, NULL, 0) != -1)
				print_l_link(current->name, current->name, pre);
			else
				print_l(current->name, current->name, pre);
		}
		else if (flag->fl_a == 1 || current->name[0] != '.')
			ft_printf("%s", current->name);
		i++;
		if ((i < numb || head->next == NULL) && flag->fl_l != 1 && (flag->fl_a == 1 || current->name[0] != '.'))
			ft_printf("\n");
		current = current->next;
	}
	if (flag->fl_l == 1 && flag->check_min == 2)
		ft_printf("\n");
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

t_lsave *file_arg(t_flag *flag, int argc, char **argv, int i)
{
	t_lsave *head;
	struct stat line;
	int 	numb_dir;
	t_pre 	pre;

	pre = pre_afile(argc, argv, flag);
	head = NULL;
	numb_dir = i;
	while (argc > i)
	{
		if (readlink(argv[i], NULL, 0) != -1 && opendir(argv[i]) == NULL)
		{
			if(lstat(argv[i], &line) != -1)
			{
				if (!(S_ISDIR(line.st_mode)))
					pushback(&head, new_argf(line, argv[i]));
				else
					flag->check_min = 2;
			}
		}
		else if (opendir(argv[i]) == NULL)
		{
			if(stat(argv[i], &line) != -1)
			{
				if (!(S_ISDIR(line.st_mode)))
					pushback(&head, new_argf(line, argv[i]));
				else
					flag->check_min = 2;
			}
		}
		i++;
	}
	if (head != NULL)
	{
		sorting(&head, flag);
		print_arg_file(head, flag, pre, (argc - numb_dir - flag->num_err));
	}
	return (head);
}
