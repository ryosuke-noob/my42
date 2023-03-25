/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 20:34:32 by nutar             #+#    #+#             */
/*   Updated: 2023/03/25 20:43:41 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2_1_3(t_stack *stack)
{
	sa(stack);
}

void	sort_3_2_1(t_stack *stack)
{
	sa(stack);
	rra(stack);
}

void	sort_3_1_2(t_stack *stack)
{
	ra(stack);
}

void	sort_1_3_2(t_stack *stack)
{
	sa(stack);
	ra(stack);
}

void	sort_2_3_1(t_stack *stack)
{
	rra(stack);
}
