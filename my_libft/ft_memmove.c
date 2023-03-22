/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnutaba <rnutaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:14:09 by rnutaba           #+#    #+#             */
/*   Updated: 2022/10/07 14:14:09 by rnutaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t size)
{
	char	*tmp;

	if (s1 < s2 || s2 + size <= s1)
		ft_memcpy(s1, s2, size);
	else if (s1 == s2)
		return ((void *)s2);
	else
	{
		tmp = s1 + size;
		while (--tmp >= (char *)s1)
			*tmp = *(char *)(s2 + (--size));
	}
	return (s1);
}
