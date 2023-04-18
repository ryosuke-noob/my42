/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:06:23 by nutar             #+#    #+#             */
/*   Updated: 2023/04/19 00:12:04 by nutar            ###   ########.fr       */
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
	if (i == MAX_HEIGHT || i == 0)
		map_error(&data->map);
	data->map.height = i;
	data->map.width = (int)ft_strlen(data->map.map[0]) - 1;
}

static void	check_pass(const char *pass)
{
	size_t	len;

	len = ft_strlen(pass);
	if (len < 5)
		pass_error();
	if (pass[len - 4] != '.' || pass[len - 3] != 'b' \
			|| pass[len - 2] != 'e' || pass[len - 1] != 'r')
		pass_error();
}

void	init_map(t_data *data, const char *pass)
{
	data->map.cnt_c = 0;
	data->map.cnt_p = 0;
	data->map.cnt_e = 0;
	data->map.cnt_collect = 0;
	data->map.have_newline = YES;
	data->cnt_move = 0;
	check_pass(pass);
	read_map_data(data, pass);
	check_map(&data->map);
}
