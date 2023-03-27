/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:34:52 by nutar             #+#    #+#             */
/*   Updated: 2023/03/27 17:33:56 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ret_number(t_integers integers, int content)
{
	int	i;
	int	number;

	number = 1;
	i = -1;
	while (++i < integers.argc)
		if (content > integers.array[i])
			number++;
	return (number);
}

t_stack	create_stack(t_integers	integers)
{
	t_stack	stack;
	t_list	*new;
	int		i;

	stack.stack_a = NULL;
	stack.stack_b = NULL;
	stack.size_a = integers.argc;
	stack.size_b = 0;
	i = -1;
	while (++i < integers.argc)
	{
		new = my_lstnew(integers.array[i], \
							ret_number(integers, integers.array[i]));
		if (new == NULL)
		{
			my_lstclear(&stack.stack_a);
			error_func(integers.array);
		}
		my_lstadd_back(&stack.stack_a, new);
	}
	return (stack);
}
