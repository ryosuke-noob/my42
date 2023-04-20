/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnutaba <rnutaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:18:12 by rnutaba           #+#    #+#             */
/*   Updated: 2022/10/08 15:18:12 by rnutaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_included(int c, char const *set);
static char	*ft_set_ret(void);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	int		i;
	int		start;
	int		end;

	if (!s1 || !set)
		return (ft_set_ret());
	start = 0;
	while (s1[start] && char_included(s1[start], set))
		start++;
	if (!ft_strlen(s1) || !s1[start])
		return (ft_set_ret());
	end = ft_strlen(s1) - 1;
	while (start < end && char_included(s1[end], set))
		end--;
	ret = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!ret)
		return (0);
	i = -1;
	while (++i < end - start + 1)
		ret[i] = s1[start + i];
	ret[i] = 0;
	return (ret);
}

static char	*ft_set_ret(void)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char));
	if (!ret)
		return (0);
	ret[0] = 0;
	return (ret);
}

static int	char_included(int c, char const *set)
{
	int	i;

	i = -1;
	while (set[++i])
		if (set[i] == c)
			return (1);
	return (0);
}
