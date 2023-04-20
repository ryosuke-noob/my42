/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnutaba <rnutaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:53:00 by rnutaba           #+#    #+#             */
/*   Updated: 2022/10/07 14:53:00 by rnutaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t size)
{
	size_t			i;
	unsigned char	*tmp;

	tmp = s;
	i = -1;
	while (++i < size)
	{
		tmp[i] = 0;
	}
	return ;
}
