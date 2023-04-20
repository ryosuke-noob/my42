/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnutaba <rnutaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:39:32 by rnutaba           #+#    #+#             */
/*   Updated: 2022/10/10 20:39:32 by rnutaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_alloc(char **ret, int n, unsigned int *n_abs)
{
	int				size;
	unsigned int	tmp;

	size = 0;
	if (n <= 0)
		size++;
	if (n < 0)
		*n_abs = (unsigned int)(-n);
	else
		*n_abs = (unsigned int)n;
	tmp = *n_abs;
	while (tmp)
	{
		size++;
		tmp = tmp / 10;
	}
	*ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!(*ret))
		return (0);
	return (size);
}

char	*ft_itoa(int n)
{
	char			*ret;
	int				start;
	int				size;
	unsigned int	n_abs;

	size = ft_alloc(&ret, n, &n_abs);
	if (!size)
		return (0);
	start = 0;
	if (n < 0)
		ret[start++] = '-';
	ret[size] = 0;
	while (--size >= start)
	{
		ret[size] = (n_abs % 10) + '0';
		n_abs = n_abs / 10;
	}
	return (ret);
}
