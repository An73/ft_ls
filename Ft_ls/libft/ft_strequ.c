/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 01:58:34 by dkotenko          #+#    #+#             */
/*   Updated: 2017/11/08 19:23:17 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int		i;

	if (s1 != NULL && s2 != NULL)
	{
		i = ft_strcmp((char*)s1, (char*)s2);
		if (i == 0)
			return (1);
		else
			return (0);
	}
	return (0);
}
