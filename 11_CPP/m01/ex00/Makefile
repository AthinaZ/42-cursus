# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/22 18:11:08 by azouzoul          #+#    #+#              #
#    Updated: 2021/09/22 18:11:10 by azouzoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Zombies

HEADER		=	Zombie.hpp

CC			=	clang++

CFLAGS		=	-Wall -Wextra -Werror -std=c++98

SRCS		=	main.cpp \
				Zombie.cpp \
				newZombie.cpp \
				randomChump.cpp \

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
