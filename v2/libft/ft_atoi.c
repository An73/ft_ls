/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:25:07 by dkotenko          #+#    #+#             */
/*   Updated: 2017/11/08 15:21:02 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int		sum;
	int		neg;
	int		i;

	sum = 0;
	i = 0;
	neg = 1;
	while (str[i] == '\v' || str[i] == '\r' || str[i] == '\f' ||\
			str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '+' && str[i + 1] != '-')
		i++;
	if (str[i] != '-' && str[i] < '0' && str[i] > '9')
		return (0);
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		sum = sum * 10 + str[i] - '0';
		i++;
	}
	return (sum * neg);
}
