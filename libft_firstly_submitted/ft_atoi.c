/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnutaba <rnutaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:32:43 by rnutaba           #+#    #+#             */
/*   Updated: 2022/10/07 15:32:43 by rnutaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define SPACE 1
#define CHAR 0

static int	ft_space(char c)
{
	if (c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == 32)
		return (SPACE);
	return (CHAR);
}

static int	check(long ret, int c, int flag)
{
	long	div;
	int		mod;

	div = 922337203685477580;
	if (flag == 1)
		mod = 7;
	else
		mod = 8;
	if (ret > div)
		return (flag);
	if (ret == div && mod < c)
		return (flag);
	return (0);
}

int	ft_atoi(const char *str)
{
	long	i;
	long	minus;
	long	ret;
	int		tmp;

	i = 0;
	minus = 1;
	while (ft_space(str[i]))
		i++;
	if (str[i] == '-')
		minus = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	ret = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = ret * 10 + str[i++] - '0';
		tmp = check(ret, str[i], minus);
		if (tmp == 1)
			return (-1);
		if (tmp == -1)
			return (0);
	}
	return ((int)ret * minus);
}
