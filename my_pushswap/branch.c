/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 21:33:23 by nutar             #+#    #+#             */
/*   Updated: 2023/03/27 17:08:16 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	asc_sort(t_stack *stack, int flag)
{
	int	result;

	// result = judge(*stack, 'a');
	result = judge(*stack, flag);
	if (result == 213 || result == 321 || result == 132 || result == 21)
		sa(stack, 0);
	if (result == 312 || result == 132)
		ra(stack, 0);
	if (result == 321 || result == 231)
		rra(stack, 0);
}

void	branch(t_stack *stack)
{
	if (stack->size_a > 6)
	{
	}
	else if (stack->size_a > 3)
	{
		int		count;
		int		i;
		t_list	*index;
		t_list	*tmp;

		index = stack->stack_a;
		while (1)
		{
			tmp = stack->stack_a;
			count = 0;
			while (tmp->next != NULL)
			{
				if (tmp->content < index->content)
					count++;
				tmp = tmp->next;
			}
			if (count == stack->size_a - 3)
				break ;
			else
				index = index->next;
		}
		printf("[count : %d] [index : %d]", count, index->content);
		i = stack->size_a - 1;
		while (i-- > 0)
		{
			if (stack->stack_a->content < index->content)
				pb(stack);
			else
				ra(stack, 'a');
		}
		//add flag to asc_sort;
		//if add dec_sort, argolism will improve
		asc_sort(stack, 'a');

		//
		printf("\nstack a: ");
		tmp = stack->stack_a;
		while (tmp)
		{
			printf("%d ", tmp->content);
			tmp = tmp->next;
		}
		printf("[%d]\n",stack->size_a);
		printf("stack b: ");
		tmp = stack->stack_b;
		while (tmp)
		{
			printf("%d ", tmp->content);
			tmp = tmp->next;
		}
		printf("[%d]\n",stack->size_b);
		//
		asc_sort(stack, 'b');
		while (count-- > 0)
		{
			rrb(stack, 'b');
			pa(stack);
		}
	}
	else
		asc_sort(stack,'a');
	return ;
}