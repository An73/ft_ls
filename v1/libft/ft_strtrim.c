/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 21:27:44 by dkotenko          #+#    #+#             */
/*   Updated: 2017/11/08 21:44:30 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		index;
	int		len;
	char	*fresh;

	i = 0;
	index = 0;
	len = 0;
	if (s != NULL)
	{
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		if (s[i] == '\0')
			return (ft_strdup("\0"));
		len = ft_strlen((char*)s) - 1;
		while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
			len--;
		if ((fresh = (char*)malloc((len - i + 2) * sizeof(*fresh))) == NULL)
			return (NULL);
		while (i <= len)
			fresh[index++] = s[i++];
		fresh[index] = '\0';
		return (fresh);
	}
	return (NULL);
}
