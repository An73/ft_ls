/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 18:17:56 by dkotenko          #+#    #+#             */
/*   Updated: 2017/11/12 17:07:30 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *big, const char *little)
{
	const char	*big_new;
	const char	*little_new;

	if (*little == '\0')
		return ((char*)big);
	while (*big != '\0')
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
	}
	return (0);
}
