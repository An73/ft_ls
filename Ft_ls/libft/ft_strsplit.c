/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 12:45:23 by dkotenko          #+#    #+#             */
/*   Updated: 2017/11/18 13:04:38 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char		*ft_strcpy_split(char *dest, const char *src, char c)
{
	char	*str;

	str = dest;
	while (*src != c && *src != '\0')
		*dest++ = *src++;
	*dest = '\0';
	return (str);
}

static size_t	sym(char *s, char c)
{
	size_t		i;

	i = 0;
	while (*s != '\0')
	{
		while (*s++ != c)
		{
			i++;
			if (*s == c || *s == '\0')
				return (i);
		}
	}
	return (0);
}

static int		word(char *s, char c)
{
	int		i;

	i = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			i++;
			while (*s++ != c && *s)
				;
			s--;
		}
		s++;
	}
	return (i);
}

static char		**array_ray(char **array, int j)
{
	array[j] = NULL;
	return (array);
}

char			**ft_strsplit(char const *s, char c)
{
	char	*str;
	char	**array;
	int		j;

	j = 0;
	if (s && c != '\0')
	{
		str = (char*)s;
		if (!(array = (char**)malloc(sizeof(char*) * (word(str, c) + 1))))
			return (NULL);
		while (array)
		{
			while (*str == c)
				str++;
			if (*str == '\0')
				return (array_ray(array, j));
			array[j] = (char*)malloc(sizeof(char) * (sym(str, c) + 1));
			array[j] = ft_strcpy_split(array[j], str, c);
			array[j++ + 1] = NULL;
			while (*str != c)
				if (*str++ == '\0')
					return (array);
		}
	}
	return (NULL);
}
