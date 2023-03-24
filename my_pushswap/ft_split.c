/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnutaba <rnutaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:20:21 by rnutaba           #+#    #+#             */
/*   Updated: 2022/10/13 16:28:39 by rnutaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**free_ret_src(char **ret, int count, char *src, int flag)
{
	(void)count;
	if (flag == 3 || flag == 4)
	{
		if (ft_strlen(src) == 0)
			ret = (char **)malloc(sizeof(char *));
		else
			ret = (char **)malloc(sizeof(char *) * 2);
		if (!ret)
			return (0);
		if (ft_strlen(src) == 0)
		{
			*ret = 0;
			if (flag == 4)
				free(src);
			return (ret);
		}
		ret[0] = ft_strdup(src);
		ret[1] = 0;
		return (ret);
	}
	if (flag > 0)
		free(src);
	return (0);
}

static int	free_all(char **ret, int count, char *src, int flag)
{
	if (flag < 2)
	{
		while (count >= 0)
			free(ret[count--]);
		free(ret);
	}
	if (flag > 0)
		free(src);
	return (0);
}

static size_t	count_char(char *s, int c, int flag, size_t *start)
{
	size_t	count;
	size_t	i;

	count = 0;
	if (flag == 1)
	{
		i = 0;
		while (s[i] && s[i + 1])
		{
			if (s[i] != c && s[i + 1] == c)
				count++;
			i++;
		}
		return (count);
	}
	while (s[count + *start] == c && s[count + *start])
		*start += 1;
	while (s[count + *start] != c && s[count + *start])
		count++;
	return (count);
}

static int	set_ret(char **ret, char *src, size_t size_src, int c)
{
	int		count;
	size_t	start;
	size_t	size;

	count = -1;
	start = 0;
	while ((size_t)(++count) <= size_src)
	{
		size = count_char(src, c, 2, &start);
		ret[count] = (char *)malloc(size + 1);
		if (!ret[count])
			return (free_all(ret, count, src, 1));
		ft_strlcpy(ret[count], &src[start], size + 1);
		start += size;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	char	*src;
	char	tmp_c[2];
	size_t	size_src;

	ft_strlcpy(tmp_c, &c, 2);
	if (!s)
		return (0);
	if (s[0] == '\0' || c == '\0')
		return (free_ret_src(0, 0, (char *)s, 3));
	src = ft_strtrim(s, tmp_c);
	if (!src)
		return (0);
	if (src[0] == '\0')
		return (free_ret_src(0, 0, src, 4));
	size_src = count_char(src, c, 1, 0);
	ret = (char **)malloc(sizeof(char *) * (size_src + 2));
	if (!ret)
		return ((char **)free_ret_src(ret, 0, src, 2));
	ret[size_src + 1] = 0;
	if (set_ret(ret, src, size_src, c) == 0)
		return (0);
	free_ret_src(ret, 0, src, 2);
	return (ret);
}
