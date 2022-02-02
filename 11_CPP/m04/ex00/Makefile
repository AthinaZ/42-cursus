# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/03 23:36:06 by azouzoul          #+#    #+#              #
#    Updated: 2021/12/15 22:10:27 by azouzoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Polymorphism

HEADER		=	Animal.hpp \
				Cat.hpp \
				Dog.hpp \
				WrongAnimal.hpp \
				WrongCat.hpp

CC			=	clang++

CFLAGS		=	-Wall -Wextra -Werror -std=c++98

SRCS		=	main.cpp \
				Animal.cpp \
				Cat.cpp \
				Dog.cpp \
				WrongAnimal.cpp \
				WrongCat.cpp

OBJS		=	$(SRCS:.cpp=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(HEADER)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o		:	%.cpp
			$(CC) $(CFLAGS) -c $<

clean		:
				rm -rf $(OBJS)

fclean		:	clean
				rm -rf $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re

