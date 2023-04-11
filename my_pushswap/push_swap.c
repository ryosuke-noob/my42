/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:44:56 by nutar             #+#    #+#             */
/*   Updated: 2023/04/11 11:43:21 by nutar            ###   ########.fr       */
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

static void	integers_check(t_integers integers)
{
	int	i;

	i = -1;
	while (++i < integers.argc - 1)
		if (integers.array[i] != integers.array[i + 1] - 1)
			break ;
	if (i == integers.argc - 1)
	{
		if (integers.array != NULL)
			free(integers.array);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_integers	integers;
	t_stack		stack;

	integers = arg_check(argc, argv);
	integers_check(integers);
	stack = create_stack(integers);
	sort(&stack);
	my_lstclear(&stack.stack_a);
	return (0);
}
