/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 23:33:13 by nutar             #+#    #+#             */
/*   Updated: 2023/04/18 22:56:59 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/so_long.h"

void	destroy_images(t_data *data)
{
	if (data->img.collect != NULL)
		mlx_destroy_image(data->mlx, data->img.collect);
	if (data->img.exit != NULL)
		mlx_destroy_image(data->mlx, data->img.exit);
	if (data->img.player != NULL)
		mlx_destroy_image(data->mlx, data->img.player);
	if (data->img.floor != NULL)
		mlx_destroy_image(data->mlx, data->img.floor);
	if (data->img.wall != NULL)
		mlx_destroy_image(data->mlx, data->img.wall);
}

void	error_images(t_data *data)
{
	int	i;

	destroy_images(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	i = -1;
	while (++i < data->map.height)
		free(data->map.map[i]);
	printf("cannot read images...\nError\n");
	exit(FAILURE);
}
