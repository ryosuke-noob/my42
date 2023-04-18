/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:06:23 by nutar             #+#    #+#             */
/*   Updated: 2023/04/18 09:20:53 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/so_long.h"

static void	read_map_data(t_data *data, const char *pass)
{
	int	i;

	data->map.fd = open(pass, O_RDONLY);
	if (data->map.fd == -1)
		file_error();
	i = -1;
	while (++i < MAX_HEIGHT + 1)
	{
		data->map.map[i] = get_next_line(data->map.fd);
		if (data->map.map[i] == NULL)
			break ;
		if (data->map.map[i][ft_strlen(data->map.map[i]) - 1] != '\n')
			data->map.have_newline = NO;
	}
	close(data->map.fd);
	if (i == MAX_HEIGHT)
		map_error(&data->map);
	data->map.height = i;
	data->map.width = (int)ft_strlen(data->map.map[0]) - 1;
}

//copy map into integer arrays
//CHECKED == 1
//OBJECTIVE == 2
//COLLECOTIVE == 3
//GOAL == 4
//UNCHECKED == 0
static void	copy_map(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->map[i][j] == '0' || map->map[i][j] == 'P')
				map->cp_map[i][j] = UNCHECKED;
			else if (map->map[i][j] == '1')
				map->cp_map[i][j] = OBJECTIVE;
			else if (map->map[i][j] == 'C')
				map->cp_map[i][j] = COLLECTIVE;
			else if (map->map[i][j] == 'E')
				map->cp_map[i][j] = GOAL;
		}
	}
}

void	init_map(t_data *data, const char *pass)
{
	data->map.cnt_c = 0;
	data->map.cnt_p = 0;
	data->map.cnt_e = 0;
	data->map.cnt_collect = 0;
	data->map.have_newline = YES;
	data->cnt_move = 0;
	read_map_data(data, pass);
	copy_map(&data->map);
}
