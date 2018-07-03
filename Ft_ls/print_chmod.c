/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chmod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 15:43:03 by dkotenko          #+#    #+#             */
/*   Updated: 2018/03/18 15:43:05 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_chmod(int stat_n, int numb, char ch)
{
	if (stat_n & numb)
		ft_printf("%c", ch);
	else
		ft_printf("-");
}

int		l_xattr(char *putb_file)
{
	ssize_t xattr;

	xattr = 0;
	xattr = listxattr(putb_file, NULL, 0, XATTR_NOFOLLOW);
	if (xattr > 0)
		return (1);
	return (0);
}

void	part(int numb)
{
	print_chmod(S_IRUSR, numb, 'r');
	print_chmod(S_IWUSR, numb, 'w');
	if (S_ISUID & numb && S_IXUSR & numb)
		ft_printf("s");
	else if (S_ISUID & numb)
		ft_printf("S");
	else
		print_chmod(S_IXUSR, numb, 'x');
	print_chmod(S_IRGRP, numb, 'r');
	print_chmod(S_IWGRP, numb, 'w');
}

void	print_st_mode(char *putb_file, int numb)
{
	if (S_IFDIR & numb)
		ft_printf("d");
	else
		ft_printf("-");
	part(numb);
	if (S_ISGID & numb && S_IXGRP & numb)
		ft_printf("s");
	else if (S_ISGID & numb)
		ft_printf("S");
	else
		print_chmod(S_IXGRP, numb, 'x');
	print_chmod(S_IROTH, numb, 'r');
	print_chmod(S_IWOTH, numb, 'w');
	if (S_ISVTX & numb && S_IXOTH & numb)
		ft_printf("t");
	else if (S_ISVTX & numb)
		ft_printf("T");
	else
		print_chmod(S_IXOTH, numb, 'x');
	if (l_xattr(putb_file) == 1)
		ft_printf("@");
	else
		ft_printf(" ");
}
