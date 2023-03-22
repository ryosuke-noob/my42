/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnutaba <rnutaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:06:45 by rnutaba           #+#    #+#             */
/*   Updated: 2022/10/08 15:06:45 by rnutaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*set_return(char const *s1, char const *s2)
{
	char	*ret;

	if (!s1 && !s2)
	{
		ret = (char *)malloc(sizeof(char));
		if (!ret)
			return (0);
		ret[0] = 0;
	}
	else
	{
		if (!s1)
			ret = ft_strdup(s2);
		else
			ret = ft_strdup(s1);
		if (!ret)
			return (0);
	}
	return (ret);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (set_return(s1, s2));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s1_len + s2_len > SIZE_MAX)
		return (0);
	ret = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (ret == 0)
		return (0);
	i = 0;
	while (i < s1_len)
	{
		ret[i] = s1[i];
		i++;
	}
	i--;
	while (++i < s1_len + s2_len)
		ret[i] = s2[i - s1_len];
	ret[i] = 0;
	return (ret);
}
