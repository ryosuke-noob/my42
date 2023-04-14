/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 22:12:16 by nutar             #+#    #+#             */
/*   Updated: 2023/04/14 16:11:14 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define MAX_HEIGHT 1080
#define MAX_WIDTH 1920
#define UNCHECKED 0
#define CHECKED 1
#define WALL 2
#define COLLECTIVE 3
#define GOAL 4

typedef struct s_map
{
	int		fd;
	int		height;
	int		width;
	char	*map[MAX_HEIGHT];
	int		cnt_p;
	int		cnt_c;
	int		cnt_e;
	int		start_i;
	int		start_j;
	int		cp_map[MAX_HEIGHT][MAX_WIDTH];
	int		cnt_collect;
}	t_map;

void	clear_map(t_map *map)
{
	int	i;

	if (map == NULL)
		return ;
	i = -1;
	while (++i < map->height)
		free(map->map[i]);
}

void	error_map(t_map *map)
{
	clear_map(map);
	printf("Error\n");
	exit(FAILURE);
}

void	copy_map(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width - 1)
		{
			if (map->map[i][j] == '0' || map->map[i][j] == 'P')
				map->cp_map[i][j] = UNCHECKED;
			else if (map->map[i][j] == '1')
				map->cp_map[i][j] = WALL;
			else if (map->map[i][j] == 'C')
				map->cp_map[i][j] = COLLECTIVE;
			else if (map->map[i][j] == 'E')
				map->cp_map[i][j] = GOAL;
		}
	}
}

//get map from .bar file, and init map
void	get_map(int fd, t_map *map)
{
	int		i;

	i = 0;
	map->cnt_c = 0;
	map->cnt_p = 0;
	map->cnt_e = 0;
	map->cnt_collect = 0;
	map->fd = fd;
	i = -1;
	while (++i < MAX_HEIGHT)
	{
		map->map[i] = get_next_line(fd);
		if (map->map[i] == NULL)
			break ;
	}
	map->height = i;
	map->width = (int)ft_strlen(map->map[0]) - 1;
	copy_map(map);
	printf("height:%d width:%d\n", map->height, map->width);
}

//check wether map's width is proper
void	check_map_width(t_map *map)
{
	int		i;

	i = -1;
	while (++i < map->height)
		if ((int)ft_strlen(map->map[i]) != map->width + 1)
			error_map(map);
}

//check map's char is proper
//j < width - 1 because last one is \n
void	check_map_char(t_map *map)
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
				map->start_i = i;
				map->start_j = j;
			}
			else if (map->map[i][j] == 'E')
				map->cnt_e++;
			else if (map->map[i][j] != '0' && map->map[i][j] != '1')
				error_map(map);
		}
	}
	printf("C:%d P:%d E:%d\n", map->cnt_c, map->cnt_p, map->cnt_e);
}

//check the number of C,E,P and whether map is surrounded with 1
void	check_map_components(t_map *map)
{
	int	i;
	int	j;

	if (map->cnt_c == 0)
		error_map(map);
	if (map->cnt_e > 1)
		error_map(map);
	if (map->cnt_p > 1)
		error_map(map);
	i = -1;
	while (++i < map->height)
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
			error_map(map);
	j = -1;
	while (++j < map->width)
		if (map->map[0][j] != '1' || map->map[map->height - 1][j] != '1')
			error_map(map);
}

//whene point is collective, this func is called
//increse cnt of collect, and clear checked status
void	branch_point_collective(t_map *map)
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

int	next_point_movable(t_map *map, int i, int j)
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
int	check_point(t_map *map, int i, int j)
{
	printf("map[%d][%d]:%d\n", i, j, map->cp_map[i][j]);
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
//WALL == 2
//CHECKED == 1
//UNCHECKED == 0
void	check_map_playable(t_map *map)
{
	printf("start:[%d,%d]\n", map->start_i, map->start_j);
	if (check_point(map, map->start_i, map->start_j) == FAILURE)
		error_map(map);
}

void	check_map(int fd)
{
	t_map	map;

	get_map(fd, &map);
	check_map_width(&map);
	check_map_char(&map);
	check_map_components(&map);
	check_map_playable(&map);
	printf("good map\n");
}
