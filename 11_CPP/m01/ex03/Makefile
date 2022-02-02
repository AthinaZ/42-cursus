# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/23 16:24:06 by azouzoul          #+#    #+#              #
#    Updated: 2021/09/23 16:24:07 by azouzoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Weapon

HEADER		=	Weapon.hpp \
				HumanA.hpp \
				HumanB.hpp 

CC			=	clang++

CFLAGS		=	-Wall -Wextra -Werror -std=c++98

SRCS		=	main.cpp \
				HumanA.cpp \
				Weapon.cpp \
				HumanB.cpp

OBJS		=	$(SRCS:.cpp=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(HEADER)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean		:
				rm -rf $(OBJS)

fclean		:	clean
				rm -rf $(NAME)

re			:	fclean all

.PHONY	:	all clean fclean re
