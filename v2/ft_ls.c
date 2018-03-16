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

/*t_lsave 	*new_list(struct dirent *sd)
{
	struct stat line;
	t_lsave *new;

	new = (t_lsave*)malloc(sizeof(t_lsave));
	stat(sd->d_name, &line);
	new->type = sd->d_type;
	new->name = sd->d_name;
	new->time = ctime(&line.st_mtime);
	new->marker = 0;
	new->next = NULL;
	return (new);
}*/
t_lsave 	*new_list_l(struct dirent *sd, char *direct)
{
	struct stat line;
	t_lsave *new;

	new = (t_lsave*)malloc(sizeof(t_lsave));
	lstat(putb(direct, sd->d_name), &line);
	new->type = sd->d_type;
	new->name = ft_strdup(sd->d_name);
	new->time = line.st_mtime;
	new->marker = 0;
	new->next = NULL;
	return (new);
}

t_lsave 	*new_list(struct dirent *sd, char *direct)
{
	struct stat line;
	t_lsave *new;
	char	*fr;

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

void	pushback(t_lsave **head, t_lsave *new)
{
	t_lsave *current = *head;
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
	DIR *dir;
	struct dirent *sd;
	t_lsave *head;

	head = NULL;
	//ft_printf("d = %s\n", direct);
	dir = opendir(direct);
	if (dir == NULL)
	{
		arg_file(direct, flag);
		return (NULL);
	}
	while ( (sd=readdir(dir)) != NULL)
	{
		if (sd->d_type == 10)
			pushback(&head, new_list_l(sd, direct));
		else
			pushback(&head, new_list(sd, direct));
	}
	closedir(dir);
	return (head);
}

t_lsave 	*new_err(char *name)
{
	t_lsave *new;

	new = (t_lsave*)malloc(sizeof(t_lsave));
	new->name = ft_strdup(name);
	new->next = NULL;
	return (new);
}

int	error_check(char **argv, int argc, int i)
{
	int		n;
	t_lsave *head_err;

	n = 0;
	head_err = NULL;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
		{
			ft_putstr_fd("ls: fts_open: No such file or directory\n", 2);
			exit(1);
		}
		errno = 0;
		opendir(argv[i]);
		if (errno == 2 && readlink(argv[i], NULL, 0) == -1)
		{
			pushback(&head_err, new_err(argv[i]));
			n++;
		}
		i++;
	}
	if (head_err != NULL)
		sort_name(head_err);
	while (head_err != NULL)
	{
		errno = 0;
		opendir(head_err->name);
		if (errno == 2 && readlink(head_err->name, NULL, 0) == -1)
		{
			ft_printf("ls: %s: ", head_err->name);
			perror("");
		}
		head_err = head_err->next;
	}
	return (n);
}
/*void	test(t_lsave *head)
{
	while (head->next != NULL)
	{
		ft_printf("type = %d\nname = %s\ntime = %s\nmarker = %d\n***\n", head->type, head->name, head->time, head->marker);
		head = head->next;
	}
}*/

int		main(int argc, char **argv)
{
	t_flag	flag;
	int		i;

	flag.check_min = 0;
	i = 1;
	while (argc > 1 && i < argc && argv[i][0] == '-' && check_flag(argv[i], &flag) != 0)
	{
		write_flag(&flag, argv[i]);
		i++;
	}
	//ft_printf("%d\n", i);
	flag.num_err = error_check(argv, argc, i);
	//ft_printf("%d\n", i);
	if (argc == i)
		no_dir(&flag);
	else
		yes_dir(&flag, argc, argv, i);
	//system("leaks ft_ls");
	//printer(".", &flag);
}
