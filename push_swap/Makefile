# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csteylae <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 13:25:44 by csteylae          #+#    #+#              #
#    Updated: 2023/12/12 20:18:14 by csteylae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap
CC= clang
CFLAGS= -Wall -Wextra -Werror -g

SRCS= init_stack.c \
	  circ_lst_fts.c \
	  operation.c \

OBJS= $(SRCS:.c=.o)

$(NAME) : $(OBJS) 
	make bonus -C libft
	$(CC) $(CFLAGS) -g $(OBJS) -o $(NAME) libft/libft.a libft/libftprintf/libftprintf.a
	dsymutil $(NAME)

all : $(NAME)

clean : 
	make clean -C libft
	rm -rf $(OBJS)

fclean : clean
	make fclean -C libft
	rm -rf $(NAME)
	rm -rf $(NAME).dSYM

re: fclean all

.PHONY: all clean fclean re
