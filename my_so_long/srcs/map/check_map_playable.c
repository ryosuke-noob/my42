/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_playable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnutaba <rnutaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:58:55 by nutar             #+#    #+#             */
/*   Updated: 2023/04/20 13:29:14 by rnutaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/so_long.h"

//when point is collective, this func is called
//increse cnt of collect, and clear checked status
static void	branch_point_collective(t_map *map)
{
	int	i;
	int	j;

	map->cnt_collect++;
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
			if (map->cp_map[i][j] == CHECKED)
				map->cp_map[i][j] = UNCHECKED;
	}
}

static int	next_point_movable(t_map *map, int i, int j)
{
	if (map->cp_map[i][j] == COLLECTIVE \
				|| map->cp_map[i][j] == UNCHECKED)
		return (1);
	else if (map->cp_map[i][j] == GOAL \
				&& map->cnt_collect == map->cnt_c)
		return (1);
	return (0);
}

//check every point
//if you can reach goal, reutrn SUCCESS
static int	check_point(t_map *map, int i, int j)
{
	if (map->cp_map[i][j] == COLLECTIVE)
		branch_point_collective(map);
	else if (map->cp_map[i][j] == GOAL)
		return (SUCCESS);
	map->cp_map[i][j] = CHECKED;
	if (i + 1 < map->height - 1 && next_point_movable(map, i + 1, j))
		if (check_point(map, i + 1, j) == SUCCESS)
			return (SUCCESS);
	if (i - 1 > 0 && next_point_movable(map, i - 1, j))
		if (check_point(map, i - 1, j) == SUCCESS)
			return (SUCCESS);
	if (j + 1 < map->width - 1 && next_point_movable(map, i, j + 1))
		if (check_point(map, i, j + 1) == SUCCESS)
			return (SUCCESS);
	if (j - 1 > 0 && next_point_movable(map, i, j - 1))
		if (check_point(map, i, j - 1) == SUCCESS)
			return (SUCCESS);
	return (FAILURE);
}

//GOAL == 4
//COLLECOTIVE == 3
//OBJECTIVE == 2
//CHECKED == 1
//UNCHECKED == 0
void	check_map_playable(t_map *map)
{
	if (check_point(map, map->player_i, map->player_j) == FAILURE)
		map_error(map);
}
