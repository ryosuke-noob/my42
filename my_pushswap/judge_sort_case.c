/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   judge_sort_case.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 20:44:18 by nutar             #+#    #+#             */
/*   Updated: 2023/03/25 22:17:56 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	judge_3(t_list *target)
{
	t_list	*bottom;

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

static int	judge_2(t_list *target)
{
	if (target->content < target->next->content)
		return (12);
	return (21);
}

int	judge(t_stack stack, int flag)
{
	t_list	*target;
	int		target_size;

	if (flag == 'a')
	{
		target = stack.stack_a;
		target_size = stack.size_a;
	}
	else
	{
		target = stack.stack_b;
		target_size = stack.size_b;
	}
	if (target_size == 1)
		return (1);
	if (target_size == 2)
		return (judge_2(target));
	return (judge_3(target));
}
