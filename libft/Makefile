# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: threiss <threiss@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/16 11:59:43 by threiss           #+#    #+#              #
#    Updated: 2021/10/24 22:26:41 by threiss          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_atoll.c \
	  ft_bzero.c \
	  ft_calloc.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_itoa.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_putchar_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_putstr_fd.c \
	  ft_split.c \
	  ft_strchr.c \
	  ft_strdup.c \
	  ft_strjoin.c \
	  ft_strlcat.c \
	  ft_strlcpy.c \
	  ft_strlen.c \
	  ft_strmapi.c \
	  ft_strncmp.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strtrim.c \
	  ft_substr.c \
	  ft_tolower.c \
	  ft_toupper.c \
		ft_lstadd_back.c \
	     ft_lstadd_front.c \
	     ft_lstclear.c \
	     ft_lstlast.c \
	     ft_lstnew.c \
	     ft_lstsize.c \

OBJS	= ${SRCS:.c=.o}

BONUS_OBJS = ${BONUS_SRCS:.c=.o}

NAME	= libft.a

CC	= clang

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS} libft.h
	ar rc ${NAME} ${OBJS}

all:	${NAME}

bonus:	${OBJS} ${BONUS_OBJS} libft.h
	ar rc ${NAME} ${OBJS} ${BONUS_OBJS}

clean:
	${RM} ${OBJS} ${BONUS_OBJS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all bonus

.PHONY:
	all clean fclean re bonus
