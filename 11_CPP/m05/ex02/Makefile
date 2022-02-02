NAME		=	VariousForms

HEADER		=	Bureaucrat.hpp \
				Form.hpp \
				PresidentialPardonForm.hpp \
				RobotomyRequestForm.hpp \
				ShrubberyCreationForm.hpp

CC			=	clang++

CFLAGS		=	-Wall -Wextra -Werror -std=c++98

SRCS		=	main.cpp \
				Bureaucrat.cpp \
				Form.cpp \
				ShrubberyCreationForm.cpp \
				RobotomyRequestForm.cpp \
				PresidentialPardonForm.cpp \

OBJS		=	$(SRCS:.cpp=.o)

all			:	$(NAME)

%.o		:	%.cpp
			$(CC) $(CFLAGS) -c $<

$(NAME)		:	$(OBJS) $(HEADER)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean		:
				rm -rf $(OBJS)

fclean		:	clean
				rm -rf $(NAME)
				rm -f *_shrubbery

re			:	fclean all

.PHONY		:	all clean fclean re
