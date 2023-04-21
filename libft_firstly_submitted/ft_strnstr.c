/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnutaba <rnutaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:57:36 by rnutaba           #+#    #+#             */
/*   Updated: 2022/10/07 13:57:36 by rnutaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	\
	set_j(size_t i, size_t len, const char *str, const char *to_find)
{
	size_t	j;

	j = 0;
	while (to_find[j] != 0 && (i + j) < len)
	{
		if (str[i + j] != to_find[j])
			break ;
		j++;
	}
	return (j);
}

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	length;

	if (to_find[0] == 0)
		return ((char *)str);
	if (len == 0)
		return (0);
	i = 0;
	length = ft_strlen(to_find);
	while (str[i] != 0 && i < len)
	{
		if (str[i] == to_find[0])
		{
			j = set_j(i, len, str, to_find);
			if (j == length)
				return ((char *)&str[i]);
		}
		i++;
	}
	return (0);
}
