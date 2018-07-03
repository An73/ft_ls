/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_sp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 18:04:17 by dkotenko          #+#    #+#             */
/*   Updated: 2018/03/18 18:04:19 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_swap_t(time_t *a, time_t *b)
{
	time_t	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	swap_name(t_lsave *a, t_lsave *b)
{
	char	*tmp;

	tmp = NULL;
	tmp = a->name;
	a->name = b->name;
	b->name = tmp;
	ft_swap(&a->type, &b->type);
	ft_swap_t(&a->time, &b->time);
}
