/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 21:09:54 by dkotenko          #+#    #+#             */
/*   Updated: 2017/11/08 14:37:37 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*big_new;
	const char	*little_new;
	size_t		len_str;

	if (*little == '\0')
		return ((char*)big);
	len_str = ft_strlen((char*)little);
	while (*big != '\0' && len >= len_str)
	{
		big_new = big;
		little_new = little;
		while (*little_new != '\0' && *little_new == *big_new)
		{
			little_new++;
			big_new++;
		}
		if (*little_new == '\0')
			return ((char*)big);
		big++;
		len--;
	}
	return (0);
}
