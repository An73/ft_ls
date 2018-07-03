/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 22:44:04 by dkotenko          #+#    #+#             */
/*   Updated: 2017/10/29 14:36:11 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;

	i = 0;
	if (dst >= src)
	{
		while (len--)
			((unsigned char*)dst)[len] = ((unsigned char*)src)[len];
	}
	else
		while (i < len)
		{
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
			i++;
		}
	return (dst);
}
