/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:30:06 by nutar             #+#    #+#             */
/*   Updated: 2023/04/17 15:27:21 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "so_long.h"

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;
//
// 	dst = data.addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }
//
// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;
//
// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world");
// 	img.img = mlx_new_image(mlx, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// 	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
// 	// for(int i = 0; i < 100; i++)
// 	// {
// 	// 	my_mlx_pixel_put(&img, i, i, 0x00FF0000);
// 	// }
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// }

void	init_images( t_vars *vars, t_data *data, t_map *map)
{
	data->img.floor = mlx_xpm_file_to_image(vars->mlx, \
				FLOOR, &data->img.width, &data->img.height);
	// printf("floor: [%d, %d]", data->img.width, data->img.height);
	data->img.wall = mlx_xpm_file_to_image(vars->mlx, \
				WALL, &data->img.width, &data->img.height);
	// printf("wall: [%d, %d]", data->img.width, data->img.height);
	data->img.player = mlx_xpm_file_to_image(vars->mlx, \
				PLAYER, &data->img.width, &data->img.height);
	// printf("player: [%d, %d]", data->img.width, data->img.height);
	data->img.collect = mlx_xpm_file_to_image(vars->mlx, \
				COLLECT, &data->img.width, &data->img.height);
	// printf("collective: [%d, %d]", data->img.width, data->img.height);
	data->img.exit = mlx_xpm_file_to_image(vars->mlx, \
				EXIT, &data->img.width, &data->img.height);
	// printf("exit: [%d, %d]", data->img.width, data->img.height);
	data->img.height = WIN_H / map->height;
	data->img.width = WIN_W / map->width;
}

void	case_a(void)
{

}

void	case_s(void)
{

}

void	case_d(void)
{

}

void	case_w(void)
{

}

int	recieve_key(int	keycode, t_vars *vars)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(SUCCESS);
	}
	if (keycode == A || keycode == LARROW)
		case_a();
	if (keycode == W || keycode == UARROW)
		case_w();
	if (keycode == D || keycode == RARROW)
		case_d();
	if (keycode == S || keycode == DARROW)
		case_s();
	return (0);
}

void	map_to_win(t_vars *vars, t_map *map, t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, \
				data->img.floor, IMG_SIZE * j, IMG_SIZE * i);
		}
	}
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_data	data;
	t_map	map;
	int		fd;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	check_map(fd, &map);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_W, WIN_H, "Hello world!");
	init_images(&vars, &data, &map);
	map_to_win(&vars, &map, &data);
	mlx_hook(vars.win, 2, 1L << 0, recieve_key, &vars);
	mlx_loop(vars.mlx);
	close(fd);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	int	fd;

// 	if (argc != 2)
// 		return (FAILURE);
// 	fd = open(argv[1], O_RDONLY);
// 	// printf("fd:%d\n",fd);
// 	check_map(fd);
// 	close(fd);
// 	return (SUCCESS);
// }
