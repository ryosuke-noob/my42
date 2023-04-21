/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnutaba <rnutaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:42:04 by rnutaba           #+#    #+#             */
/*   Updated: 2022/10/07 13:42:04 by rnutaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t size)
{
	size_t				i;
	const unsigned char	*t1;
	const unsigned char	*t2;

	t1 = s1;
	t2 = s2;
	i = -1;
	while (++i < size)
		if (t1[i] != t2[i])
			return (t1[i] - t2[i]);
	return (0);
}
