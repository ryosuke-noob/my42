/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:30:39 by nutar             #+#    #+#             */
/*   Updated: 2023/04/14 21:33:50 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

//check whether argv is num
//allow first letter is + or -
//do not allow only - or +
//check length of strings
static void	check_all_digits(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		if (argv[i][0] == '-' || argv[i][0] == '+')
			j++;
		while (argv[i][++j] != '\0')
			if (ft_isdigit(argv[i][j]) == FALSE)
				break ;
		if (argv[i][j] != '\0' || j > 11 || ft_isdigit(argv[i][j - 1]) == FALSE)
			error_func(NULL);
	}
}

//check integers fit in int type and return array of integers
static int	*check_int(int argc, char **argv)
{
	int	i;
	int	*array;

	array = malloc(sizeof(int) * (argc - 1));
	if (array == NULL)
		error_func(NULL);
	i = -1;
	while (++i < argc - 1)
		array[i] = ft_atoi_edit(argv[i + 1], array, 0, NULL);
	return (array);
}

//check dupulicate and return middle value of integers
static void	check_duplicate_digits(t_integers *integers)
{
	int	i;
	int	j;

	i = -1;
	while (++i < integers->argc)
	{
		j = i;
		while (++j < integers->argc)
			if (integers->array[i] == integers->array[j])
				error_func(integers->array);
	}
}

//check argv, and return array of integers
//array[0] has middle value of integers
t_integers	arg_check_all(int argc, char **argv)
{
	t_integers	integers;

	check_all_digits(argc, argv);
	integers.array = check_int(argc, argv);
	integers.argc = argc - 1;
	check_duplicate_digits(&integers);
	return (integers);
}
