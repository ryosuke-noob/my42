/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   judge_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:13:27 by nutar             #+#    #+#             */
/*   Updated: 2023/03/29 20:14:28 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	judge_s(t_stack *stack)
{
	int	jdg_a;
	int	jdg_b;

	jdg_a = judge(*stack, 'a');
	jdg_b = judge(*stack, 'b');
	if ((jdg_a == 213 || jdg_a == 321 || jdg_a == 132 || jdg_a == 21) \
			&& (jdg_b == 123 || jdg_b == 231 || jdg_b == 312 || jdg_b == 12))
		ss(stack);
	else if (jdg_a == 213 || jdg_a == 321 || jdg_a == 132 || jdg_a == 21)
		sa(stack, 'a');
	else if (jdg_b == 123 || jdg_b == 231 || jdg_b == 312 || jdg_b == 12)
		sb(stack, 'b');
}

void	judge_r(t_stack *stack)
{
	int	jdg_a;
	int	jdg_b;

	jdg_a = judge(*stack, 'a');
	jdg_b = judge(*stack, 'b');
	if ((jdg_a == 312 || jdg_a == 132) && (jdg_b == 132 || jdg_b == 312))
		rr(stack);
	else if (jdg_a == 312 || jdg_a == 132)
		ra(stack, 'a');
	else if (jdg_b == 132 || jdg_b == 312)
		rb(stack, 'b');
}

void	judge_rr(t_stack *stack)
{
	int	jdg_a;
	int	jdg_b;

	jdg_a = judge(*stack, 'a');
	jdg_b = judge(*stack, 'b');
	if ((jdg_a == 321 || jdg_a == 231) && (jdg_b == 213 || jdg_b == 123))
		rrr(stack);
	else if (jdg_a == 321 || jdg_a == 231)
		rra(stack, 'a');
	else if (jdg_b == 213 || jdg_b == 123)
		rrb(stack, 'b');
}
