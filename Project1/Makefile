NAME = project.a

CC = gcc
CCFLAGS = -Wall -Werror -Wextra
RM = cmd /C del

SRCS = project.c NOR.c XOR.c isNotEqual.c getByte.c Abs.c\

OBJS = ${SRCS:.c=.o}

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

run :
	$(CC) $(SRCS)
	.\a.exe

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean all