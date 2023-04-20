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

static t_list	*ft_free_mem(t_list *new, t_list **ret, void (*del)(void *))
{
	free(new);
	ft_lstclear(ret, del);
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**ret;
	t_list	*tmp;
	t_list	*new;

	ret = malloc(sizeof(t_list *));
	if (!lst || !f | !del || !ret)
		return (0);
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (ft_free_mem(new, ret, del));
	ret = &new;
	tmp = lst;
	while (tmp)
	{
		new = ft_lstnew(f((*lst).content));
		if (!new)
			return (ft_free_mem(new, ret, del));
		ft_lstadd_back(ret, new);
		tmp = tmp->next;
	}
	return (*ret);
}
