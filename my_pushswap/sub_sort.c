/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:42:20 by nutar             #+#    #+#             */
/*   Updated: 2023/04/05 13:01:24 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	top_sort(t_stack *stack, int size, int max, int min)
// {
// 	int	i;
// 	int	tmp_min;
// 	int	count;

// 	i = -1;
// 	count = count_min(stack, size, min, 'b');
// 	tmp_min = min + count;
// 	while (++i < size)
// 	{
// 		if (i < size - 1 && stack->stack_b->number == min + 1 && stack->stack_b->next->number == min)
// 			sb(stack, 'b');
// 		if (stack->stack_b->number == min)
// 		{
// 			pa(stack);
// 			min++;
// 			if (stack->stack_b != NULL && stack->stack_b->number != min && (stack->stack_b->number < (size - count) / 2 + tmp_min))
// 			{
// 				rr(stack);
// 				i++;
// 			}
// 			else
// 				ra(stack, 'a');
// 		}
// 		else if (stack->stack_b->number >= (size - count) / 2 + tmp_min)
// 			pa(stack);
// 		else
// 			rb(stack, 'b');
// 	}
// 	size -= count;
// 	// printf("over");
// 	sub_sort(stack, stack->size_b, max - size / 2 - size % 2, min);
// }

// void	bottom_sort(t_stack *stack, int size, int max, int min)
// {

// }

// void	sub_sort(t_stack *stack, int size, int max, int min)
// {

// }