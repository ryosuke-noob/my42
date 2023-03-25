/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:34:52 by nutar             #+#    #+#             */
/*   Updated: 2023/03/25 18:22:17 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	create_stack(t_integers	integers)
{
	t_stack	stack;
	t_list	*new;
	int		i;

	stack.stack_a = NULL;
	stack.stack_b = NULL;
	i = -1;
	while (++i < integers.argc)
	{
		new = my_lstnew(integers.array[i]);
		if (new == NULL)
		{
			my_lstclear(&stack.stack_a);
			error_func(integers.array);
		}
		my_lstadd_back(&stack.stack_a, new);
	}
	return (stack);
}
