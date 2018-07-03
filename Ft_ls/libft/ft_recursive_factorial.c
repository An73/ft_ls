/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:34:51 by dkotenko          #+#    #+#             */
/*   Updated: 2017/11/16 13:34:55 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	if (nb == 0)
		return (1);
	if (nb > 12)
		return (0);
	else if (nb > 0)
	{
		nb = nb * ft_recursive_factorial(nb - 1);
		return (nb);
	}
	else
		return (0);
}
