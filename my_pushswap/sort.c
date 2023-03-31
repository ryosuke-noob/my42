/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 21:33:23 by nutar             #+#    #+#             */
/*   Updated: 2023/03/31 16:36:06 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	b_sort(t_stack *stack, int size, int max, int min)
{
	int	i;

	// printf("[size==%d, max==%d]\n",size,max);
	// check_stack(stack);
	if (size <= 3)
	{
		asc_sort(stack, 'b');
		i = -1;
		while (++i < size)
			push_back(stack);
		return ;
	}
	if (size == 4)
	{
		i = -1;
		while (++i < size)
		{
			if (stack->stack_b->number == max)
			{
				pa(stack);
				break ;
			}
			else if (check_r_rr(*stack, max) == 'r')
				rb(stack, 'b');
			else
				rrb(stack, 'b');
		}
		asc_sort(stack, 'b');
		i = -1;
		while (++i < 3)
			push_back(stack);
		ra(stack, 'a');
		return ;
	}
	i = -1;
	while (++i < size)
	{
		if (stack->stack_b->number >= size / 2 + min)
			pa(stack);
		else
			rb(stack, 'b');
	}
	b_sort(stack, stack->size_b, max - size / 2 - size % 2, min);
	i = -1;
	while (++i < size - size / 2)
		pb(stack);
	b_sort(stack, stack->size_b, max, min + size / 2);
}

static void	a_sort(t_stack *stack, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (stack->stack_a->number <= size / 2)
			pb(stack);
		else
			ra(stack, 'a');
	}
	b_sort(stack, size / 2, size / 2, 1);
	i = -1;
	while (++i < size - size / 2)
		pb(stack);
	b_sort(stack, size - size / 2, size, size / 2 + 1);
}

void	sort(t_stack *stack)
{
	if (stack->size_a > 6)
		a_sort(stack, stack->size_a);
	else if (stack->size_a > 3)
		sort_under_6(stack);
	else
		asc_sort(stack, 'a');
	return ;
}
