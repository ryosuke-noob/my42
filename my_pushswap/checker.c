/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:04:14 by nutar             #+#    #+#             */
/*   Updated: 2023/04/14 21:44:09 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static t_integers	arg_check(int argc, char **argv)
{
	t_integers	integers;
	int			i;

	if (argc == 1)
		exit(0);
	if (argc == 2)
	{
		i = -1;
		while (++i < (int)ft_strlen(argv[1]))
			if (argv[1][i] != ' ')
				break ;
		if (i == (int)ft_strlen(argv[1]))
			error_func(NULL);
		integers = arg_2_check_all(argc, argv);
	}
	else
		integers = arg_check_all(argc, argv);
	return (integers);
}

static void	final_integers_check(t_stack stack)
{
	int		i;
	t_list	*tmp;

	if (stack.size_b > 0)
	{
		ft_printf("KO\n");
		my_lstclear(&stack.stack_b);
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

void	ft_bzero(void *s, size_t size)
{
	size_t			i;
	unsigned char	*tmp;

	tmp = s;
	i = 0;
	while (i < size)
	{
		tmp[i++] = 0;
	}
	return ;
}

void	execute(t_stack *stack)
{
	char	*cmd;

	cmd = get_next_line(0);
	while (cmd != NULL)
	{
		judge_cmd(stack, cmd);
		ft_bzero(cmd, sizeof(cmd));
		free(cmd);
		cmd = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_integers	integers;
	t_stack		stack;

	integers = arg_check(argc, argv);
	stack = create_stack(integers);
	free(integers.array);
	execute(&stack);
	final_integers_check(stack);
	my_lstclear(&stack.stack_a);
	return (0);
}

// void	check_stack(t_stack *stack)
// {
// 	t_list	*tmp;

// 	printf("\nstack a: ");
// 	tmp = stack->stack_a;
// 	while (tmp)
// 	{
// 		printf("%d ", tmp->content);
// 		tmp = tmp->next;
// 	}
// 	printf("[%d]\n", stack->size_a);
// 	printf("stack b: ");
// 	tmp = stack->stack_b;
// 	while (tmp)
// 	{
// 		printf("%d ", tmp->content);
// 		tmp = tmp->next;
// 	}
// 	printf("[%d]\n", stack->size_b);
// }
