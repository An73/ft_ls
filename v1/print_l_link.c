/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_l_link.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 19:11:05 by dkotenko          #+#    #+#             */
/*   Updated: 2018/02/24 19:11:06 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_st_mode_l(char *putb_file, int numb)
{
	ft_printf("l");
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

void	print_l_link(char *putb_file, char *name_file, t_pre *pre)
{
	struct stat line;
	struct passwd *pwd;
	struct group *grp;
	char	*l_name;

	lstat(putb_file, &line);
	pwd = getpwuid(line.st_uid);
	grp = getgrgid(line.st_gid);
	//ft_printf("line.st_mode = %d\n", line.st_mode);
	//ft_printf("name_file = %s\n", name_file);
	l_name = malloc(line.st_size + 1);
	readlink(putb_file, l_name, line.st_size + 1);
	l_name[line.st_size] = '\0';
	print_st_mode_l(putb_file, line.st_mode);
	ft_printf("%*d %s  %s %*d %s ", (numb_len(pre->nlink) + 1), line.st_nlink, pwd->pw_name,\
		grp->gr_name, (numb_len(pre->size) + 1), line.st_size, str_t(ctime(&line.st_mtime)));
	ft_printf("%s -> ", name_file);
	ft_printf("%s\n", l_name);
}
