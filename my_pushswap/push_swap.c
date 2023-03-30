/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:44:56 by nutar             #+#    #+#             */
/*   Updated: 2023/03/30 18:17:14 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	check_stack(t_stack *stack)
{
	t_list	*tmp;

	printf("\nstack a: ");
	tmp = stack->stack_a;
	while (tmp)
	{
		printf("%d ", tmp->content);
		tmp = tmp->next;
	}
	printf("[%d]\n", stack->size_a);
	printf("stack b: ");
	tmp = stack->stack_b;
	while (tmp)
	{
		printf("%d ", tmp->content);
		tmp = tmp->next;
	}
	printf("[%d]\n", stack->size_b);
}

int	main(int argc, char **argv)
{
	t_integers	integers;
	t_stack		stack;

	integers = arg_check(argc, argv);
	stack = create_stack(integers);
	sort(&stack);
	my_lstclear(&stack.stack_a);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	t_integers	integers;
// 	t_stack		stack;

// 	//arg
// 	integers = arg_check(argc, argv);

// 	//stack
// 	stack = create_stack(integers);

// 	// //sort
// 	// sort(&stack);

// 	// my_lstclear(&stack.stack_a);
// 	// check integers
// 	// printf("[check integers]\n");
// 	// int			i;
// 	// i = -1;
// 	// while (++i < integers.argc)
// 	// 	printf("%d ", integers.array[i]);
// 	// printf("\n");

// 	// //check stack
// 	printf("[check stack: BEFORE]\n");
// 	t_list	*tmp;
// 	printf("stack a: ");
// 	tmp = stack.stack_a;
// 	while (tmp)
// 	{
// 		// printf("[%d,%d] ", tmp->content, tmp->number);
// 		printf("%d ", tmp->content);
// 		// printf("%d ", tmp->number);
// 		tmp = tmp->next;
// 	}
// 	printf("[%d]\n",stack.size_a);

// 	// //command
// 	printf("---command---\n");
// 	sort(&stack);
// 	printf("\n-------------\n");
// 	// //

// 	printf("[check stack: AFTER]\n");
// 	printf("stack a: ");
// 	tmp = stack.stack_a;
// 	while (tmp)
// 	{
// 		printf("%d ", tmp->content);
// 		tmp = tmp->next;
// 	}
// 	printf("[%d]\n",stack.size_a);
// 	printf("stack b: ");
// 	tmp = stack.stack_b;
// 	while (tmp)
// 	{
// 		printf("%d ", tmp->content);
// 		tmp = tmp->next;
// 	}
// 	printf("[%d]\n",stack.size_b);

// 	// // //check judge
// 	// // printf("[check judge]\n");
// 	// // printf("%d ", judge(stack, 'a'));
// 	// // printf("\n");

// 	// // check leaks
// 	// // printf("\n-------------------------\n\n");
// 	// // system("leaks -q a.out");
// 	// // return (0);
// }
