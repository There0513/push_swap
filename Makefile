# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: threiss <threiss@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/20 15:59:28 by threiss           #+#    #+#              #
#    Updated: 2021/10/14 16:56:18 by threiss          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_PATH	=	./srcs/

SRCS_NAMES	=	main.c \
				operations.c \
				sort_five.c \
				sort_hund.c \
				sort_more.c \
				utils_struct.c \
				utils_sort.c \
				error_handling.c \
				lsts.c \
				lsts2.c \
				push_checker.c \
			
SRCS_NAMES_BONUS	=	checker.c \
				get_next_line.c \

INCL	=	./includes/

NAME	= 	push_swap
NAME_BONUS	= 	checker

CC	=	clang

RM	=	rm -f

CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	$(addprefix $(SRCS_PATH), $(SRCS_NAMES))

SRCS_BONUS	=	$(addprefix $(SRCS_PATH), $(SRCS_NAMES_BONUS))

OBJS	=	${SRCS:.c=.o}

OBJS_BONUS	=	${filter-out ${addprefix $(SRCS_PATH), main.o}, ${OBJS}}	${SRCS_BONUS:.c=.o}

.c.o:
		@${CC} ${CFLAGS} -I$(INCL) -c $< -o ${<:.c=.o} # ?!

$(NAME):	${OBJS}
			@make --silent -C ./libft/
			${CC} ${CFLAGS} ${OBJS} libft/libft.a -I${INCL} -o ${NAME}

$(NAME_BONUS):	${OBJS_BONUS}
			@make --silent -C ./libft/
			${CC} ${CFLAGS} ${OBJS_BONUS} libft/libft.a -I${INCL} -o ${NAME_BONUS}

all:		${NAME}

clean:
		${RM} ${OBJS}
		${RM} ${OBJS_BONUS}
		@make --silent -C ./libft clean

fclean:		clean
		${RM} ${NAME} ${NAME_BONUS}

re:		fclean all checker

.PHONY:
		all clean fclean re
