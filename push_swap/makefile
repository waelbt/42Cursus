LIBFT	:=	libft/libft.a

NAME	:=	push_swap

CHECKER :=	checker

SRC		:=  push_swap.c check_arg.c sort_function.c arg_less_teen.c sort_150.c sort_more_150.c magic.c

OBJ		:=  push_swap.o check_arg.o sort_function.o arg_less_teen.o sort_150.o sort_more_150.o magic.o

SRCB	:=	check_arg_bonus.c sort_function_bonus.c arg_less_teen_bonus.c checker_bonus.c sort_150_bonus.c sort_more_150_bonus.c magic_bonus.c get_next_line_utils_bonus.c get_next_line_bonus.c

OBJB	:=	check_arg_bonus.o sort_function_bonus.o arg_less_teen_bonus.o checker_bonus.o sort_150_bonus.o sort_more_150_bonus.o magic_bonus.o get_next_line_utils_bonus.o get_next_line_bonus.o

CC		:=	gcc

CFLAGS	:=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT) : 
	make -C libft

bonus: $(CHECKER)

$(CHECKER): $(LIBFT) $(OBJB)
	$(CC) $(FLAGS) $(OBJB) $(LIBFT) -o $(CHECKER)

clean:
	@rm -f $(OBJ) $(OBJB)
	make clean -C libft

fclean: clean
	@rm -f $(NAME) $(CHECKER)
	make fclean -C libft

re: fclean all
