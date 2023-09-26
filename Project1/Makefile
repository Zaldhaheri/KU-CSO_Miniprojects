NAME = project.a

CC = gcc
CCFLAGS = -Wall -Werror -Wextra
RM = cmd /C del

SRCS = project.c functions.c\

OBJS = ${SRCS:.c=.o}

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

run :
	$(CC) $(SRCS)
	./a.out

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean all