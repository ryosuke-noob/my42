/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:25:44 by nutar             #+#    #+#             */
/*   Updated: 2023/09/24 14:01:25 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

long	get_time(void)
{
	struct timeval	tv;
	long			m_sec;

	if (gettimeofday(&tv, NULL) == ERR)
		return (ERR);
	m_sec = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (m_sec);
}

static void	delete_mutex(pthread_mutex_t *forks, long num)
{
	long	i;

	i = -1;
	while (++i < num)
		pthread_mutex_destroy(&forks[i]);
}

int	delete_all(pthread_mutex_t *forks, long num, t_th *th, int status)
{
	delete_mutex(forks, num);
	free(th);
	free(forks);
	return (status);
}
