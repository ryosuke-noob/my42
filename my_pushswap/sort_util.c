/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:05:12 by nutar             #+#    #+#             */
/*   Updated: 2023/04/05 17:22:22 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//count added because of line restrict
int	count_min(t_stack *stack, int size, int min, int count)
{
	int		i;
	t_list	*tmp;

	tmp = stack->stack_b;
	i = -1;
	while (++i < size)
	{
		if (tmp->number == min + count)
			count++;
		else if (i < size - 1 && judge_2_1(tmp, min + count))
		{
			count += 2;
			tmp = tmp->next;
			i++;
		}
		else if (i < size - 2 && judge_3_1(tmp, min + count))
		{
			count += 2;
			tmp = tmp->next->next;
			i += 2;
		}
		tmp = tmp->next;
	}
	return (count);
}

int	count_last_max(t_stack *stack, int size, int max)
{
	int		i;
	int		count;
	t_list	*tmp;

	tmp = stack->stack_a;
	i = -1;
	count = 0;
	while (++i < size)
	{
		if (tmp->number == max - size + i + 1)
			count++;
		else
			count *= 0;
		if (tmp->next != NULL)
			tmp = tmp->next;
	}
	return (count);
}

int	judge_2_1(t_list *tmp, int min)
{
	if (tmp->number == min + 1 && tmp->next->number == min)
		return (1);
	return (0);
}

int	judge_3_1(t_list *tmp, int min)
{
	if (tmp->number == min + 1 && tmp->next->next->number == min)
		return (1);
	return (0);
}
