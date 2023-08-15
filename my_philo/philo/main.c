/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:38:41 by nutar             #+#    #+#             */
/*   Updated: 2023/08/15 21:44:25 by nutar            ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_input	input;

	if (argc != 5 && argc != 6)
	{
		printf("wrong argument\n");
		return (EXIT_FAILURE);
	}
	if (set_input(argc, argv, &input) == NULL)
	{
		printf("wrong input\n");
		return (EXIT_FAILURE);
	}
	printf("OK\n");
	printf("num: %d, die: %d, eat: %d, sleep: %d", input.num, input.die, input.eat, input.sleep);
	if (argc == 6)
		printf(", must_eat: %d", input.must_eat);
	printf("\n");
	// create_philos(5);
	// printf("%lu\n", (long)1 % 2);
	return (EXIT_SUCCESS);
}
