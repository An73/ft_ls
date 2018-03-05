/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 22:52:57 by dkotenko          #+#    #+#             */
/*   Updated: 2017/11/08 19:23:40 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		index;
	char	*str;

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
			str[index] = f(s[index]);
			index++;
		}
		str[index] = '\0';
		return (str);
	}
	return (NULL);
}
