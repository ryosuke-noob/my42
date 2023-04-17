/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:30:06 by nutar             #+#    #+#             */
/*   Updated: 2023/04/17 23:55:19 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/so_long.h"

// void	init_images(t_data *data)
// {
// 	data->img.floor = mlx_xpm_file_to_image(data->mlx, \
// 				FLOOR, &data->img.width, &data->img.height);
// 	data->img.wall = mlx_xpm_file_to_image(data->mlx, \
// 				WALL, &data->img.width, &data->img.height);
// 	data->img.player = mlx_xpm_file_to_image(data->mlx, \
// 				PLAYER, &data->img.width, &data->img.height);
// 	data->img.collect = mlx_xpm_file_to_image(data->mlx, \
// 				COLLECT, &data->img.width, &data->img.height);
// 	data->img.exit = mlx_xpm_file_to_image(data->mlx, \
// 				EXIT, &data->img.width, &data->img.height);
// }

// int	recieve_key(int keycode, t_data *data)
// {
// 	if (keycode == ESC)
// 	{
// 		mlx_destroy_window(data->mlx, data->win);
// 		exit(SUCCESS);
// 	}
// 	if (keycode == A || keycode == LARROW)
// 		case_a(data);
// 	else if (keycode == W || keycode == UARROW)
// 		case_w(data);
// 	else if (keycode == D || keycode == RARROW)
// 		case_d(data);
// 	else if (keycode == S || keycode == DARROW)
// 		case_s(data);
// 	return (0);
// }

// int	map_to_win(t_data *data)
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	while (++i < data->map.height)
// 	{
// 		j = -1;
// 		while (++j < data->map.width)
// 		{
// 			if (data->map.map[i][j] == '1')
// 				mlx_put_image_to_window(data->mlx, data->win, \
// 					data->img.wall, IMG_SIZE * j, IMG_SIZE * i);
// 			if (data->map.map[i][j] == '0')
// 				mlx_put_image_to_window(data->mlx, data->win, \
// 					data->img.floor, IMG_SIZE * j, IMG_SIZE * i);
// 			if (data->map.map[i][j] == 'E')
// 				mlx_put_image_to_window(data->mlx, data->win, \
// 					data->img.exit, IMG_SIZE * j, IMG_SIZE * i);
// 			if (data->map.map[i][j] == 'P')
// 				mlx_put_image_to_window(data->mlx, data->win, \
// 					data->img.player, IMG_SIZE * j, IMG_SIZE * i);
// 			if (data->map.map[i][j] == 'C')
// 				mlx_put_image_to_window(data->mlx, data->win, \
// 					data->img.collect, IMG_SIZE * j, IMG_SIZE * i);
// 		}
// 	}
// 	return (0);
// }

// int	close_window(t_data *data)
// {
// 	int	i;

// 	mlx_destroy_image(data->mlx, data->img.collect);
// 	mlx_destroy_image(data->mlx, data->img.exit);
// 	mlx_destroy_image(data->mlx, data->img.player);
// 	mlx_destroy_image(data->mlx, data->img.floor);
// 	mlx_destroy_image(data->mlx, data->img.wall);
// 	mlx_destroy_window(data->mlx, data->win);
// 	mlx_destroy_display(data->mlx);
// 	close(data->map.fd);
// 	free(data->mlx);
// 	free(data->win);
// 	i = -1;
// 	while (++i < data->map.height)
// 		free(data->map.map[i]);
// 	exit(SUCCESS);
// }

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (FAILURE);
	init_map(&data, argv[1]);
	check_map(&data.map);
	init_window(&data);
	init_images(&data);
	manage_window(&data);
	return (0);
}

__attribute__((destructor))
static void destructor(void){
    system("leaks -q so_long");
}