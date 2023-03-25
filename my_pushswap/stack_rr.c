/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:41:08 by nutar             #+#    #+#             */
/*   Updated: 2023/03/25 19:52:06 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack)
{
	t_list	*tmp;
	t_list	*top;
	t_list	*semi_bottom;
	t_list	*bottom;

	if (stack->stack_a == NULL || stack->stack_a->next == NULL)
		return ;
	if (stack->stack_a->next->next == NULL)
	{
		sa(stack);
		return ;
	}
	tmp = stack->stack_a;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	top = stack->stack_a;
	semi_bottom = tmp;
	bottom = tmp->next;
	stack->stack_a = bottom;
	bottom->next = top;
	semi_bottom->next = NULL;
}

void	rrb(t_stack *stack)
{
	t_list	*tmp;
	t_list	*top;
	t_list	*semi_bottom;
	t_list	*bottom;

	if (stack->stack_b == NULL || stack->stack_b->next == NULL)
		return ;
	if (stack->stack_b->next->next == NULL)
	{
		sa(stack);
		return ;
	}
	tmp = stack->stack_b;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	top = stack->stack_b;
	semi_bottom = tmp;
	bottom = tmp->next;
	stack->stack_b = bottom;
	bottom->next = top;
	semi_bottom->next = NULL;
}

void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
}
