/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 23:18:42 by nutar             #+#    #+#             */
/*   Updated: 2023/04/14 19:23:38 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *c)
{
	size_t	count;

	count = 0;
	while (c[count] != 0)
		count++;
	return (count);
}

static char	*ft_strdup(const char *src)
{
	char	*new;
	size_t	length;
	int		i;

	length = ft_strlen(src);
	new = (char *)malloc(sizeof(char) * (length + 1));
	if (!new)
		return (0);
	i = -1;
	while (src[++i] != 0)
		new[i] = src[i];
	new[i] = 0;
	return (new);
}

static char	*set_return(char *s1, char *s2)
{
	char	*ret;

	if (s1 == NULL && s2 == NULL)
	{
		ret = (char *)malloc(sizeof(char));
		ret[0] = '\0';
		if (ret == NULL)
			return (NULL);
	}
	else
	{
		if (s1 == NULL)
			ret = ft_strdup(s2);
		else
		{
			ret = ft_strdup(s1);
			free(s1);
		}
		if (ret == NULL)
			return (NULL);
	}
	return (ret);
}

static char	*free_func_edit(char *ret, char *n2free)
{
	if (n2free != NULL)
		free(n2free);
	return (ret);
}

char	*ft_strjoin_edit(char *s1, char *s2)
{
	char	*ret;
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == NULL || s2 == NULL)
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
	return (free_func_edit(ret, s1));
}
