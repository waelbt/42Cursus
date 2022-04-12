SERVER	= 	server

CLIENT =	client

PRINTF	=	ft_printf/libftprintf.a

C_SRCS	=	client.c ft_atoi.c $(PRINTF)

S_SRCS	=	server.c $(PRINTF)

C_OBJCT	=	${C_SRCS:.c=.o}

S_OBJCT	=	${S_SRCS:.c=.o}

RM		=	rm -f

CCW		=	cc -Wextra -Wall -Werror

all	: $(SERVER) $(CLIENT)


$(SERVER) : $(S_OBJCT) $(PRINTF)
	$(CCW) $(S_OBJCT) -o $(SERVER)

$(CLIENT) : $(C_OBJCT) $(PRINTF)
	$(CCW) $(C_OBJCT) -o $(CLIENT)

$(PRINTF) : 
	make -C ft_printf

clean :
	${RM} ${C_OBJCT}
	${RM} ${S_OBJCT}
	make clean -C ft_printf

fclean : clean
	${RM} ${SERVER}
	${RM} ${CLIENT}
	make fclean -C ft_printf

re : fclean all
