/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnutaba <rnutaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:42:56 by rnutaba           #+#    #+#             */
/*   Updated: 2022/10/07 10:42:56 by rnutaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	count;
	size_t	ln_dest;
	size_t	ln_src;

	count = 0;
	if (!dest && !size)
		return (0);
	ln_dest = ft_strlen(dest);
	ln_src = ft_strlen(src);
	if (ln_dest >= size)
		return (size + ln_src);
	while (src[count] != 0 && count < size - ln_dest - 1)
	{
		dest[count + ln_dest] = src[count];
		count++;
	}
	dest[count + ln_dest] = 0;
	return (ln_dest + ln_src);
}
