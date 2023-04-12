/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:04:14 by nutar             #+#    #+#             */
/*   Updated: 2023/04/12 13:40:16 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static t_integers	arg_check(int argc, char **argv)
{
	t_integers	integers;

	if (argc == 1)
		exit(0);
	if (argc == 2)
		integers = arg_2_check_all(argc, argv);
	else
		integers = arg_check_all(argc, argv);
	return (integers);
}

static void	integers_check(t_integers integers)
{
	int	i;

	i = -1;
	while (++i < integers.argc - 1)
		if (integers.array[i] != integers.array[i + 1] - 1)
			break ;
	if (i == integers.argc - 1)
	{
		if (integers.array != NULL)
			free(integers.array);
		exit(0);
	}
}

static void	final_integers_check(t_stack stack)
{
	int		i;
	t_list	*tmp;

	if (stack.size_b > 0)
	{
		ft_printf("KO\n");
		return ;
	}
	tmp = stack.stack_a;
	i = -1;
	while (++i < stack.size_a - 1)
	{
		if (tmp->number != tmp->next->number - 1)
			break ;
		tmp = tmp->next;
	}
	if (i == stack.size_a - 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void	execute(t_stack *stack)
{
	char	*cmd;

	cmd = get_next_line(0);
	while (cmd != NULL)
	{
		judge_cmd(stack, cmd);
		free(cmd);
		cmd = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_integers	integers;
	t_stack		stack;

	integers = arg_check(argc, argv);
	integers_check(integers);
	stack = create_stack(integers);
	// sort(&stack);
	//execute
	execute(&stack);
	final_integers_check(stack);
	my_lstclear(&stack.stack_a);
	return (0);
}
