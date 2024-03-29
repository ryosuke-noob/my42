/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 21:33:23 by nutar             #+#    #+#             */
/*   Updated: 2023/04/11 11:37:32 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bottom_sort_over_6(t_stack *stack, int *size, int *max, int *min)
{
	int	i;

	i = -1;
	while (++i < *size)
	{
		if (stack->stack_a->number >= *size / 2 + *min)
			ra(stack, 'a');
		else
			pb(stack);
	}
	i = -1;
	while (++i < *size / 2 + *size % 2)
		rra(stack, 'a');
	sub_sort(stack, *size / 2, *min + *size / 2 - 1, *min);
	*min += *size / 2;
	*size = *size / 2 + *size % 2;
	bottom_sort(stack, size, max, min);
}

static void	asc_sort(t_stack *stack, int flag)
{
	int	result;

	result = judge(*stack, flag);
	if (flag == 'a')
	{
		if (result == 213 || result == 321 || result == 132 || result == 21)
			sa(stack, 'a');
		if (result == 312 || result == 132)
			ra(stack, 'a');
		if (result == 321 || result == 231)
			rra(stack, 'a');
	}
	else
	{
		if (result == 213 || result == 321 || result == 132 || result == 21)
			sb(stack, 'b');
		if (result == 312 || result == 132)
			rb(stack, 'b');
		if (result == 321 || result == 231)
			rrb(stack, 'b');
	}
}

static void	sort_under_6(t_stack *stack)
{
	int		i;
	t_list	*index;

	index = stack->stack_a;
	while (index->next != NULL)
	{
		if (index->number == stack->size_a / 2 + 1)
			break ;
		index = index->next;
	}
	i = stack->size_a;
	while (i-- > 0)
	{
		if (stack->stack_a->content < index->content)
			pb(stack);
		else
			ra(stack, 'a');
	}
	judge_s(stack);
	judge_r(stack);
	judge_rr(stack);
	while (stack->size_b > 0)
		pa(stack);
}

static void	sort_over_6(t_stack *stack, int size)
{
	int	i;
	int	min;
	int	cnt_max;

	cnt_max = count_last_max(stack, size, size / 2);
	i = -1;
	while (++i < size - cnt_max)
	{
		if (stack->stack_a->number <= size / 2 - cnt_max)
			pb(stack);
		else
			ra(stack, 'a');
	}
	sub_sort(stack, size / 2 - cnt_max, size / 2 - cnt_max, 1);
	while (cnt_max-- > 0)
		ra(stack, 'a');
	min = size / 2 + 1;
	cnt_max = size;
	size -= min - 1;
	bottom_sort_over_6(stack, &size, &cnt_max, &min);
}

void	sort(t_stack *stack)
{
	if (stack->size_a > 6)
		sort_over_6(stack, stack->size_a);
	else if (stack->size_a > 3)
		sort_under_6(stack);
	else
		asc_sort(stack, 'a');
	return ;
}
