# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/03 23:32:19 by azouzoul          #+#    #+#              #
#    Updated: 2021/10/03 23:32:21 by azouzoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ClapTrap

HEADER		=	ClapTrap.hpp

CC			=	clang++

CFLAGS		=	-Wall -Wextra -Werror -std=c++98

SRCS		=	main.cpp \
				ClapTrap.cpp \

OBJS		=	$(SRCS:.cpp=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(HEADER)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean		:
				rm -rf $(OBJS)

fclean		:	clean
				rm -rf $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re

