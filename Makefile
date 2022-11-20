# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmeulema <jmeulema@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/16 17:42:28 by jmeulema          #+#    #+#              #
#    Updated: 2022/11/19 17:36:56 by jmeulema         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

RM = rm -rf
CC = gcc
FLAGS = -Wall -Wextra -Werror

INC = \
			push_swap.h \

INCS = $(addprefix -I, $(INC))
			
SRCS = \
			SRC/argv_check_utils.c \
			SRC/argv_check_utils_2.c \
			SRC/cmd_push.c \
			SRC/cmd_rev_rotate.c \
			SRC/cmd_rotate.c \
			SRC/cmd_swap.c \
			SRC/do_move.c \
			SRC/ft_split.c \
			SRC/init_cost.c \
			SRC/init_position.c \
			SRC/push_swap.c \
			SRC/sort.c \
			SRC/stack_utils.c \
			SRC/tab.c \
			SRC/utils.c \
			
OBJS = ${SRCS:.c=.o}

all : ${NAME}

$(NAME) : $(OBJS)
		@$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean :
		${RM} ${OBJS}

fclean : clean 
		${RM} ${NAME}

re : fclean all

%.o: %.c
		${CC} ${FLAGS} -o $@ -c $<
