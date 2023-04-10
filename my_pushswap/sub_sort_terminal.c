/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_sort_terminal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:30:05 by nutar             #+#    #+#             */
/*   Updated: 2023/04/10 09:17:26 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	case_2_1_3(t_stack *stack)
{
	pa(stack);
	pa(stack);
	ra(stack, 'a');
	ra(stack, 'a');
	pa(stack);
	ra(stack, 'a');
}

static void	else_case(t_stack *stack, int max, int min, int count)
{
	t_list	*tmp;

	tmp = stack->stack_b;
	if (stack->size_b >= 3 && tmp->number == min + 1 && \
			tmp->next->number == min && tmp->next->next->number == min + 2)
		case_2_1_3(stack);
	else if (stack->size_b == 4 && tmp->number == max - 1 \
		&& tmp->next->number == max && tmp->next->next->number == min + 1 \
			&& tmp->next->next->next->number == min)
		sb(stack, 'b');
	else if (check_r_rr(*stack, max - count, min) == 'r')
		rb(stack, 'b');
	else
		rrb(stack, 'b');
}

//count added because of line restrict
int	sub_sort_terminal(t_stack *stack, int max, int min, int count)
{
	t_list	*tmp;

	while (stack->size_b)
	{
		tmp = stack->stack_b;
		if (tmp->number == min)
		{
			pa(stack);
			min++;
			if (tmp->number != max - count && tmp->number != min && \
							check_r_rr(*stack, max - count, min) == 'r')
				rr(stack);
			else
				ra(stack, 'a');
		}
		else if (tmp->number == max - count)
		{
			pa(stack);
			count++;
		}
		else
			else_case(stack, max, min, count);
	}
	return (count);
}
