/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnutaba <rnutaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 21:38:04 by rnutaba           #+#    #+#             */
/*   Updated: 2022/10/07 21:38:04 by rnutaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
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
