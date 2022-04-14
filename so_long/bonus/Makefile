NAME	=	so_long

SRCS	=	src/*.c so_long_bouns.c

OBJCT	=	${SRCS:.c=.o}

FLAGES	=	-Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

RM		=	rm -f

CC		=	gcc

all : bonus

bonus : $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(FLAGES) $(SRCS) -o $(NAME)

clean :
	${RM} ${OBJCT}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY:		all clean fclean re bonus