/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:35:51 by nutar             #+#    #+#             */
/*   Updated: 2023/04/17 23:53:49 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/so_long.h"

int	recieve_key(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		close_window(data);
		exit(SUCCESS);
	}
	if (keycode == A || keycode == LARROW)
		case_a(data);
	else if (keycode == W || keycode == UARROW)
		case_w(data);
	else if (keycode == D || keycode == RARROW)
		case_d(data);
	else if (keycode == S || keycode == DARROW)
		case_s(data);
	return (0);
}

int	close_window(t_data *data)
{
	int	i;

	mlx_destroy_image(data->mlx, data->img.collect);
	mlx_destroy_image(data->mlx, data->img.exit);
	mlx_destroy_image(data->mlx, data->img.player);
	mlx_destroy_image(data->mlx, data->img.floor);
	mlx_destroy_image(data->mlx, data->img.wall);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	close(data->map.fd);
	free(data->mlx);
	free(data->win);
	i = -1;
	while (++i < data->map.height)
		free(data->map.map[i]);
	exit(SUCCESS);
}

void	manage_window(t_data *data)
{
	mlx_loop_hook(data->mlx, images_to_win, data);
	mlx_hook(data->win, 2, 1L << 0, recieve_key, data);
	mlx_hook(data->win, 17, 1L << 5, close_window, data);
	mlx_loop(data->mlx);
}
