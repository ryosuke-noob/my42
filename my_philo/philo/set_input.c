/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:41:51 by nutar             #+#    #+#             */
/*   Updated: 2023/08/16 11:45:55 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

static int		check_int(char *arg);
static size_t	ft_strlen(const char *c);
static int		ft_atoi_edit(const char *str);
static int		check_input(int argc, char **argv);

t_input	*set_input(int argc, char **argv, t_input *ret)
{
	if (check_input(argc, argv) == ERR)
		return (NULL);
	ret->num = ft_atoi_edit(argv[1]);
	if (ret->num == 0)
		return (NULL);
	ret->die = ft_atoi_edit(argv[2]);
	ret->eat = ft_atoi_edit(argv[3]);
	ret->sleep = ft_atoi_edit(argv[4]);
	if (argc == 6)
		ret->must_eat = ft_atoi_edit(argv[5]);
	else
		ret->must_eat = NO_INPUT;
	return (ret);
}

static int	check_input(int argc, char **argv)
{
	int		i;
	int		j;
	size_t	len;

	i = 0;
	while (++i < argc)
	{
		len = ft_strlen(argv[i]);
		if (len > 10)
			return (ERR);
		j = -1;
		while (++j < len)
			if (('0' <= argv[i][j] && argv[i][j] <= '9') != TRUE)
				return (ERR);
		if (check_int(argv[i]) == ERR)
			return (ERR);
	}
	return (EXIT_SUCCESS);
}

static int	check_int(char *arg)
{
	size_t	len;
	size_t	i;
	long	ret;

	len = ft_strlen(arg);
	ret = 0;
	i = 0;
	while (i < len)
		ret = ret * 10 + arg[i++] - '0';
	if (ret > INT_MAX)
		return (ERR);
	return (EXIT_SUCCESS);
}

static size_t	ft_strlen(const char *c)
{
	size_t	count;

	count = 0;
	while (c[count] != 0 && count != SIZE_MAX)
		count++;
	return (count);
}

static int	ft_atoi_edit(const char *str)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = ret * 10 + str[i++] - '0';
	}
	return (ret);
}
