# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/01 19:47:14 by jberegon          #+#    #+#              #
#    Updated: 2020/11/10 20:07:32 by jberegon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
	  ft_memcpy.c ft_memmove.c ft_memset.c ft_strlen.c ft_strlcat.c 		\
	  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c 		\
	  ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strdup.c 		\
	  ft_calloc.c ft_strlcpy.c ft_strncmp.c ft_strnstr.c ft_substr.c 		\
	  ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c		\
	  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c

OBJS = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = gcc -c $(CFLAGS)

all:	$(NAME)

$(NAME):	$(OBJS)
	ar -rc	$(NAME) $(OBJS)
	ranlib	$(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean:	clean
	/bin/rm -f $(NAME)

re:	fclean all

.PHONY: all, clean, fclean, re

norme:
	norminette -R CheckForbiddenSourceHeader $(SRC)
