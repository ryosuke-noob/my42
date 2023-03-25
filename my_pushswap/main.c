/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:44:56 by nutar             #+#    #+#             */
/*   Updated: 2023/03/25 16:40:46 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_integers	arg_check(int argc, char **argv)
{
	t_integers	integers;

	if (argc == 1)
		exit(0);
	if (argc == 2)
		integers = arg_2_check_all(argc, argv);
	else
		integers = arg_check_all(argc, argv);
	return (integers);
}

int	main(int argc, char **argv)
{
	int			i;
	t_integers	integers;

	integers = arg_check(argc, argv);




	//check
	i = -1;
	while (++i < integers.argc)
		printf("%d\n", integers.array[i]);
	printf("\n-------------------------\n\n");
	system("leaks -q a.out");
	return (0);
}
