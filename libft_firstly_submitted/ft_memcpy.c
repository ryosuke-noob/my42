/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnutaba <rnutaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:58:29 by rnutaba           #+#    #+#             */
/*   Updated: 2022/10/07 13:58:29 by rnutaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t size)
{
	size_t	i;
	char	*tmp;

	if (s1 == s2)
		return (s1);
	tmp = s1;
	i = -1;
	while (++i < size)
	{
		*(tmp++) = *((char *)s2++);
	}
	return (s1);
}
