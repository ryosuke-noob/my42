/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:30:06 by nutar             #+#    #+#             */
/*   Updated: 2023/04/17 16:35:04 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "so_long.h"

void	init_images(t_data *data)
{
	data->img.floor = mlx_xpm_file_to_image(data->mlx, \
				FLOOR, &data->img.width, &data->img.height);
	// printf("floor: [%d, %d]", data->img.width, data->img.height);
	data->img.wall = mlx_xpm_file_to_image(data->mlx, \
				WALL, &data->img.width, &data->img.height);
	// printf("wall: [%d, %d]", data->img.width, data->img.height);
	data->img.player = mlx_xpm_file_to_image(data->mlx, \
				PLAYER, &data->img.width, &data->img.height);
	// printf("player: [%d, %d]", data->img.width, data->img.height);
	data->img.collect = mlx_xpm_file_to_image(data->mlx, \
				COLLECT, &data->img.width, &data->img.height);
	// printf("collective: [%d, %d]", data->img.width, data->img.height);
	data->img.exit = mlx_xpm_file_to_image(data->mlx, \
				EXIT, &data->img.width, &data->img.height);
	// printf("exit: [%d, %d]", data->img.width, data->img.height);
}

void	case_a(t_data *data)
{
	if (data->map.map[data->map.player_i][data->map.player_j - 1] == '0')
	{
		data->map.map[data->map.player_i][data->map.player_j--] = '0';
		data->map.map[data->map.player_i][data->map.player_j] = 'P';
	}
}

void	case_s(t_data *data)
{
	if (data->map.map[data->map.player_i + 1][data->map.player_j] == '0')
	{
		data->map.map[data->map.player_i++][data->map.player_j] = '0';
		data->map.map[data->map.player_i][data->map.player_j] = 'P';
	}
}

void	case_d(t_data *data)
{
	if (data->map.map[data->map.player_i][data->map.player_j + 1] == '0')
	{
		data->map.map[data->map.player_i][data->map.player_j++] = '0';
		data->map.map[data->map.player_i][data->map.player_j] = 'P';
	}
}

void	case_w(t_data *data)
{
	if (data->map.map[data->map.player_i - 1][data->map.player_j] == '0')
	{
		data->map.map[data->map.player_i--][data->map.player_j] = '0';
		data->map.map[data->map.player_i][data->map.player_j] = 'P';
	}
}

int	recieve_key(int	keycode, t_data *data)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(SUCCESS);
	}
	if (keycode == A || keycode == LARROW)
		case_a(data);
	if (keycode == W || keycode == UARROW)
		case_w(data);
	if (keycode == D || keycode == RARROW)
		case_d(data);
	if (keycode == S || keycode == DARROW)
		case_s(data);
	return (0);
}

int	map_to_win(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map.height)
	{
		j = -1;
		while (++j < data->map.width)
		{
			if (data->map.map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->win, \
					data->img.wall, IMG_SIZE * j, IMG_SIZE * i);
			if (data->map.map[i][j] == '0')
				mlx_put_image_to_window(data->mlx, data->win, \
					data->img.floor, IMG_SIZE * j, IMG_SIZE * i);
			if (data->map.map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, \
					data->img.exit, IMG_SIZE * j, IMG_SIZE * i);
			if (data->map.map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx, data->win, \
					data->img.player, IMG_SIZE * j, IMG_SIZE * i);
			if (data->map.map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, \
					data->img.collect, IMG_SIZE * j, IMG_SIZE * i);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		fd;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	check_map(fd, &data.map);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, IMG_SIZE * data.map.width, \
						IMG_SIZE * data.map.height, "Hello world!");
	init_images(&data);
	// map_to_win(&vars, &map, &data);
	mlx_loop_hook(data.mlx, map_to_win, &data);
	mlx_hook(data.win, 2, 1L << 0, recieve_key, &data);
	mlx_loop(data.mlx);
	close(fd);
	return (0);
}
