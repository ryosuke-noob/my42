NAME	=	so_long
SRCS	=	main.c\
			check_map.c\
			get_next_line.c\
			get_next_line_utils.c
OBJS	= $(SRCS:.c=.o)
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
LDFLAGS = -L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit
MINILIBX = minilibx-linux/libmlx_Darwin.a

$(NAME): $(OBJS)
	make -C minilibx-linux
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME) $(OBJS) $(MINILIBX)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
