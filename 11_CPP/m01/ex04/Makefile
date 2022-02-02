# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/24 16:36:16 by azouzoul          #+#    #+#              #
#    Updated: 2021/09/24 16:36:17 by azouzoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	replace

CC			=	clang++

CFLAGS		=	-Wall -Wextra -Werror -std=c++98

SRCS		=	main.cpp \

OBJS		=	$(SRCS:.cpp=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(HEADER)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean		:
				rm -rf $(OBJS)

fclean		:	clean
				rm -rf $(NAME) test1.replace test2.replace test3.replace

test		:	all
				./$(NAME) test1 the THE
				./$(NAME) test2 hello ciao
				./$(NAME) test3 i y

re			:	fclean all

.PHONY	:	all clean fclean re

