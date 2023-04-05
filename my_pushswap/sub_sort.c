/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:42:20 by nutar             #+#    #+#             */
/*   Updated: 2023/04/05 16:31:06 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

//count added because of line restrict
static int	count_min(t_stack *stack, int size, int min, int count)
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

void	top_sort_min(t_stack *stack, int *min, int mid, int *i)
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

void	top_sort(t_stack *stack, int *size, int *max, int *min)
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

void	bottom_sort(t_stack *stack, int *size, int *max, int *min)
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
	int	count;

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
			else if (stack->size_b >= 3 && stack->stack_b->number == min + 1 && stack->stack_b->next->number == min && stack->stack_b->next->next->number == min + 2)
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
	top_sort(stack, &size, &max, &min);
	size = size - size / 2;
	bottom_sort(stack, &size, &max, &min);
}
