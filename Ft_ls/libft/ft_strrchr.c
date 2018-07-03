/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 17:02:38 by dkotenko          #+#    #+#             */
/*   Updated: 2017/11/07 22:17:39 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *str, int ch)
{
	char		*buf;
	char		*temp;

	temp = NULL;
	buf = (char*)str;
	while (*buf != '\0')
	{
		if (*buf == ch)
			temp = buf;
		buf++;
	}
	if (ch == '\0')
		temp = buf;
	return (temp);
}
