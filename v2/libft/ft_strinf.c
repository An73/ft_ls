/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:08:28 by dkotenko          #+#    #+#             */
/*   Updated: 2017/11/15 16:08:29 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_p(int num)
{
	while (num-- > 0)
		ft_putchar('|');
	ft_putchar(' ');
}

static void		printer(int l_top, int l_bott, int digit, int space)
{
	ft_putstr("  capital letter: ");
	ft_p(l_top);
	ft_putnbr(l_top);
	ft_putstr("\nlowercase letter: ");
	ft_p(l_bott);
	ft_putnbr(l_bott);
	ft_putstr("\n           digit: ");
	ft_p(digit);
	ft_putnbr(digit);
	ft_putstr("\n           space: ");
	ft_p(space);
	ft_putnbr(space);
	ft_putchar('\n');
}

void			ft_strinf(char *str)
{
	int		i;
	int		l_top;
	int		l_bott;
	int		digit;
	int		space;

	i = 0;
	l_top = 0;
	l_bott = 0;
	digit = 0;
	space = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			l_top++;
		if (str[i] >= 'a' && str[i] <= 'z')
			l_bott++;
		if (str[i] >= '0' && str[i] <= '9')
			digit++;
		if (str[i] == ' ')
			space++;
		i++;
	}
	printer(l_top, l_bott, digit, space);
}
