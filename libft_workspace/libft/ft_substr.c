/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnutaba <rnutaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 22:17:13 by rnutaba           #+#    #+#             */
/*   Updated: 2022/10/07 22:17:13 by rnutaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	i;
	char	*ret;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (len + 1 > SIZE_MAX)
		return (0);
	ret = (char *)malloc((len + 1));
	if (!ret)
		return (0);
	if (s_len <= (size_t)start || len == 0)
		ret[0] = 0;
	else
	{
		i = start;
		while (i < (size_t)start + len && s[i] != 0)
		{
			ret[i - (size_t)start] = s[i];
			i++;
		}	
		ret[i - (size_t)start] = 0;
	}
	return (ret);
}
