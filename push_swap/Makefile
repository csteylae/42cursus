# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csteylae <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 13:25:44 by csteylae          #+#    #+#              #
#    Updated: 2024/03/06 15:28:50 by csteylae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap
CC= gcc
CFLAGS= -Wall -Wextra -Werror

SRCS= src/init_stack.c \
	  src/parse_str.c \
	  src/stack_functions.c \
	  src/update_index.c \
	  src/operations_push_and_swap.c \
	  src/operations_all_rotations.c \
	  src/minisort.c \
	  src/assigning_target.c \
	  src/assigning_push_price.c \
	  src/apply_good_moves.c \
	  src/push_swap.c \
	  src/main.c \
	  src/print_stack.c \

OBJS= $(SRCS:.c=.o)

$(NAME) : $(OBJS) 
	make bonus -C src/libft
	$(CC) $(CFLAGS) -g $(OBJS) -o $(NAME) src/libft/libft.a src/libft/libftprintf/libftprintf.a

all : $(NAME)

clean : 
	make clean -C src/libft
	rm -rf $(OBJS)

fclean : clean
	make fclean -C src/libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
