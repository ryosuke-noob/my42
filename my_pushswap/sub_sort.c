/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:42:20 by nutar             #+#    #+#             */
/*   Updated: 2023/04/05 18:35:34 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	top_sort_min(t_stack *stack, int *min, int mid, int *i)
{
	t_list	*tmp;

	pa(stack);
	(*min)++;
	tmp = stack->stack_b;
	if (tmp != NULL && tmp->number != *min && tmp->number < mid)
	{
		rr(stack);
		(*i)++;
	}
	else
		ra(stack, 'a');
}

static void	top_sort(t_stack *stack, int *size, int *max, int *min)
{
	int	i;
	int	tmp_min;
	int	count;

	i = -1;
	count = count_min(stack, *size, *min, 0);
	tmp_min = *min + count;
	while (++i < *size)
	{
		if (i < *size - 2 && judge_3_1(stack->stack_b, *min))
			sb(stack, 'b');
		if (i < *size - 1 && judge_2_1(stack->stack_b, *min))
			sb(stack, 'b');
		if (stack->stack_b->number == *min)
			top_sort_min(stack, min, (*size - count) / 2 + tmp_min, &i);
		else if (stack->stack_b->number >= (*size - count) / 2 + tmp_min)
			pa(stack);
		else
			rb(stack, 'b');
	}
	*size -= count;
	sub_sort(stack, stack->size_b, *max - *size / 2 - *size % 2, *min);
	*min = tmp_min + *size / 2;
}

static void	bottom_sort(t_stack *stack, int *size, int *max, int *min)
{
	int	i;
	int	cnt_max;

	i = -1;
	cnt_max = count_last_max(stack, *size, *max);
	while (++i < *size - cnt_max)
	{
		if (i < *size - cnt_max - 1 && judge_2_1(stack->stack_a, *min))
			sa(stack, 'a');
		if (stack->stack_a->number == *min)
		{
			ra(stack, 'a');
			(*min)++;
		}
		else
			pb(stack);
	}
	sub_sort(stack, stack->size_b, *max - cnt_max, *min);
	while (cnt_max-- > 0)
		ra(stack, 'a');
}

void	sub_sort(t_stack *stack, int size, int max, int min)
{
	int	i;

	if (size <= 6)
	{
		i = sub_sort_terminal(stack, max, min, 0);
		while (i-- > 0)
			ra(stack, 'a');
		return ;
	}
	top_sort(stack, &size, &max, &min);
	size = size - size / 2;
	bottom_sort(stack, &size, &max, &min);
}
