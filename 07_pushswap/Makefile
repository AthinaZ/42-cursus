# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/30 16:10:45 by azouzoul          #+#    #+#              #
#    Updated: 2021/04/30 16:10:49 by azouzoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

NAME2 = push_swap

SRCS =  checker.c \
		checker2.c \
		ft_split.c \
		get_next_line.c \
		get_next_line_utils.c \
		operators.c \
		utils.c \
		utils2.c \
		utils3.c \
		ft_itoa.c \
		utils4.c \
		utils5.c

SRCS2 =  push_swap.c \
		push_swap2.c \
		push_swap3.c \
		push_swap4.c \
		push_swap5.c \
		ft_split.c \
		get_next_line.c \
		get_next_line_utils.c \
		operators.c \
		utils.c \
		utils2.c \
		utils3.c \
		ft_itoa.c \
		utils4.c \
		utils5.c

OBJS = $(SRCS:.c=.o)

OBJS2 = $(SRCS2:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: 		$(NAME) $(NAME2)

$(NAME): 	$(OBJS) push_swap.h
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(NAME2): 	$(OBJS2) push_swap.h
			$(CC) $(CFLAGS) -o $(NAME2) $(OBJS2)

clean: 		$(MAKE) clean
			$(RM) $(OBJS) $(OBJS2)

fclean:
			$(RM) $(OBJS) $(OBJS2) $(NAME) $(NAME2)

re: 		fclean $(NAME) $(NAME2)

.PHONY: 	all clean fclean re
