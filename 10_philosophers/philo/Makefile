NAME		=	philo

HEADER		=	./includes/

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -g -I $(HEADER) -pthread

SRCS		=	srcs/main.c \
				srcs/init.c \
				srcs/time_utils.c \
				srcs/utils.c \
				srcs/actions.c \
				srcs/watermark.c \

OBJS		=	$(SRCS:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(HEADER)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean		:
				rm -rf $(OBJS)

fclean		:	clean
				rm -rf $(NAME)

re			:	fclean all
