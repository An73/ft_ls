/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 21:50:04 by dkotenko          #+#    #+#             */
/*   Updated: 2017/11/12 17:03:11 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst_new;
	unsigned char	*src_new;

	dst_new = (unsigned char*)dst;
	src_new = (unsigned char*)src;
	while (n--)
	{
		if (*src_new == (unsigned char)c)
		{
			*dst_new++ = *src_new++;
			return (dst_new);
		}
		*dst_new++ = *src_new++;
	}
	return (NULL);
}
