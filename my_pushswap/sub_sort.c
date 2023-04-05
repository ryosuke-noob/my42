/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:42:20 by nutar             #+#    #+#             */
/*   Updated: 2023/04/05 14:36:16 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	top_sort(t_stack *stack, int *size, int *max, int *min)
{
	int	i;
	int	tmp_min;
	int	count;

	i = -1;
	count = count_min(stack, *size, *min, 'b');
	tmp_min = *min + count;
	while (++i < *size)
	{
		if (i < *size - 2 && stack->stack_b->number == *min + 1 && stack->stack_b->next->next->number == *min)
			sb(stack, 'b');
		if (i < *size - 1 && stack->stack_b->number == *min + 1 && stack->stack_b->next->number == *min)
			sb(stack, 'b');
		if (stack->stack_b->number == *min)
		{
			pa(stack);
			(*min)++;
			if (stack->stack_b != NULL && stack->stack_b->number !=*min && (stack->stack_b->number < (*size - count) / 2 + tmp_min))
			{
				rr(stack);
				i++;
			}
			else
				ra(stack, 'a');
		}
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
	// int	tmp_min;

	// tmp_min += *size / 2;
	i = -1;
	cnt_max = count_last_max(stack, *size - *size / 2, *max);
	while (++i < *size - *size / 2 - cnt_max)
	{
		// if(i < size - size / 2 - cnt_max - 1 && stack->stack_a->number == stack->stack_a->next->number + 1)
		if(i < *size - *size / 2 - cnt_max - 1 && stack->stack_a->number == *min + 1 && stack->stack_a->next->number == *min)
			sa(stack, 'a');
		if (stack->stack_a->number == *min)
		{
			ra(stack, 'a');
			(*min)++;
		}
		else
			pb(stack);
	}
	// printf("under");
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
	bottom_sort(stack, &size, &max, &min);
}
