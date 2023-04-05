/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_2_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:30:39 by nutar             #+#    #+#             */
/*   Updated: 2023/04/06 00:09:12 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	error_func_2(int *array, int argc, char **argv)
{
	int	i;

	if (array != NULL)
		free(array);
	if (argv != NULL)
	{
		i = -1;
		while (++i <= argc)
			free(argv[i]);
		free(argv);
	}
	write(1, "Error\n", 7);
	exit(1);
}

//check whether argv is num
//allow first letter is + or -
//check length of strings
static void	check_all_digits_2(int argc, char **argv)
{
	int	i;
	int	j;

	i = -1;
	while (++i < argc)
	{
		j = -1;
		if (argv[i][0] == '-' || argv[i][0] == '+')
			j++;
		while (argv[i][++j] != '\0')
			if (ft_isdigit(argv[i][j]) == FALSE)
				break ;
		if (argv[i][j] != '\0' || j > 11 || ft_isdigit(argv[i][j - 1]) == FALSE)
			error_func_2(NULL, argc, argv);
	}
}

//check integers fit in int type and return array of integers
static int	*check_int_2(int argc, char **argv)
{
	int	i;
	int	*array;

	array = malloc(sizeof(int) * argc);
	if (array == NULL)
		error_func_2(NULL, argc, argv);
	i = -1;
	while (++i < argc)
		array[i] = ft_atoi_edit(argv[i], array);
	return (array);
}

//check dupulicate
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
t_integers	arg_2_check_all(int argc, char **argv)
{
	t_integers	integers;
	char		**re_argv;
	int			i;

	re_argv = ft_split(argv[1], ' ');
	if (re_argv == NULL)
		error_func(NULL);
	argc = 0;
	while (re_argv[argc] != NULL)
		argc++;
	check_all_digits_2(argc, re_argv);
	integers.array = check_int_2(argc, re_argv);
	i = -1;
	while (++i <= argc)
		free(re_argv[i]);
	free(re_argv);
	integers.argc = argc;
	check_duplicate_digits(&integers);
	return (integers);
}
