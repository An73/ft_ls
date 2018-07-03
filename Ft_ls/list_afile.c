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
		if ((i < numb || head->next == NULL) &&\
			flag->fl_l != 1 && (flag->fl_a == 1 || current->name[0] != '.'))
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

void	fa_part(char **argv, t_flag *flag, t_lsave **head, int i)
{
	struct stat line;

	if (stat(argv[i], &line) != -1)
	{
		if (!(S_ISDIR(line.st_mode)))
			pushback(head, new_argf(line, argv[i]));
		else
			flag->check_min = 2;
	}
}

void	fa_part_l(char **argv, t_flag *flag, t_lsave **head, int i)
{
	struct stat line;

	if (lstat(argv[i], &line) != -1)
	{
		if (!(S_ISDIR(line.st_mode)))
			pushback(head, new_argf(line, argv[i]));
		else
			flag->check_min = 2;
	}
}

t_lsave	*file_arg(t_flag *flag, int argc, char **argv, int i)
{
	t_lsave		*head;
	int			numb_dir;
	t_pre		pre;
	DIR			*dir;

	pre = pre_afile(argc, argv, flag);
	head = NULL;
	numb_dir = i;
	while (argc > i)
	{
		dir = opendir(argv[i]);
		if (readlink(argv[i], NULL, 0) != -1 && dir == NULL)
			fa_part_l(argv, flag, &head, i);
		else if (dir == NULL)
			fa_part(argv, flag, &head, i);
		if (dir != NULL)
			closedir(dir);
		i++;
	}
	if (head != NULL)
	{
		sorting(&head, flag);
		print_arg_file(head, flag, pre, (argc - numb_dir - flag->num_err));
	}
	return (head);
}
