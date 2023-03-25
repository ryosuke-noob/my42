/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   judge_sort_case.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 20:44:18 by nutar             #+#    #+#             */
/*   Updated: 2023/03/25 21:14:47 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	judge(t_stack stack, int flag)
{
	t_list	*target;
	t_list	*bottom;

	if (flag == 'a')
		target = stack.stack_a;
	else
		target = stack.stack_b;
	bottom = target;
	while (bottom->next != NULL)
		bottom = bottom->next;
	if (target->content < target->next->content)
	{
		if (target->next->content < bottom->content)
			return (123);
		if (target->content < bottom->content)
			return (132);
		return (231);
	}
	if (target->next->content > bottom->content)
		return (321);
	if (target->content < bottom->content)
		return (213);
	return (312);
}
