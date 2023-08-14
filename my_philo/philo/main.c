/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:38:41 by nutar             #+#    #+#             */
/*   Updated: 2023/08/14 16:47:42 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_philo.h"

void	*thread(void *arg)
{
	t_th	*th;

	th = (t_th *)arg;
	// pthread_mutex_lock(th->mutex);
	// printf("in %dth thread\n", th->i);

	//left_right ver.
	printf("in %dth thread, left = %d, right = %d\n", th->i, \
	(th->i + th->num - 1) % th->num, th->i);

	//one_two fork ver.
	// printf("in %dth thread, first = %d, second = %d\n", th->i, \
	// (th->i + th->num - ((th->i + 1) % 2)) % th->num, (th->i + th->num - (th->i % 2)) % th->num);

	// pthread_mutex_unlock(th->mutex);
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
	free(th);
}

void	delete_mutex(pthread_mutex_t *forks, int num)
{
	int	i;

	i = -1;
	while (++i < num)
		pthread_mutex_destroy(&forks[i]);
	if (num != 1)
		free(forks);
}

int	create_philos(int num)
{
	t_th			*th;
	int				i;
	pthread_mutex_t	*forks;

	th = (t_th *)malloc(sizeof(t_th) * num);
	if (th == NULL)
		return (ERR);
	forks = (pthread_t *)malloc(sizeof(pthread_t) * num);
	if (forks == NULL)
		return (ERR);
	i = -1;
	while (++i < num)
		pthread_mutex_init(&forks[i], NULL);
	i = -1;
	while (++i < num)
	{
		th[i].i = i;
		th[i].num = num;
		th[i].l_fork = &forks[(i + num - 1) % num];
		th[i].r_fork = &forks[i];
		if (pthread_create(&th[i].th, NULL, thread, (void *) &th[i]) == ERR)
			return (ERR);
	}
	delete_thread(th, num);
	delete_mutex(forks, num);
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
