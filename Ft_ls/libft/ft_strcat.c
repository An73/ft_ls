/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 13:46:01 by dkotenko          #+#    #+#             */
/*   Updated: 2017/10/27 14:44:24 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strcat(char *s1, const char *s2)
{
	int		index;
	int		j;

	index = 0;
	j = 0;
	while (s1[index] != '\0')
		index++;
	while (s2[j] != '\0')
	{
		s1[index] = s2[j];
		index++;
		j++;
	}
	s1[index] = '\0';
	return (s1);
}
