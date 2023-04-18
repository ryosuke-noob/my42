NAME	=	so_long
SRCS	=	./srcs/main.c\
			./srcs/map/init_map.c\
			./srcs/map/get_next_line.c\
			./srcs/map/get_next_line_utils.c\
			./srcs/map/error_map.c\
			./srcs/map/check_map.c\
			./srcs/map/check_map_playable.c\
			./srcs/images/init_images.c\
			./srcs/images/init_window.c\
			./srcs/images/error_images.c\
			./srcs/event/manage_window.c\
			./srcs/event/player_move.c
OBJS	= $(SRCS:.c=.o)
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g -fsanitize=address
IFLAGS	= -I ./includes
LDFLAGS = -L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit
MINILIBX = minilibx-linux/libmlx_Darwin.a

$(NAME): $(OBJS)
	make -C minilibx-linux
	$(CC) $(CFLAGS) $(IFLAGS) $(LDFLAGS) -o $(NAME) $(OBJS) $(MINILIBX)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
