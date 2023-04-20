/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnutaba <rnutaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:48:35 by rnutaba           #+#    #+#             */
/*   Updated: 2022/10/07 09:48:35 by rnutaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	count;

	count = 0;
	while (*s != 0)
	{
		count++;
		s++;
	}
	if ((unsigned char)*s == (unsigned char)c)
		return ((char *)s);
	s--;
	while (count-- > 0)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s--;
	}
	return (0);
}
