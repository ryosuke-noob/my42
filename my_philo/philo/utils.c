/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:25:44 by nutar             #+#    #+#             */
/*   Updated: 2023/08/08 17:49:34 by nutar            ###   ########.fr       */
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
	printf("sec: %ld\n", tv.tv_sec);
	printf("msec: %d\n", tv.tv_usec / 1000);
	printf("usec: %d\n", tv.tv_usec);
	return (m_sec);
}
