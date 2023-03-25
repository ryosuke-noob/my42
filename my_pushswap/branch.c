/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 21:33:23 by nutar             #+#    #+#             */
/*   Updated: 2023/03/25 22:29:15 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	branch(t_stack *stack)
{
	if (stack->size_a > 6)
	{
	}
	else if (stack->size_a > 3)
	{
		// int		count;
		// int		index;
		// t_list	*tmp;

		// tmp = stack->stack_a;
		// while (tmp->next != NULL)
		// {
		// 	if (tmp->content )
		// }
		// index = stack->stack_a->content;
	}
	else
	{
		int	result;

		result = judge(*stack, 'a');
		if (result == 213 || result == 321 || result == 132 || result == 21)
			sa(stack, 0);
		if (result == 312 || result == 132)
			ra(stack, 0);
		if (result == 321 || result == 231)
			rra(stack, 0);
	}
	return ;
}