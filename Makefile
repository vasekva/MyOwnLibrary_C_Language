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

INCLUDES	=	-I ./includes
FIRST_DIR	=	./srcs/first_part/
SECOND_DIR	=	./srcs/second_part/
BONUS_DIR	=	./srcs/bonus_part/
OBJS_DIR	=	./objs/

FIRST_PART	=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
				ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c \
				ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
				ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
				ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
				ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c \

SECOND_PART	=	ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
				ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c \
				ft_putendl_fd.c ft_putnbr_fd.c

BONUS_PART	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
				ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
				ft_lstmap.c \

SRCS		=	$(addprefix $(FIRST_DIR),	$(FIRST_PART))	$(addprefix $(SECOND_DIR), $(SECOND_PART))
OBJS		=	$(addprefix $(OBJS_DIR),	$(FIRST_PART:.c=.o))	$(addprefix $(OBJS_DIR), $(SECOND_PART:.c=.o))
BONUS_SRCS	=	$(addprefix		$(BONUS_DIR),	$(BONUS_PART))
BONUS_OBJS	=	$(addprefix		$(OBJS_DIR),	$(BONUS_PART:.c=.o))

CC = gcc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror -c

all:	$(NAME)

$(NAME):
				mkdir -p $(OBJS_DIR)
				$(CC)  $(INCLUDES) $(CFLAGS) $(SRCS)
				mv $(FIRST_PART:.c=.o) $(OBJS_DIR)
				mv $(SECOND_PART:.c=.o) $(OBJS_DIR)
				ar -rc $(NAME) $(OBJS)
				ranlib $(NAME)

bonus:
				mkdir -p $(OBJS_DIR)
				$(CC)  $(INCLUDES) $(CFLAGS) $(BONUS_SRCS)
				mv $(BONUS_PART:.c=.o)	$(OBJS_DIR)
				ar -rc $(NAME) $(BONUS_OBJS)
				ranlib $(NAME)
clean:
	$(RM) $(OBJS_DIR)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all, clean, fclean, re, bonus
