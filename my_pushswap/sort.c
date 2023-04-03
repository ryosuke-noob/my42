/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 21:33:23 by nutar             #+#    #+#             */
/*   Updated: 2023/04/03 22:26:26 by nutar            ###   ########.fr       */
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
		else if (i < size - 1 && tmp->number == min + 1 && tmp->next->number == min)
		{
			count += 2;
			min += 2;
			tmp = tmp->next;
			i++;
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

static void	b_sort(t_stack *stack, int size, int max, int min)
{
	int	i;
	int	tmp_min;
	int	count;
	int	cnt_max;

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
			else if (stack->size_b == 3 && stack->stack_b->number == min + 1 && stack->stack_b->next->number == min)
			{
				pa(stack);
				pa(stack);
				ra(stack, 'a');
				ra(stack, 'a');
				pa(stack);
				ra(stack, 'a');
			}
			else if (stack->size_b == 4 \
			&& ((stack->stack_b->number == max - 1 && stack->stack_b->next->number == max && stack->stack_b->next->next->number == min + 1 && stack->stack_b->next->next->next->number == min) \
			|| (stack->stack_b->number == min + 1 && stack->stack_b->next->number == min && stack->stack_b->next->next->number == max - 1 && stack->stack_b->next->next->next->number == max)))
				sb(stack, 'b');
			else if (stack->size_b == 4 \
			&& ((stack->stack_b->number == max - 1 && stack->stack_b->next->number == min && stack->stack_b->next->next->number == min + 1 && stack->stack_b->next->next->next->number == max) \
			|| (stack->stack_b->number == min + 1 && stack->stack_b->next->number == max && stack->stack_b->next->next->number == max - 1 && stack->stack_b->next->next->next->number == min)))
				rrb(stack, 'b');
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
		if (i < size - 1 && stack->stack_b->number == min + 1 && stack->stack_b->next->number == min)
			sb(stack, 'b');
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
		// if(i < size - size / 2 - cnt_max - 1 && stack->stack_a->number == stack->stack_a->next->number + 1)
		if(i < size - size / 2 - cnt_max - 1 && stack->stack_a->number == tmp_min + 1 && stack->stack_a->next->number == tmp_min)
			sa(stack, 'a');
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
	int	count;
	int	cnt_max;

	cnt_max = count_last_max(stack, size, size / 2);
	i = -1;
	while (++i < size - cnt_max)
	{
		if (stack->stack_a->number <= size / 2)
			pb(stack);
		else
			ra(stack, 'a');
	}
	b_sort(stack, size / 2 - cnt_max, size / 2 - cnt_max, 1);
	while (cnt_max-- > 0)
		ra(stack, 'a');
	// printf("\n[size: %d, max: %d, min: %d]]", size, cnt_max, 1);
	// check_stack(stack);
	// count = count_min(stack, size - size / 2, size / 2 + 1, 'a');
	count = size / 2 + 1;
	i = -1;
	while (++i < size - size / 2)
	{
		if (stack->stack_a->number == count)
		{
			ra(stack, 'a');
			count++;
		}
		else
			pb(stack);
	}
	b_sort(stack, size - count + 1, size, count);
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
