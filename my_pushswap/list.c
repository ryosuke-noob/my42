/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:34:52 by nutar             #+#    #+#             */
/*   Updated: 2023/03/29 20:20:33 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ret_number(t_integers integers, int content)
{
	int	i;
	int	number;

	number = 1;
	i = -1;
	while (++i < integers.argc)
		if (content > integers.array[i])
			number++;
	return (number);
}

t_stack	create_stack(t_integers	integers)
{
	t_stack	stack;
	t_list	*new;
	int		i;

	stack.stack_a = NULL;
	stack.stack_b = NULL;
	stack.size_a = integers.argc;
	stack.size_b = 0;
	i = -1;
	while (++i < integers.argc)
	{
		new = my_lstnew(integers.array[i], \
							ret_number(integers, integers.array[i]));
		if (new == NULL)
		{
			my_lstclear(&stack.stack_a);
			error_func(integers.array);
		}
		my_lstadd_back(&stack.stack_a, new);
	}
	return (stack);
}

void	my_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	my_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (!lst || !(*lst))
		return ;
	tmp = *lst;
	while (lst && *lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

t_list	*my_lstnew(int content, int number)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->content = content;
	new->number = number;
	new->next = 0;
	return (new);
}
