/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:38:41 by nutar             #+#    #+#             */
/*   Updated: 2023/08/16 12:37:10 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_philo.h"

void	*thread(void *arg)
{
	t_th	*th;
	int		eat_count;

	th = (t_th *)arg;
	eat_count = 0;
	while (1)
	{
		pthread_mutex_lock(th->l_fork);
		printf("%lu %d has taken a fork\n", get_time(), th->i);
		pthread_mutex_lock(th->r_fork);
		printf("%lu %d has taken a fork\n", get_time(), th->i);
		printf("%lu %d is eating\n", get_time(), th->i);
		//start eating
		usleep(th->input.eat * 1000);
		//end eating
		pthread_mutex_unlock(th->r_fork);
		pthread_mutex_unlock(th->l_fork);
		if (eat_count == th->input.must_eat)
			return (EXIT_SUCCESS);
		//start sleeping
		printf("%lu %d is sleeping\n", get_time(), th->i);
		usleep(th->input.sleep * 1000);
		//end sleeping
		printf("%lu %d is thinking\n", get_time(), th->i);
	}
	return (NULL);
}

// void	*thread(void *arg)
// {
// 	t_th	*th;

// 	th = (t_th *)arg;
// 	// pthread_mutex_lock(th->mutex);
// 	// printf("in %dth thread\n", th->i);

// 	//left_right ver.
// 	printf("in %luth thread, left = %lu, right = %lu || ", th->i, \
// 	(th->i + th->input.num - 1) % th->input.num, th->i);
// 	printf("num: %d, die: %d, eat: %d, sleep: %d", th->input.num, th->input.die, th->input.eat, th->input.sleep);
// 	if (th->input.must_eat != NO_INPUT)
// 		printf(", must_eat: %d", th->input.must_eat);
// 	printf("\n");

// 	//one_two fork ver.
// 	// printf("in %dth thread, first = %d, second = %d\n", th->i, \
// 	// (th->i + th->num - ((th->i + 1) % 2)) % th->num, (th->i + th->num - (th->i % 2)) % th->num);

// 	// pthread_mutex_unlock(th->mutex);
// 	return (NULL);
// }

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

int	create_philos(t_input input)
{
	t_th			*th;
	long			i;
	pthread_mutex_t	*forks;

	//---init---//
	th = (t_th *)malloc(sizeof(t_th) * input.num);
	if (th == NULL)
		return (ERR);
	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * input.num);
	if (forks == NULL)
		return (ERR);
	i = -1;
	while (++i < input.num)
		if (pthread_mutex_init(&forks[i], NULL) == ERR)
			return (ERR);
	//---init---//
	//create thread
	i = -1;
	while (++i < input.num)
	{
		th[i].i = i;
		th[i].input = input;
		th[i].l_fork = &forks[(i + input.num - 1) % input.num];
		th[i].r_fork = &forks[i];
		if (pthread_create(&th[i].th, NULL, thread, (void *) &th[i]) == ERR)
			return (ERR);
	}
	//---delete thread and free---//
	delete_thread(th, input.num);
	delete_mutex(forks, input.num);
	//---delete thread and free---//
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_input	input;

	//---input check---//
	if (argc != 5 && argc != 6)
		return (arg_error());
	if (set_input(argc, argv, &input) == NULL)
		return (input_error());
	printf("OK\n");
	printf("num: %d, die: %d, eat: %d, sleep: %d", input.num, input.die, input.eat, input.sleep);
	if (argc == 6)
		printf(", must_eat: %d", input.must_eat);
	printf("\n");
	//---input check---//

	create_philos(input);
	return (EXIT_SUCCESS);
}
