NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRCS = 	src/so_long.c\
	 	src/utils.c\
	 	src/map_control.c\
	 	src/map_checker.c\
	 	src/map_checker_utils.c\
		src/get_next_line.c\
		libft/libft.a\
		ft_printf/ft_printf.a\

$(NAME) :
	make all -C libft
	make all -C ft_printf
	cc $(CFLAGS) $(SRCS) -o $(NAME)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft
	make fclean -C ft_printf

clean :
	make clean -C libft
	make clean -C ft_printf

re : fclean all