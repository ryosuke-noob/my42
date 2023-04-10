/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:42:20 by nutar             #+#    #+#             */
/*   Updated: 2023/04/10 10:58:53 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_min_a(t_stack *stack, int size, int min, int count)
{
	int		i;
	t_list	*tmp;

	tmp = stack->stack_a;
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

static void	top_sort_flag(t_stack *stack, int *size, int *min)
{
	int	i;
	int	tmp_min;

	tmp_min = *min;
	i = -1;
	while (++i < *size / 2 + *size % 2)
		pa(stack);
	stack->flag = 0;
	sub_sort(stack, stack->size_b, *min + *size / 2 - 1, *min);
	*min = tmp_min + *size / 2;
	// sub_sort(stack, stack->size_b, *max - *size / 2 - *size % 2, *min);
	// printf("In top_sort_flag\n");
}

static void	top_sort(t_stack *stack, int *size, int *min)
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
	sub_sort(stack, stack->size_b, tmp_min + *size / 2 - 1, *min);
	*min = tmp_min + *size / 2;
}

static void	bottom_sort(t_stack *stack, int *size, int *max, int *min)
{
	int	i;
	int	cnt_max;
	int	cnt_min;
	int	tmp_min;

	i = -1;
	cnt_max = count_last_max(stack, *size, *max);
	cnt_min = count_min_a(stack, *size - cnt_max, *min, 0);
	tmp_min = *min + cnt_min;
	// printf("cnt_max: %d, cnt_min: %d\n", cnt_max, cnt_min);
	while (++i < *size - cnt_max)
	{
		if (i < *size - cnt_max - 2 && judge_3_1(stack->stack_a, *min))
			sa(stack, 'a');
		if (i < *size - cnt_max - 1 && judge_2_1(stack->stack_a, *min))
			sa(stack, 'a');
		if (stack->stack_a->number == *min)
		{
			ra(stack, 'a');
			(*min)++;
		}
		else
		{
			pb(stack);
			if (stack->stack_b->number < (*size - cnt_max - cnt_min) / 2 + tmp_min)
				rb(stack, 'b');
		}
	}
	sub_sort(stack, stack->size_b, *max - cnt_max, *min);
	while (cnt_max-- > 0)
		ra(stack, 'a');
}

void	sub_sort(t_stack *stack, int size, int max, int min)
{
	int	i;

	// printf("sub_sort [size: %d]\n", size);
	if (size <= 6)
	{
		// printf("terminal [size: %d, max: %d, min: %d, flag: %d]", size, max, min, stack->flag);
		// check_stack(stack);
		i = sub_sort_terminal(stack, max, min, 0);
		while (i-- > 0)
			ra(stack, 'a');
		return ;
	}
	// printf("top [size: %d, max: %d, min: %d, flag: %d]", size, max, min, stack->flag);
	// check_stack(stack);
	if (stack->flag == 1)
		top_sort_flag(stack, &size, &min);
	else
		top_sort(stack, &size, &min);
	size -= size / 2;//here
	// printf("bottom [size: %d, max: %d, min: %d, flag: %d]", size, max, min, stack->flag);
	// check_stack(stack);
	bottom_sort(stack, &size, &max, &min);
	stack->flag = 1;
}
