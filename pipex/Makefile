NAME= pipex
CC= gcc
CFLAGS= -Wall -Wextra -Werror -g -fsanitize=address

SRCS= src/utils.c \
	  src/init.c \
	  src/refactorizing_parse_cmd.c 
		
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
