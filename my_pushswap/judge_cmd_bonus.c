/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   judge_cmd_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:13:27 by nutar             #+#    #+#             */
/*   Updated: 2023/04/12 13:37:44 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	int	len;

	len = ft_strlen(cmd);
	if (ft_strncmp(cmd, "sa", len))
		sa(stack);
	if (ft_strncmp(cmd, "sb", len))
		sb(stack);
	if (ft_strncmp(cmd, "ss", len))
		ss(stack);
	if (ft_strncmp(cmd, "ra", len))
		ra(stack);
	if (ft_strncmp(cmd, "rb", len))
		rb(stack);
	if (ft_strncmp(cmd, "rr", len))
		rr(stack);
	if (ft_strncmp(cmd, "rra", len))
		rra(stack);
	if (ft_strncmp(cmd, "rrb", len))
		rrb(stack);
	if (ft_strncmp(cmd, "rrr", len))
		rrr(stack);
	if (ft_strncmp(cmd, "pa", len))
		pa(stack);
	if (ft_strncmp(cmd, "pb", len))
		pb(stack);
}
