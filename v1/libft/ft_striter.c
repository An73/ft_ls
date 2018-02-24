/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 22:20:14 by dkotenko          #+#    #+#             */
/*   Updated: 2017/11/13 19:07:58 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_striter(char *s, void (*f)(char*))
{
	int		index;

	index = 0;
	if (s != NULL && f != NULL)
	{
		while (s[index] != '\0')
		{
			f(&s[index]);
			index++;
		}
	}
}
