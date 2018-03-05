/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 23:48:11 by dkotenko          #+#    #+#             */
/*   Updated: 2017/11/08 19:24:23 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		index;
	char				*str;

	index = 0;
	if (s != NULL)
	{
		while (s[index] != '\0')
			index++;
		str = (char *)malloc(index * sizeof(*str) + 1);
		if (!str)
			return (NULL);
		index = 0;
		while (s[index] != '\0')
		{
			str[index] = f(index, s[index]);
			index++;
		}
		str[index] = '\0';
		return (str);
	}
	return (NULL);
}
