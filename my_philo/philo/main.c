/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:38:41 by nutar             #+#    #+#             */
/*   Updated: 2023/08/14 17:33:28 by nutar            ###   ########.fr       */
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
	printf("in %luth thread, left = %lu, right = %lu\n", th->i, \
	(th->i + th->num - 1) % th->num, th->i);

	//one_two fork ver.
	// printf("in %dth thread, first = %d, second = %d\n", th->i, \
	// (th->i + th->num - ((th->i + 1) % 2)) % th->num, (th->i + th->num - (th->i % 2)) % th->num);

	// pthread_mutex_unlock(th->mutex);
	return (NULL);
}

void	delete_thread(t_th *th, long num)
{
	long	i;

	i = -1;
	while (++i < num)
	{
		// pthread_detach(th[i].th);
		pthread_join(th[i].th, &th[i].th_return);
	}
	free(th);
}

void	delete_mutex(pthread_mutex_t *forks, long num)
{
	long	i;

	i = -1;
	while (++i < num)
		pthread_mutex_destroy(&forks[i]);
	if (num != 1)
		free(forks);
}

int	create_philos(long num)
{
	t_th			*th;
	long			i;
	pthread_mutex_t	*forks;

	//init
	th = (t_th *)malloc(sizeof(t_th) * num);
	if (th == NULL)
		return (ERR);
	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num);
	if (forks == NULL)
		return (ERR);
	i = -1;
	while (++i < num)
		pthread_mutex_init(&forks[i], NULL);
	//create thread
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
	//delete thread and free
	delete_thread(th, num);
	delete_mutex(forks, num);
	return (EXIT_SUCCESS);
}

int	check_int(char *arg)
{
	//check length of the arg. If more than 10 letters, ERR.
	//convert to long
	//if number bigger than INT_MAX, ERR.
	return (EXIT_SUCCESS);
}

int	check_input(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		//check letter of the arg. If have alfs, ERR.
		if (check_int(argv[i]) == ERR)
			return (ERR);
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_input	input;

	// if (argc != 5 && argc != 6)
	// 	return (EXIT_FAILURE);
	// // check_input(argc, argv);
	// if (check_input(argc, argv) == ERR)
	// 	return (EXIT_FAILURE);
	// // printf("time_stamp: %ld\n", get_time());
	create_philos(5);
	// printf("%lu\n", (long)1 % 2);
	return (EXIT_SUCCESS);
}
