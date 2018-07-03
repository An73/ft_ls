/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 14:49:18 by dkotenko          #+#    #+#             */
/*   Updated: 2017/11/07 21:03:43 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		index;
	size_t		j;

	index = 0;
	j = 0;
	while (s1[index] != '\0')
		index++;
	while (s2[j] != '\0' && j < n)
	{
		s1[index] = s2[j];
		index++;
		j++;
	}
	s1[index] = '\0';
	return (s1);
}
