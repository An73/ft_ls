/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 12:47:59 by dkotenko          #+#    #+#             */
/*   Updated: 2018/02/21 12:48:01 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/xattr.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "./libft/includes/libft.h"

typedef struct s_flag{
	char	fl_l;
	char	fl_R;
	char	fl_a;
	char	fl_r;
	char	fl_t;
	char	no_dir;
}				t_flag;

typedef struct s_pre{
	char	xtr;
	int		nlink;
	int		size;
	int		block;
}				t_pre;

void	big_r(char *direct, t_flag *flag);
void	recursion(char *direct, t_flag *flag);
void	print_l(char *putb_file, char *name_file, t_pre *pre);
char	*putb(char *direct, char *d_name);

char	*str_t(char *time);
void	print_chmod(int stat_n, int numb, char ch);
int		l_xattr(char *putb_file);
void	print_l_link(char *putb_file, char *name_file, t_pre *pre);


t_pre	pre_write(char *direct, t_flag *flag);
int		numb_len(int numb);
void	little_r(char *direct, t_flag *flag);
void	litt_big_r(char *direct, t_flag *flag);