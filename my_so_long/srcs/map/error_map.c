/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnutaba <rnutaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:39:50 by nutar             #+#    #+#             */
/*   Updated: 2023/04/20 13:55:14 by rnutaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/so_long.h"

void	file_error(void)
{
	ft_printf("cannot open file...\nError\n");
	exit(FAILURE);
}

void	pass_error(void)
{
	ft_printf("pass is incorrect...\nError\n");
	exit(FAILURE);
}

void	map_error(t_map *map)
{
	int	i;

	if (map == NULL)
		return ;
	i = -1;
	while (++i < map->height)
		free(map->map[i]);
	ft_printf("map is incorrect...\nError\n");
	exit(FAILURE);
}
