/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:56:34 by nutar             #+#    #+#             */
/*   Updated: 2023/03/27 16:59:14 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack)
{
	t_list	*move;

	if (stack->stack_b == NULL)
		return ;
	move = stack->stack_b;
	stack->stack_b = stack->stack_b->next;
	move->next = stack->stack_a;
	stack->stack_a = move;
	stack->size_a++;
	stack->size_b--;
	printf("pa ");
}

void	pb(t_stack *stack)
{
	t_list	*move;

	if (stack->stack_a == NULL)
		return ;
	move = stack->stack_a;
	stack->stack_a = stack->stack_a->next;
	move->next = stack->stack_b;
	stack->stack_b = move;
	stack->size_b++;
	stack->size_a--;
	printf("pb ");
}
