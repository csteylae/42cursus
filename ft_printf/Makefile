# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csteylae <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 14:19:18 by csteylae          #+#    #+#              #
#    Updated: 2023/10/12 18:40:05 by csteylae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libftprintf.a
CC= gcc
CFLAGS= -Wall -Wextra -Werror

SRCS= ft_printf.c \
	  ft_putformat.c \

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

all: $(NAME)

clean :
	rm -f $(OBJS) 

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
