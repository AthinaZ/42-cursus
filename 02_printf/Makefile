# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/08 17:12:29 by azouzoul          #+#    #+#              #
#    Updated: 2021/02/08 17:12:32 by azouzoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=	./srcs/*.c ./libft/*.c

OBJ		= $(SRCS:.c=.o)
FLAGS	= gcc -c -Wall -Wextra -Werror
HEADER	= include/

all: $(NAME)

$(NAME):
	$(FLAGS) -c -I$(HEADER) -I ./libft $(SRCS)
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
