/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:34:20 by nutar             #+#    #+#             */
/*   Updated: 2023/03/24 20:52:41 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_func(int	*array)
{
	if (array != NULL)
		free(array);
	write(1, "Error\n", 7);
	exit(1);
}

//editted atoi
int	ft_atoi_edit(const char *str, int *array)
{
	long	i;
	long	minus;
	long	ret;
	int		tmp;

	i = 0;
	minus = 1;
	if (str[i] == '-')
		minus = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	ret = 0;
	while (str[i] >= '0' && str[i] <= '9')
		ret = ret * 10 + str[i++] - '0';
	if (ret * minus < (long)INT32_MIN || ret * minus > (long)INT32_MAX)
		error_func(array);
	return ((int)ret * minus);
}

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}