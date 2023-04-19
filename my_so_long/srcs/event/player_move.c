/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:19:42 by nutar             #+#    #+#             */
/*   Updated: 2023/04/19 11:34:58 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/so_long.h"

void	case_a(t_data *data)
{
	if (data->map.map[data->map.player_i][data->map.player_j - 1] == 'C')
	{
		data->map.map[data->map.player_i][data->map.player_j--] = '0';
		data->map.map[data->map.player_i][data->map.player_j] = 'P';
		data->map.cnt_collect--;
		ft_printf("%d\n", ++data->cnt_move);
	}
	else if (data->map.map[data->map.player_i][data->map.player_j - 1] == 'E')
	{
		if (data->map.cnt_collect != 0)
			return ;
		ft_printf("%d\n", ++data->cnt_move);
		ft_printf("clear!!\n");
		close_window(data);
		exit(SUCCESS);
	}
	else if (data->map.map[data->map.player_i][data->map.player_j - 1] == '0')
	{
		data->map.map[data->map.player_i][data->map.player_j--] = '0';
		data->map.map[data->map.player_i][data->map.player_j] = 'P';
		ft_printf("%d\n", ++data->cnt_move);
	}
}

void	case_s(t_data *data)
{
	if (data->map.map[data->map.player_i + 1][data->map.player_j] == 'C')
	{
		data->map.map[data->map.player_i++][data->map.player_j] = '0';
		data->map.map[data->map.player_i][data->map.player_j] = 'P';
		data->map.cnt_collect--;
		ft_printf("%d\n", ++data->cnt_move);
	}
	else if (data->map.map[data->map.player_i + 1][data->map.player_j] == 'E')
	{
		if (data->map.cnt_collect != 0)
			return ;
		ft_printf("%d\n", ++data->cnt_move);
		ft_printf("clear\n");
		close_window(data);
		exit(SUCCESS);
	}
	else if (data->map.map[data->map.player_i + 1][data->map.player_j] == '0')
	{
		data->map.map[data->map.player_i++][data->map.player_j] = '0';
		data->map.map[data->map.player_i][data->map.player_j] = 'P';
		ft_printf("%d\n", ++data->cnt_move);
	}
}

void	case_d(t_data *data)
{
	if (data->map.map[data->map.player_i][data->map.player_j + 1] == 'C')
	{
		data->map.map[data->map.player_i][data->map.player_j++] = '0';
		data->map.map[data->map.player_i][data->map.player_j] = 'P';
		data->map.cnt_collect--;
		ft_printf("%d\n", ++data->cnt_move);
	}
	else if (data->map.map[data->map.player_i][data->map.player_j + 1] == 'E')
	{
		if (data->map.cnt_collect != 0)
			return ;
		ft_printf("%d\n", ++data->cnt_move);
		ft_printf("clear\n");
		close_window(data);
		exit(SUCCESS);
	}
	else if (data->map.map[data->map.player_i][data->map.player_j + 1] == '0')
	{
		data->map.map[data->map.player_i][data->map.player_j++] = '0';
		data->map.map[data->map.player_i][data->map.player_j] = 'P';
		ft_printf("%d\n", ++data->cnt_move);
	}
}

void	case_w(t_data *data)
{
	if (data->map.map[data->map.player_i - 1][data->map.player_j] == 'C')
	{
		data->map.map[data->map.player_i--][data->map.player_j] = '0';
		data->map.map[data->map.player_i][data->map.player_j] = 'P';
		data->map.cnt_collect--;
		ft_printf("%d\n", ++data->cnt_move);
	}
	else if (data->map.map[data->map.player_i - 1][data->map.player_j] == 'E')
	{
		if (data->map.cnt_collect != 0)
			return ;
		ft_printf("%d\n", ++data->cnt_move);
		ft_printf("clear\n");
		close_window(data);
		exit(SUCCESS);
	}
	else if (data->map.map[data->map.player_i - 1][data->map.player_j] == '0')
	{
		data->map.map[data->map.player_i--][data->map.player_j] = '0';
		data->map.map[data->map.player_i][data->map.player_j] = 'P';
		ft_printf("%d\n", ++data->cnt_move);
	}
}
