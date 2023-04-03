/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 21:33:23 by nutar             #+#    #+#             */
/*   Updated: 2023/04/03 19:34:15 by nutar            ###   ########.fr       */
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

int	count_min(t_stack *stack, int size, int min, int flag)
{
	int		i;
	int		count;
	t_list	*tmp;

	count = 0;
	if (flag == 'a')
		tmp = stack->stack_a;
	else
		tmp = stack->stack_b;
	i = -1;
	while (++i < size)
	{
		if (tmp->number == min)
		{
			count++;
			min++;
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
// //3 div
// static void	b_sort(t_stack *stack, int size, int max, int min)
// {
// 	int	i;
// 	int	tmp_min;
// 	// int	cnt_min;
// 	int	cnt_max;

// 	if (size <= 6)
// 	{
// 		// printf("\nsize <= 6 [size: %d, max: %d, min: %d]]", size, max, min);
// 		// check_stack(stack);
// 		cnt_max = 0;
// 		while (stack->size_b)
// 		{
// 			if (stack->stack_b->number == min)
// 			{
// 				pa(stack);
// 				min++;
// 				if (stack->stack_b != NULL && stack->stack_b->number != max - cnt_max \
// 						&& stack->stack_b->number != min && (check_r_rr(*stack, max - cnt_max) == 'r' || check_r_rr(*stack, min) == 'r'))
// 					rr(stack);
// 				else
// 					ra(stack, 'a');
// 			}
// 			else if (stack->stack_b->number == max - cnt_max)
// 			{
// 				pa(stack);
// 				cnt_max++;
// 			}
// 			else if (check_r_rr(*stack, max - cnt_max) == 'r' || check_r_rr(*stack, min) == 'r')
// 				rb(stack, 'b');
// 			else
// 				rrb(stack, 'b');
// 		}
// 		i = -1;
// 		while (++i < cnt_max)
// 			ra(stack, 'a');
// 		return ;
// 	}
// 	//top
// 	// printf("\ntop [size: %d, max: %d, min: %d]]", size, max, min);
// 	// check_stack(stack);
// 	// cnt_min = count_min(stack, size, min, 'b');
// 	tmp_min = min;
// 	i = -1;
// 	while (++i < size)
// 	{
// 		if (stack->stack_b->number == min)
// 		{
// 			pa(stack);
// 			min++;
// 			if (stack->stack_b != NULL && stack->stack_b->number != min \
// 							&& stack->stack_b->number < size / 3 + tmp_min)
// 			{
// 				rr(stack);
// 				i++;
// 			}
// 			else
// 				ra(stack, 'a');
// 		}
// 		else if (stack->stack_b->number >= size / 3 + tmp_min)
// 			pa(stack);
// 		else
// 			rb(stack, 'b');
// 	}
// 	b_sort(stack, stack->size_b, size / 3 + tmp_min - 1, min);
// 	//middle
// 	if (min <= size / 3 + tmp_min)
// 		min = size / 3 + tmp_min;
// 	// printf("\nmiddle [size: %d, max: %d, min: %d]]", size, max, min);
// 	// check_stack(stack);
// 	i = -1;
// 	while (++i < size - size / 3)
// 	{
// 		if (stack->stack_a->number < size / 3 + min)
// 			pb(stack);
// 		else
// 			ra(stack, 'a');
// 	}
// 	i = -1;
// 	while (++i < size - size / 3 - size / 3)
// 		rra(stack, 'a');
// 	b_sort(stack, stack->size_b, size / 3 + min - 1, min);
// 	//bottom
// 	min = size / 3 + min;
// 	// printf("\nbottom [size: %d, max: %d, min: %d]]", size, max, min);
// 	// check_stack(stack);
// 	cnt_max = count_last_max(stack, max - min + 1, max);
// 	tmp_min = min;
// 	i = -1;
// 	while (++i < max - tmp_min + 1 - cnt_max)
// 	{
// 		if (stack->stack_a->number == min)
// 		{
// 			ra(stack, 'a');
// 			min++;
// 		}
// 		else
// 			pb(stack);
// 	}
// 	b_sort(stack, stack->size_b, max - cnt_max, min);
// 	while (cnt_max-- > 0)
// 		ra(stack, 'a');
// }

static void	b_sort(t_stack *stack, int size, int max, int min)
{
	int	i;
	int	tmp_min;
	int	count;
	int	cnt_max;

	// if (size == 0)
	// 	return ;
	// if (size <= 3)
	// {
	// 	asc_sort(stack, 'b');
	// 	i = -1;
	// 	while (++i < size)
	// 		push_back(stack);
	// 	return ;
	// }
	// printf("\n[size: %d, max: %d, min: %d]]", size, max, min);
	// check_stack(stack);
	if (size <= 6)
	{
		count = 0;
		while (stack->size_b)
		{
			if (stack->stack_b->number == max - count)
			{
				pa(stack);
				count++;
			}
			else if (stack->stack_b->number == min)
			{
				pa(stack);
				min++;
				if (stack->stack_b->number != max - count && stack->stack_b->number != min && (check_r_rr(*stack, max - count) == 'r' || check_r_rr(*stack, min) == 'r'))
					rr(stack);
				else
					ra(stack, 'a');
			}
			else if (check_r_rr(*stack, max - count) == 'r' || check_r_rr(*stack, min) == 'r')
				rb(stack, 'b');
			else
				rrb(stack, 'b');
		}
		i = -1;
		while (++i < count)
			ra(stack, 'a');
		return ;
	}
	i = -1;
	count = count_min(stack, size, min, 'b');
	tmp_min = min + count;
	while (++i < size)
	{
		if (stack->stack_b->number == min)
		{
			pa(stack);
			min++;
			if (stack->stack_b != NULL && stack->stack_b->number != min && (stack->stack_b->number < (size - count) / 2 + tmp_min))
			{
				rr(stack);
				i++;
			}
			else
				ra(stack, 'a');
		}
		else if (stack->stack_b->number >= (size - count) / 2 + tmp_min)
			pa(stack);
		else
			rb(stack, 'b');
	}
	size -= count;
	// printf("over");
	b_sort(stack, stack->size_b, max - size / 2 - size % 2, min);
	tmp_min += size / 2;
	i = -1;
	cnt_max = count_last_max(stack, size - size / 2, max);
	while (++i < size - size / 2 - cnt_max)
	{
		if (stack->stack_a->number == tmp_min)
		{
			ra(stack, 'a');
			tmp_min++;
		}
		else
			pb(stack);
	}
	// printf("under");
	b_sort(stack, stack->size_b, max - cnt_max, tmp_min);
	while (cnt_max-- > 0)
		ra(stack, 'a');
}

static void	a_sort(t_stack *stack, int size)
{
	int	i;
	int	cnt_min;
	int	cnt_max;

	cnt_max = count_last_max(stack, size, size / 3);
	i = -1;
	while (++i < size - cnt_max)
	{
		if (stack->stack_a->number <= size / 3)
			pb(stack);
		else
			ra(stack, 'a');
	}
	b_sort(stack, size / 3 - cnt_max, size / 3 - cnt_max, 1);
	while (cnt_max-- > 0)
		ra(stack, 'a');
	// printf("\n[size: %d, max: %d, min: %d]", size, cnt_max, cnt_min);
	// check_stack(stack);
	cnt_min = size / 3 + 1;
	i = -1;
	while (++i < size - size / 3)
	{
		if (stack->stack_a->number <= size / 3 + cnt_min - 1)
			pb(stack);
		else
			ra(stack, 'a');
	}
	i = -1;
	while (++i < size / 3)
		ra(stack, 'a');
	b_sort(stack, cnt_min - 1, cnt_min + size / 3 - 1, cnt_min);
	// printf("[size: %d, max: %d, min: %d]\n", size, cnt_max, cnt_min);
	// check_stack(stack);
	cnt_min += size / 3;
	i = -1;
	while (++i < size - size / 3 - size / 3)
	{
		if (stack->stack_a->number == cnt_min)
		{
			ra(stack, 'a');
			cnt_min++;
		}
		else
			pb(stack);
	}
	b_sort(stack, size - cnt_min + 1, size, cnt_min);
	// printf("[size: %d, max: %d, min: %d]\n", size, cnt_max, cnt_min);
	// check_stack(stack);
}

// static void	a_sort(t_stack *stack, int size)
// {
// 	int	i;
// 	int	count;
// 	int	cnt_max;

// 	cnt_max = count_last_max(stack, size, size / 2);
// 	i = -1;
// 	while (++i < size - cnt_max)
// 	{
// 		if (stack->stack_a->number <= size / 2)
// 			pb(stack);
// 		else
// 			ra(stack, 'a');
// 	}
// 	b_sort(stack, size / 2 - cnt_max, size / 2 - cnt_max, 1);
// 	while (cnt_max-- > 0)
// 		ra(stack, 'a');
// 	// printf("\n[size: %d, max: %d, min: %d]]", size, cnt_max, 1);
// 	// check_stack(stack);
// 	// count = count_min(stack, size - size / 2, size / 2 + 1, 'a');
// 	count = size / 2 + 1;
// 	i = -1;
// 	while (++i < size - size / 2)
// 	{
// 		if (stack->stack_a->number == count)
// 		{
// 			ra(stack, 'a');
// 			count++;
// 		}
// 		else
// 			pb(stack);
// 	}
// 	b_sort(stack, size - count + 1, size, count);
// }

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
