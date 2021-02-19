# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/16 18:48:30 by azouzoul          #+#    #+#              #
#    Updated: 2021/01/23 16:32:42 by azouzoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	=	ft_isalnum.c ft_isprint.c ft_memcmp.c ft_putchar_fd.c ft_split.c \
			ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
			ft_itoa.c ft_memcpy.c ft_putendl_fd.c ft_strchr.c ft_strlcpy.c \
			ft_strnstr.c ft_tolower.c ft_bzero.c ft_isascii.c ft_memccpy.c \
			ft_memmove.c ft_putnbr_fd.c ft_strdup.c ft_strlen.c ft_strrchr.c \
			ft_toupper.c ft_calloc.c ft_isdigit.c ft_memchr.c ft_memset.c \
			ft_putstr_fd.c ft_strjoin.c ft_strmapi.c ft_strtrim.c \

OBJS	=	${SRCS:.c=.o}

BONUS_S	= ft_lstsize.c ft_lstlast.c ft_lstadd_front.c ft_lstadd_back.c \
			ft_lstnew.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \

BONUS_O	= $(BONUS_S:.c=.o)

CC		=	gcc

CFLAGS = -Wall -Wextra -Werror

AR = ar -rcs

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	${AR} $(NAME) $(OBJS)

all: $(NAME)

bonus:	${OBJS} ${BONUS_O}
	${AR} ${NAME} ${OBJS} ${BONUS_O}

clean:
	rm -f ${OBJS} ${BONUS_O}

fclean:	clean
		rm -f ${NAME} ${BONUS_O}

re:	fclean all

.PHONY:	all clean fclean re bonus
