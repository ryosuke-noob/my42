/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:30:06 by nutar             #+#    #+#             */
/*   Updated: 2023/04/18 10:10:09 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (FAILURE);
	init_map(&data, argv[1]);
	check_map(&data.map);
	init_window(&data);
	init_images(&data);
	manage_window(&data);
	return (0);
}

// __attribute__((destructor))
// static void destructor(void){
//     system("leaks -q so_long");
// }
