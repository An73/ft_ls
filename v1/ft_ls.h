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

typedef struct t_flag{
	char	fl_l;
	char	fl_R;
	char	fl_a;
	char	fl_r;
	char	fl_t;
	char	no_dir;
}				t_flag;

typedef struct t_pre{
	char	xtr;
}				t_pre;

void	big_r(char *direct, t_flag *flag);
void	recursion(char *direct, t_flag *flag);
void	print_l(char *putb_file, char *name_file);
char	*putb(char *direct, char *d_name);