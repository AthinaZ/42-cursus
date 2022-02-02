# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/28 16:51:48 by azouzoul          #+#    #+#              #
#    Updated: 2022/01/28 16:51:51 by azouzoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	array

HEADER		=	Array.hpp \

CC			=	clang++

CFLAGS		=	-Wall -Wextra -Werror -std=c++98

SRCS		=	main.cpp \

OBJS		=	$(SRCS:.cpp=.o)

all			:	$(NAME)

%.o			:	%.cpp
				$(CC) $(CFLAGS) -c $<

$(NAME)		:	$(OBJS) $(HEADER)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean		:
				rm -rf $(OBJS)

fclean		:	clean
				rm -rf $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re
