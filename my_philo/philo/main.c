/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:38:41 by nutar             #+#    #+#             */
/*   Updated: 2023/08/14 15:45:52 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_philo.h"

void	*thread(void *arg)
{
	t_th	*th;

	th = (t_th *)arg;
	pthread_mutex_lock(th->mutex);
	*(th->tmp) += 1;
	printf("in %dth thread, tmp = %d\n", (th->i), *(th->tmp));
	pthread_mutex_unlock(th->mutex);
	return (NULL);
}

void	delete_thread(t_th *th, int num)
{
	int	i;

	i = -1;
	while (++i < num)
	{
		// pthread_detach(th[i].th);
		pthread_join(th[i].th, &th[i].th_return);
	}
}

int	create_philos(int num)
{
	t_th			*th;
	int				i;
	int				tmp;
	pthread_mutex_t	mutex;

	th = (t_th *)malloc(sizeof(t_th) * num);
	if (th == NULL)
		return (ERR);
	tmp = -1;
	pthread_mutex_init(&mutex, NULL);
	i = -1;
	while (++i < num)
	{
		th[i].tmp = &tmp;
		th[i].i = i;
		th[i].num = num;
		th[i].mutex = &mutex;
		if (pthread_create(&th[i].th, NULL, thread, (void *) &th[i]) == ERR)
			return (ERR);
	}
	pthread_mutex_destroy(&mutex);
	delete_thread(th, num);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	// if (argc != 5 && argc != 6)
	// 	return (EXIT_FAILURE);
	// printf("time_stamp: %ld\n", get_time());
	create_philos(5);
	return (EXIT_SUCCESS);
}
