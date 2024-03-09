# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csteylae <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/11 13:24:45 by csteylae          #+#    #+#              #
#    Updated: 2024/03/01 17:46:32 by csteylae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft.a
CC= gcc
CFLAGS= -Wall -Wextra -Werror -g

SRCS= ft_isalpha.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_strlen.c \
	  ft_memset.c \
	  ft_bzero.c \
	  ft_memcpy.c \
	  ft_memmove.c \
	  ft_strlcpy.c \
	  ft_strlcat.c \
	  ft_toupper.c \
	  ft_tolower.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strncmp.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_strnstr.c \
	  ft_atoi.c \
	  ft_calloc.c \
	  ft_strdup.c \
	  ft_substr.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_split.c \
	  ft_itoa.c \
	  ft_strmapi.c \
	  ft_striteri.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_atol.c \

SRCSBONUS= ft_lstnew.c \
		   ft_lstadd_front.c\
		   ft_lstsize.c \
		   ft_lstlast.c\
		   ft_lstadd_back.c\
		#   ft_lstiter.c \
		   ft_lstmap.c
#		   ft_lstdelone.c 
#		    ft_lstclear.c \

OBJSBONUS = $(SRCSBONUS:.c=.o)

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	make -C libftprintf
	ar -rcs $(NAME) $(OBJS) libftprintf/libftprintf.a

bonus : $(OBJS) $(OBJSBONUS)
	make -C libftprintf
	ar -rcs $(NAME) $(OBJS) $(OBJSBONUS) libftprintf/libftprintf.a
	
all: $(NAME)	

clean : 
	rm -f $(OBJS) $(OBJSBONUS)
	make clean -C libftprintf

fclean : clean
	rm -f $(NAME)
	make fclean -C libftprintf

re: fclean all

.PHONY: all clean fclean re


	






