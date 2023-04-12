/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_s_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:54:14 by nutar             #+#    #+#             */
/*   Updated: 2023/04/12 13:35:48 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_stack *stack)
{
	t_list	*top;
	t_list	*top_next;
	t_list	*top_next_next;

	if (stack->stack_a == NULL || stack->stack_a->next == NULL)
		return ;
	top = stack->stack_a;
	top_next = stack->stack_a->next;
	top_next_next = stack->stack_a->next->next;
	top->next = top_next_next;
	top_next->next = top;
	stack->stack_a = top_next;
}

void	sb(t_stack *stack)
{
	t_list	*top;
	t_list	*top_next;
	t_list	*top_next_next;

	if (stack->stack_b == NULL || stack->stack_b->next == NULL)
		return ;
	top = stack->stack_b;
	top_next = stack->stack_b->next;
	top_next_next = stack->stack_b->next->next;
	top->next = top_next_next;
	top_next->next = top;
	stack->stack_b = top_next;
}

void	ss(t_stack *stack)
{
	sa(stack);
	sb(stack);
}
