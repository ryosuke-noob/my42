/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnutaba <rnutaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:25:41 by rnutaba           #+#    #+#             */
/*   Updated: 2022/10/07 11:25:41 by rnutaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*tmp;
	size_t				i;

	tmp = s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)tmp[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}
