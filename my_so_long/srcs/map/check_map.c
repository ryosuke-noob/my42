/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:46:49 by nutar             #+#    #+#             */
/*   Updated: 2023/04/18 09:39:12 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/so_long.h"

//check map's width is proper
static void	check_map_width(t_map *map)
{
	int		i;

	if (map->width >= MAX_WIDTH)
		map_error(map);
	i = -1;
	while (++i < map->height)
	{
		if (map->have_newline == NO && i == map->height - 1)
			continue ;
		if ((int)ft_strlen(map->map[i]) != map->width + 1)
			map_error(map);
	}
}

//check map's char is proper
//j < width - 1 because last one is \n
static void	check_map_char(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width - 1)
		{
			if (map->map[i][j] == 'C')
				map->cnt_c++;
			else if (map->map[i][j] == 'P')
			{
				map->cnt_p++;
				map->player_i = i;
				map->player_j = j;
			}
			else if (map->map[i][j] == 'E')
				map->cnt_e++;
			else if (map->map[i][j] != '0' && map->map[i][j] != '1')
				map_error(map);
		}
	}
}

//check the number of C,E,P and whether map is surrounded with 1
static void	check_map_components(t_map *map)
{
	int	i;
	int	j;

	if (map->cnt_c == 0)
		map_error(map);
	if (map->cnt_e > 1)
		map_error(map);
	if (map->cnt_p > 1)
		map_error(map);
	i = -1;
	while (++i < map->height)
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
			map_error(map);
	j = -1;
	while (++j < map->width)
		if (map->map[0][j] != '1' || map->map[map->height - 1][j] != '1')
			map_error(map);
}

void	check_map(t_map *map)
{
	check_map_width(map);
	check_map_char(map);
	check_map_components(map);
	check_map_playable(map);
}
