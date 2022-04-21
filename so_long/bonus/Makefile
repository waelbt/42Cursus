NAME	=	so_long

SRCS	=	src/*.c so_long_bonus.c

OBJCT	=	${SRCS:.c=.o}

FLAGES	=	-L./minilibx -lmlx -lXext -lX11

RM		=	rm -f

CC		=	gcc -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(SRCS) $(FLAGES) -o $(NAME)

clean :
	${RM} ${OBJCT}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY:		all clean fclean re bonus
