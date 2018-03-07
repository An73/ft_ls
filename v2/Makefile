NAME = ft_ls

LBMK = make -C libft/ fclean && make -C libft/

SRCS = ft_ls.c write_flag.c printer.c pre.c print_l.c print_l_link.c sort.c is_dir.c\
big_r.c arg_file.c list_afile.c

GCCO = gcc -Wall -Wextra -Werror -c $(SRCS) -Ift_ls.h
GCC = gcc -Wall -Wextra -Werror *.o ./libft/libft.a -o ft_ls

all: $(NAME)

$(NAME): $(SRCS) ft_ls.h
	$(LBMK)
	$(GCCO)
	$(GCC)
clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f ft_ls

re: fclean all