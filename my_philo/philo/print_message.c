/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 00:26:42 by nutar             #+#    #+#             */
/*   Updated: 2023/09/25 00:49:08 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_philo.h"

void	print_take_fork(t_th *th, long time)
{
	if (th->flag->dead != TRUE)
		printf("%lu %d has taken a fork\n", time, th->i);
}

void	print_eating(t_th *th)
{
	if (th->flag->dead != TRUE)
		printf("%lu %d is eating\n", th->last_eat, th->i);
}

void	print_sleeping(t_th *th)
{
	if (th->flag->dead != TRUE)
		printf("%lu %d is sleeping\n", get_time(), th->i);
}

void	print_thinking(t_th *th)
{
	if (th->flag->dead != TRUE)
		printf("%lu %d is thinking\n", get_time(), th->i);
}

void	print_died(t_th *th, long time)
{
	if (th->flag->dead != TRUE)
		printf("%lu %d died\n", time, th->i);
}
