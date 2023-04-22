/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnutaba <rnutaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 06:27:53 by rnutaba           #+#    #+#             */
/*   Updated: 2022/10/11 06:27:53 by rnutaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static t_list	*ft_free_mem(t_list **ret, void (*del)(void *))
{
	ft_lstclear(ret, del);
	return (NULL);
}

static t_list	*my_ft_lstnew(void *(*f)(void *), void *content)
{
	t_list	*new;

	if (f != NULL)
		new = ft_lstnew(f(content));
	else
		new = ft_lstnew(content);
	return (new);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*tmp;
	t_list	*new;

	if (lst == NULL)
		return (NULL);
	new = my_ft_lstnew(f, lst->content);
	if (new == NULL)
		return (NULL);
	ret = new;
	tmp = lst->next;
	while (tmp != NULL)
	{
		new = my_ft_lstnew(f, tmp->content);
		if (new == NULL)
			return (ft_free_mem(&ret, del));
		ft_lstadd_back(&ret, new);
		tmp = tmp->next;
	}
	return (ret);
}

// void	*addone(void *p)
// {
// 	void	*ret;

// 	ret = malloc(sizeof(int *));
// 	*(int *)ret = *(int *)p + 1;
// 	return (ret);
// }

// int	main(void)
// {
// 	int tab[] = {0, 1, 2, 3};
// 	t_list * l =  ft_lstnew(tab);
// 	for (int i = 1; i < 4; ++i)
// 		ft_lstadd_back(&l, ft_lstnew(tab + i));
// 	t_list * m = ft_lstmap(l, addone, free);
// 	t_list * tmp = l;
// 	/* 1 2 3 4 */ for (int i = 0; i < 4; ++i)
// 	{
// 		// check(*(int*)tmp->content == i);
// 		printf("[%d:%d]", i, *(int *)tmp->content);
// 		tmp = (t_list *)tmp->next;
// 	}
// 	tmp = m;
// 	/* 5 6 7 8 */ for (int i = 0; i < 4; ++i)
// 	{
// 		printf("[%d:%d]", i + 1, *(int *)tmp->content);
// 		// check(*(int*)tmp->content == i + 1);
// 		tmp = (t_list *)tmp->next;
// 	}
// 	ft_lstclear(&m, free);
// 	ft_lstclear(&l, NULL);
// 	write(1, "\n", 1);
// 	return (0);
// }

// __attribute__((destructor))
// static void destructor(void){
//     system("leaks -q a.out");
// }
