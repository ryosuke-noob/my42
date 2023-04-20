/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnutaba <rnutaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:02:20 by rnutaba           #+#    #+#             */
/*   Updated: 2022/10/07 11:02:20 by rnutaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t size)
{
	size_t			i;
	unsigned char	*tmp;

	tmp = s;
	i = 0;
	while (i < size)
	{
		tmp[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
