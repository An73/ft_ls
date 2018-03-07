/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 16:53:30 by dkotenko          #+#    #+#             */
/*   Updated: 2018/02/22 16:53:31 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		l_xattr(char *putb_file)
{
	ssize_t xattr = 0;

	xattr = listxattr(putb_file, NULL, 0, XATTR_NOFOLLOW);
	if (xattr > 0)
		return (1);
	return (0);
}

void	print_chmod(int stat_n, int numb, char ch)
{
	if (stat_n & numb)
		ft_printf("%c", ch);
	else
		ft_printf("-");
}

char	*str_t(char *time)
{
	char 	*str_tm;
	int		i;

	i = 0;
	time += 4;
	str_tm = (char*)malloc(sizeof(char) * 13);
	while (i < 12)
	{
		str_tm[i] = *time;
		time++;
		i++;
	}
	str_tm[i] = '\0';
	return (str_tm);
}

void	print_st_mode(char *putb_file, int numb)
{
	//ft_printf("numb = %d\n", numb);
	if (S_IFDIR & numb)
		ft_printf("d");
	else
		ft_printf("-");
	//print_chmod(S_IFDIR, numb, 'd');
	print_chmod(S_IRUSR, numb, 'r');
	print_chmod(S_IWUSR, numb, 'w');
	print_chmod(S_IXUSR, numb, 'x');

	print_chmod(S_IRGRP, numb, 'r');
	print_chmod(S_IWGRP, numb, 'w');
	print_chmod(S_IXGRP, numb, 'x');

	print_chmod(S_IROTH, numb, 'r');
	print_chmod(S_IWOTH, numb, 'w');
	print_chmod(S_IXOTH, numb, 'x');
	if (l_xattr(putb_file) == 1)
		ft_printf("@");
	else
		ft_printf(" ");
}

int		numb_len(int numb)
{
	int		i;

	i = 0;
	while (numb)
	{
		numb = numb / 10;
		i++;
	}
	return (i);
}

void	print_l(char *putb_file, char *name_file, t_pre pre)
{
	struct stat line;
	struct passwd *pwd;
	struct group *grp;

	stat(putb_file, &line);
	pwd = getpwuid(line.st_uid);
	grp = getgrgid(line.st_gid);
	//ft_printf("line.st_mode = %d\n", line.st_mode);
	//ft_printf("name_file = %s\n", name_file);
	print_st_mode(putb_file, line.st_mode);
	ft_printf("%*d %s  %s %*d %s ", (numb_len(pre.nlink) + 1), line.st_nlink, pwd->pw_name,\
		grp->gr_name, (numb_len(pre.size) + 1), line.st_size, str_t(ctime(&line.st_mtime)));
	ft_printf("%s\n", name_file);
}


//readlink(putb_file, buf, sizeof(buf))