/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:00:09 by dkotenko          #+#    #+#             */
/*   Updated: 2018/03/05 13:00:11 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_name(t_lsave *head)
{
	t_lsave	*ptr;
	t_lsave *lptr;
	int		s;

	lptr = NULL;
	s = 1;
	while (s)
	{
		s = 0;
		ptr = head;
		while (ptr->next != lptr)
		{
			if (ft_strcmp(ptr->name, ptr->next->name) > 0)
			{
				swap_name(ptr, ptr->next);
				s = 1;
			}
			ptr = ptr->next;
		}
		lptr = ptr;
	}
}

void	sort_recur(t_lsave *head)
{
	t_lsave	*ptr;
	t_lsave *lptr;
	int		s;

	lptr = NULL;
	s = 1;
	while (s)
	{
		s = 0;
		ptr = head;
		while (ptr->next != lptr)
		{
			if (ft_strcmp(ptr->name, ptr->next->name) < 0)
			{
				swap_name(ptr, ptr->next);
				s = 1;
			}
			ptr = ptr->next;
		}
		lptr = ptr;
	}
}

void	sort_time(t_lsave *head)
{
	t_lsave	*ptr;
	t_lsave *lptr;
	int		s;

	lptr = NULL;
	s = 1;
	while (s)
	{
		s = 0;
		ptr = head;
		while (ptr->next != lptr)
		{
			if (ptr->time < ptr->next->time)
			{
				swap_name(ptr, ptr->next);
				s = 1;
			}
			ptr = ptr->next;
		}
		lptr = ptr;
	}
}

void	sort_time_recurs(t_lsave *head)
{
	t_lsave	*ptr;
	t_lsave *lptr;
	int		s;

	lptr = NULL;
	s = 1;
	while (s)
	{
		s = 0;
		ptr = head;
		while (ptr->next != lptr)
		{
			if (ptr->time > ptr->next->time)
			{
				swap_name(ptr, ptr->next);
				s = 1;
			}
			ptr = ptr->next;
		}
		lptr = ptr;
	}
}
