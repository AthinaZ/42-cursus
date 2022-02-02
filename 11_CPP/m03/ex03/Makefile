# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/03 23:36:06 by azouzoul          #+#    #+#              #
#    Updated: 2021/10/03 23:36:08 by azouzoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	DiamondTrap

HEADER		=	ClapTrap.hpp \
				ScavTrap.hpp \
				FragTrap.hpp \
				DiamondTrap.hpp

CC			=	clang++

CFLAGS		=	-Wall -Wextra -Werror -std=c++98 -Wshadow -Wno-shadow

SRCS		=	main.cpp \
				ClapTrap.cpp \
				ScavTrap.cpp \
				FragTrap.cpp \
				DiamondTrap.cpp

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

