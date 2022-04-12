NAME	=	libftprintf.a

SRCS	=	ft_printf.c ressources_part1.c ft_strlen.c

OBJCT	=	${SRCS:.c=.o}

FLAGES	=	-Wall -Wextra -Werror -c

RM		=	rm -f

CC		=	cc

$(NAME) : $(OBJCT)

%.o : %.c ft_printf.h
	${CC} ${FLAGES} $< 
	ar rcs ${NAME} $@

all : $(NAME)

clean :
	${RM} ${OBJCT}

fclean : clean
	${RM} ${NAME}

re : fclean all
