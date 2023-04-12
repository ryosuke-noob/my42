/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_r_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:19:07 by nutar             #+#    #+#             */
/*   Updated: 2023/04/12 13:35:25 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(t_stack *stack)
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

void	rb(t_stack *stack)
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

void	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
}
