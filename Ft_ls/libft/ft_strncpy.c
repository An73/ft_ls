/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 13:33:45 by dkotenko          #+#    #+#             */
/*   Updated: 2017/11/12 17:08:08 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*str;

	str = dest;
	while (*src && n > 0)
	{
		n--;
		*dest++ = *src++;
	}
	while (n-- > 0)
		*dest++ = '\0';
	return (str);
}
