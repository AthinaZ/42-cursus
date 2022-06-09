NAME1		=	containers

NAME2		=	containers2

HEADER		=	vector.hpp \
				iterator.hpp \
				utils.hpp \
				stack.hpp \
				tree.hpp \
				tree_algo.hpp \
				map.hpp \
				set.hpp \

CC			=	clang++

CFLAGS		=	-Wall -Wextra -Werror -std=c++98 #-g -fsanitize=address

SRCS1		=	main.cpp

SRCS2		=	test.cpp

OBJS1		=	$(SRCS1:.cpp=.o)

OBJS2		=	$(SRCS2:.cpp=.o)

all			:	$(NAME1) $(NAME2)

run			:
				./containers
				./containers2

my_diff:
			@./diff.sh

%.o			:	%.cpp
				$(CC) $(CFLAGS) -c $<

$(NAME1)		:$(OBJS1) $(HEADER)
				$(CC) $(CFLAGS) $(OBJS1) -o $(NAME1)

$(NAME2)		:$(OBJS2)
				$(CC) $(CFLAGS) $(OBJS2) -o $(NAME2)


clean		:
				rm -rf $(OBJS1) $(OBJS2)

fclean		:	clean
				rm -rf $(NAME1) $(NAME2)
				rm -f *.txt

re			:	fclean all

test:			re
				./containers

.PHONY		:	all clean fclean re

