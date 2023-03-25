/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:41:08 by nutar             #+#    #+#             */
/*   Updated: 2023/03/25 19:41:34 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack)
{
	t_list	*tmp;
	t_list	*top;
	t_list	*bottom;

	if (stack->stack_a == NULL || stack->stack_a->next == NULL)
		return ;
	tmp = stack->stack_a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	top = stack->stack_a;
	bottom = tmp;
	bottom->next = top;
	stack->stack_a = top->next;
	top->next = NULL;
}

void	rrb(t_stack *stack)
{
	t_list	*tmp;
	t_list	*top;
	t_list	*bottom;

	if (stack->stack_b == NULL || stack->stack_b->next == NULL)
		return ;
	tmp = stack->stack_b;
	while (tmp->next != NULL)
		tmp = tmp->next;
	top = stack->stack_b;
	bottom = tmp;
	bottom->next = top;
	stack->stack_b = top->next;
	top->next = NULL;
}

void	rrr(t_stack *stack)
{
	ra(stack);
	rb(stack);
}
