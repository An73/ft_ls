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

typedef struct s_lsave{
	int		type;
	char	*name;
	char	*time;
	int		marker;
	struct s_lsave *next;
}				t_lsave;

void	write_flag(t_flag *flag, char *arg);
t_lsave	 *printer(char *direct, t_flag *flag);
t_lsave		*new_lsave(char *direct);
void	print_l(char *putb_file, char *name_file, t_pre *pre);
void	print_l_link(char *putb_file, char *name_file, t_pre *pre);
t_pre	pre_write(char *direct, t_flag *flag);
char	*putb(char *direct, char *d_name);
int		numb_len(int numb);
char	*str_t(char *time);
void	print_chmod(int stat_n, int numb, char ch);
int		l_xattr(char *putb_file);
void	sort_name(t_lsave *head);
void	swap_name(t_lsave *a, t_lsave *b);
void	no_dir(t_flag *flag);
void	big_r(char *direct, t_flag *flag);