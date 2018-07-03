/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 14:02:43 by dkotenko          #+#    #+#             */
/*   Updated: 2018/03/18 14:02:45 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_lsave		*new_argf(struct stat line, char *argv)
{
	t_lsave	*new;

	new = (t_lsave*)malloc(sizeof(t_lsave));
	new->type = line.st_mode;
	new->name = ft_strdup(argv);
	new->time = line.st_mtime;
	new->marker = 0;
	new->next = NULL;
	return (new);
}

t_lsave		*new_list_l(struct dirent *sd, char *direct)
{
	struct stat	line;
	t_lsave		*new;
	char		*fr;

	new = (t_lsave*)malloc(sizeof(t_lsave));
	fr = putb(direct, sd->d_name);
	lstat(fr, &line);
	free(fr);
	new->type = sd->d_type;
	new->name = ft_strdup(sd->d_name);
	new->time = line.st_mtime;
	new->marker = 0;
	new->next = NULL;
	return (new);
}

t_lsave		*new_list(struct dirent *sd, char *direct)
{
	struct stat	line;
	t_lsave		*new;
	char		*fr;

	new = (t_lsave*)malloc(sizeof(t_lsave));
	fr = putb(direct, sd->d_name);
	stat(fr, &line);
	free(fr);
	new->type = sd->d_type;
	new->name = ft_strdup(sd->d_name);
	new->time = line.st_mtime;
	new->marker = 0;
	new->next = NULL;
	return (new);
}

void		pushback(t_lsave **head, t_lsave *new)
{
	t_lsave *current;

	current = *head;
	if (*head != NULL)
	{
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
	else
		*head = new;
}

t_lsave		*new_lsave(char *direct, t_flag *flag)
{
	DIR				*dir;
	struct dirent	*sd;
	t_lsave			*head;

	head = NULL;
	dir = opendir(direct);
	if (dir == NULL)
	{
		arg_file(direct, flag);
		return (NULL);
	}
	while ((sd = readdir(dir)) != NULL)
	{
		if (sd->d_type == 10)
			pushback(&head, new_list_l(sd, direct));
		else
			pushback(&head, new_list(sd, direct));
	}
	closedir(dir);
	return (head);
}
