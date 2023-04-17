/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:18:29 by nutar             #+#    #+#             */
/*   Updated: 2023/04/17 23:53:12 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/so_long.h"

void	init_images(t_data *data)
{
	data->img.floor = mlx_xpm_file_to_image(data->mlx, \
				FLOOR, &data->img.width, &data->img.height);
	data->img.wall = mlx_xpm_file_to_image(data->mlx, \
				WALL, &data->img.width, &data->img.height);
	data->img.player = mlx_xpm_file_to_image(data->mlx, \
				PLAYER, &data->img.width, &data->img.height);
	data->img.collect = mlx_xpm_file_to_image(data->mlx, \
				COLLECT, &data->img.width, &data->img.height);
	data->img.exit = mlx_xpm_file_to_image(data->mlx, \
				EXIT, &data->img.width, &data->img.height);
	if (data->img.floor == NULL || data->img.wall == NULL \
		|| data->img.player == NULL || data->img.collect == NULL \
				|| data->img.exit == NULL)
	{
		error_images(data);
	}
}

static void	branch_images_to_win(t_data *data, int i, int j)
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

int	images_to_win(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map.height)
	{
		j = -1;
		while (++j < data->map.width)
		{
			branch_images_to_win(data, i, j);
		}
	}
	return (0);
}
