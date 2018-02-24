NAME = ft_ls

LBMK = make -C libft/ fclean && make -C libft/

SRCS = ft_ls.c recursion.c print_l.c

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