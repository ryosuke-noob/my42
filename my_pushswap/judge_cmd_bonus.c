/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   judge_cmd_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:13:27 by nutar             #+#    #+#             */
/*   Updated: 2023/04/12 17:43:05 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	error_func_cmd(t_stack *stack, char *cmd)
{
	if (stack->stack_a != NULL)
		my_lstclear(&stack->stack_a);
	if (stack->stack_b != NULL)
		my_lstclear(&stack->stack_b);
	free(cmd);
	write(1, "Error\n", 7);
	exit(1);
}

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if ((unsigned char)s1[i] == 0 && (unsigned char)s2[i] == 0)
			return (0);
		i++;
	}
	return (0);
}

void	judge_cmd(t_stack *stack, char *cmd)
{
	if (ft_strncmp(cmd, "sa\n", ft_strlen(cmd)) == 0)
		sa(stack);
	else if (ft_strncmp(cmd, "sb\n", ft_strlen(cmd)) == 0)
		sb(stack);
	else if (ft_strncmp(cmd, "ss\n", ft_strlen(cmd)) == 0)
		ss(stack);
	else if (ft_strncmp(cmd, "ra\n", ft_strlen(cmd)) == 0)
		ra(stack);
	else if (ft_strncmp(cmd, "rb\n", ft_strlen(cmd)) == 0)
		rb(stack);
	else if (ft_strncmp(cmd, "rr\n", ft_strlen(cmd)) == 0)
		rr(stack);
	else if (ft_strncmp(cmd, "rra\n", ft_strlen(cmd)) == 0)
		rra(stack);
	else if (ft_strncmp(cmd, "rrb\n", ft_strlen(cmd)) == 0)
		rrb(stack);
	else if (ft_strncmp(cmd, "rrr\n", ft_strlen(cmd)) == 0)
		rrr(stack);
	else if (ft_strncmp(cmd, "pa\n", ft_strlen(cmd)) == 0)
		pa(stack);
	else if (ft_strncmp(cmd, "pb\n", ft_strlen(cmd)) == 0)
		pb(stack);
	else
		error_func_cmd(stack, cmd);
}
