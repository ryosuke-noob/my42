/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 21:33:23 by nutar             #+#    #+#             */
/*   Updated: 2023/03/28 23:35:17 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	asc_sort(t_stack *stack, int flag)
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

void	dec_sort(t_stack *stack, int flag)
{
	int	result;

	result = judge(*stack, flag);
	if (flag == 'a')
	{
		if (result == 123 || result == 231 || result == 312 || result == 12)
			sa(stack, 'a');
		if (result == 132 || result == 312)
			ra(stack, 'a');
		if (result == 213 || result == 123)
			rra(stack, 'a');	
	}
	else
	{
		if (result == 123 || result == 231 || result == 312 || result == 12)
			sb(stack, 'b');
		if (result == 132 || result == 312)
			rb(stack, 'b');
		if (result == 213 || result == 123)
			rrb(stack, 'b');	
	}
}

void	b_sort(t_stack *stack, int size, int max, int min)
{
	int	i;

	// printf("\n[size_b == %d]", size);
	// check_stack(stack);
	if (size <= 3)
	{
		asc_sort(stack, 'b');
		i = -1;
		while (++i < size)
		{
			pa(stack);
			ra(stack, 'a');
		}
		return ;
	}
	i = -1;
	while (++i < size)
	{
		if (stack->stack_b->number > (max - min) / 2 + min)
			pa(stack);
		else
			rb(stack, 'b');
	}
	b_sort(stack, stack->size_b, max - size / 2, min);
	i = -1;
	while (++i < (max - min) - (max - min) / 2)
		pb(stack);
	b_sort(stack, stack->size_b, max, min + size / 2);
}

void	a_sort(t_stack *stack, int size)
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
	// check_stack(stack);
	b_sort(stack, size / 2, size / 2, 1);
	i = -1;
	while (++i < size - size / 2)
		pb(stack);
	// check_stack(stack);
	// printf("[size:%d, size/2:%d, size-size/2:%d]",size, size/2, size - size/2);
	b_sort(stack, size - size / 2, size, size / 2 + 1);
}

void	branch(t_stack *stack)
{
	if (stack->size_a > 6)
	{
		a_sort(stack, stack->size_a);
	}
	else if (stack->size_a > 3)
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
		printf("[index : %d]", index->content);
		i = stack->size_a;
		while (i-- > 0)
		{
			if (stack->stack_a->content < index->content)
				pb(stack);
			else
				ra(stack, 'a');
		}
		//
		// check_stack(stack);
		//
		asc_sort(stack, 'a');
		dec_sort(stack, 'b');
		//
		// check_stack(stack);
		//
		while (stack->size_b > 0)
		{
			// rrb(stack, 'b');
			pa(stack);
		}
	}
	else
		asc_sort(stack,'a');
	return ;
}
