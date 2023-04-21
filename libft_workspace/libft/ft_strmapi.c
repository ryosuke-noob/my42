/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnutaba <rnutaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:28:52 by rnutaba           #+#    #+#             */
/*   Updated: 2022/10/10 21:28:52 by rnutaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	i;
	unsigned int	j;

	if (!s)
		return (0);
	if (ft_strlen(s) + 1 > SIZE_MAX)
		return (0);
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ret)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (f(i, s[i]))
			ret[j++] = f(i, s[i]);
		else
			ret[j++] = s[i];
		i++;
	}
	ret[j] = 0;
	return (ret);
}
