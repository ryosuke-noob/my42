S_NAME	=	server
S_SRCS	=	./src/server/server.c\
			./src/utils/ft_printf.c\
			./src/utils/ft_print_1.c\
			./src/utils/ft_print_2.c\
			./src/utils/error.c
S_OBJS	= $(S_SRCS:.c=.o)
C_NAME	=	client
C_SRCS	=	./src/client/client.c\
			./src/utils/ft_atoi.c\
			./src/utils/ft_printf.c\
			./src/utils/ft_print_1.c\
			./src/utils/ft_print_2.c\
			./src/utils/error.c
C_OBJS	= $(C_SRCS:.c=.o)
NAME	=	minitalk
CC		= cc
# CFLAGS	= -Wall -Wextra -Werror -g -fsanitize=address
CFLAGS	= -Wall -Wextra -Werror
IFLAGS	 = -I ./includes

$(NAME): $(S_NAME) $(C_NAME)

$(S_NAME): $(S_OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) -o $(S_NAME) $(S_OBJS)

$(C_NAME): $(C_OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) -o $(C_NAME) $(C_OBJS)


all: $(NAME)

clean:
	rm -f $(S_OBJS) $(C_OBJS)

fclean: clean
	rm -f $(S_NAME) $(C_NAME)

re: fclean all

.PHONY: all clean fclean re
