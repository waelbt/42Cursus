NAME	=	so_long

SRCS	=	src/*.c so_long.c

OBJCT	=	${SRCS:.c=.o}

FLAGES	=	-Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

RM		=	rm -f

CC		=	gcc

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(FLAGES) $(SRCS) -o $(NAME)

clean :
	${RM} ${OBJCT}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY:		all clean fclean re bonus