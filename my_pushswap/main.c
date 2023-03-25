/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:44:56 by nutar             #+#    #+#             */
/*   Updated: 2023/03/25 19:15:27 by nutar            ###   ########.fr       */
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
	t_integers	integers;
	t_stack		stack;

	//arg
	integers = arg_check(argc, argv);

	//stack
	stack = create_stack(integers);




	//check integers
	printf("[check integers]\n");
	int			i;
	i = -1;
	while (++i < integers.argc)
		printf("%d ", integers.array[i]);
	printf("\n");

	//check stack
	printf("[check stack: BEFORE]\n");
	t_list	*tmp;
	tmp = stack.stack_a;
	while (tmp)
	{
		printf("%d ", tmp->content);
		tmp = tmp->next;
	}
	printf("\n");

	ss(&stack);

	printf("[check stack: AFTER]\n");
	tmp = stack.stack_a;
	while (tmp)
	{
		printf("%d ", tmp->content);
		tmp = tmp->next;
	}
	printf("\n");
	//check leaks
	// printf("\n-------------------------\n\n");
	// system("leaks -q a.out");
	return (0);
}