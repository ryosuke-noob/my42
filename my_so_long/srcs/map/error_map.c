/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:39:50 by nutar             #+#    #+#             */
/*   Updated: 2023/04/18 23:50:13 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/so_long.h"

void	file_error(void)
{
	perror("cannot open file...\nError\n");
	exit(FAILURE);
}

void	pass_error(void)
{
	perror("pass is incorrect...\nError\n");
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
	printf("map is incorrect...\nError\n");
	exit(FAILURE);
}
