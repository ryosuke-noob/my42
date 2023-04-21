/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnutaba <rnutaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 21:45:20 by rnutaba           #+#    #+#             */
/*   Updated: 2022/10/07 21:45:20 by rnutaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	char	*ret;
	size_t	i;

	if (size * n > SIZE_MAX)
		return (0);
	ret = (char *)malloc(size * n);
	if (!ret)
		return (0);
	i = 0;
	while (i < n * size)
		ret[i++] = 0;
	return ((void *)ret);
}
