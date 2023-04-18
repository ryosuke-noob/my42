/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:31:24 by nutar             #+#    #+#             */
/*   Updated: 2023/04/18 09:30:08 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>
# include "../minilibx-linux/mlx.h"
# include "./get_next_line.h"

//general
# define SUCCESS 0
# define FAILURE 1
# define YES 1
# define NO 0

//map
// # define MAX_HEIGHT 1080/16 - 13
// # define MAX_WIDTH 1920/16 - 29
# define MAX_HEIGHT 54
# define MAX_WIDTH 91
# define UNCHECKED 0
# define CHECKED 1
# define OBJECTIVE 2
# define COLLECTIVE 3
# define GOAL 4

//images
# define IMG_SIZE 16
# define FLOOR "./images/Edge_single.xpm"
# define WALL "./images/Wall_front.xpm"
# define EXIT "./images/Floor_ladder.xpm"
# define COLLECT "./images/weapon_bomb.xpm"
# define PLAYER "./images/hero_basic.xpm"

//keycode
# define ESC 65307
# define A 97
# define D 100
# define S 115
# define W 119
# define LARROW 65361
# define UARROW 65362
# define RARROW 65363
# define DARROW 65364

typedef struct s_img
{
	int		height;
	int		width;
	void	*floor;
	void	*exit;
	void	*wall;
	void	*player;
	void	*collect;
}	t_img;

typedef struct s_map
{
	int		fd;
	int		height;
	int		width;
	int		cnt_p;
	int		cnt_c;
	int		cnt_e;
	int		player_i;
	int		player_j;
	char	*map[MAX_HEIGHT + 1];
	int		cp_map[MAX_HEIGHT][MAX_WIDTH];
	int		cnt_collect;
	int		have_newline;
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_map	map;
	int		cnt_move;
}	t_data;

//map
void	init_map(t_data *data, const char *pass);
void	file_error(void);
void	map_error(t_map *map);
void	check_map_playable(t_map *map);
void	check_map(t_map *map);
char	*get_next_line(int fd);

//images
void	init_images(t_data *data);
int		images_to_win(t_data *data);
void	init_window(t_data *data);
void	error_images(t_data *data);
void	destroy_images(t_data *data);

//event
void	manage_window(t_data *data);
int		close_window(t_data *data);
int		recieve_key(int keycode, t_data *data);
void	case_a(t_data *data);
void	case_s(t_data *data);
void	case_w(t_data *data);
void	case_d(t_data *data);

#endif