NAME= pipex
CC= cc
CFLAGS= -Wall -Wextra -Werror -g

SRCS= src/utils.c \
	  src/init.c \
	  src/parse_arg.c \
	  src/pipex.c \
	  src/main.c
		
OBJS= $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	make bonus -C lib/libft
	$(CC) $(CFLAGS) -g $(OBJS) -o $(NAME) lib/libft/libft.a lib/libft/ft_printf/libftprintf.a

all : $(NAME)

clean :
	make clean -C lib/libft
	rm -rf $(OBJS)

fclean : clean
	make fclean -C lib/libft
	rm -rf $(NAME)
	rm -rf *.dSYM

re: fclean all

.PHONY: all clean fclean re
