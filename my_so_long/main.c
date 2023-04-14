/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:30:06 by nutar             #+#    #+#             */
/*   Updated: 2023/04/14 15:16:23 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "so_long.h"

int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		return (FAILURE);
	fd = open(argv[1], O_RDONLY);
	// printf("fd:%d\n",fd);
	check_map(fd);
	close(fd);
	return (SUCCESS);
}

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

// // int	main(void)
// // {
// // 	void	*mlx;
// // 	void	*mlx_win;
// // 	t_data	img;
// //
// // 	mlx = mlx_init();
// // 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world");
// // 	img.img = mlx_new_image(mlx, 1920, 1080);
// // 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// // 	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
// // 	// for(int i = 0; i < 100; i++)
// // 	// {
// // 	// 	my_mlx_pixel_put(&img, i, i, 0x00FF0000);
// // 	// }
// // 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// // 	mlx_loop(mlx);
// // }

// int	myclose(int keycode, t_vars *vars)
// {
// 	mlx_destroy_window(vars->mlx, vars->win);
// 	(void)keycode;
// 	return (0);
// }

// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
// 	mlx_hook(vars.win, 2, 1L << 0, myclose, &vars);
// 	mlx_loop(vars.mlx);
// }
