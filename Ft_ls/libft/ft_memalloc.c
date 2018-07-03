/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:30:04 by dkotenko          #+#    #+#             */
/*   Updated: 2017/11/10 13:42:12 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*a;

	a = malloc(size);
	if (a)
	{
		ft_memset(a, 0, size);
		return (a);
	}
	return (NULL);
}
