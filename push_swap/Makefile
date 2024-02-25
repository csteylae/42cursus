# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csteylae <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 13:25:44 by csteylae          #+#    #+#              #
#    Updated: 2024/02/21 17:04:45 by csteylae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap
CC= clang
CFLAGS= -Wall -Wextra -Werror  -fsanitize=address -g

SRCS= init_stack.c \
	  stack_functions.c \
	  operation.c \
	  minisort.c \
	  push_swap_utils.c \
	  push_swap.c \
	 # stack_functions2.c \

OBJS= $(SRCS:.c=.o)

$(NAME) : $(OBJS) 
	make bonus -C libft
	$(CC) $(CFLAGS) -g $(OBJS) -o $(NAME) libft/libft.a libft/libftprintf/libftprintf.a
#	dsymutil $(NAME)

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
