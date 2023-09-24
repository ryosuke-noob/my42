/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:50:25 by nutar             #+#    #+#             */
/*   Updated: 2023/09/25 00:49:38 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_philo.h"

static void	*obs(void *arg);
static void	*philo(void *arg);
static void	set_philo_data(t_th *th, int i, \
							pthread_mutex_t *forks, t_input *input);
static int	init_create_philos(t_input input, t_th **th, \
							pthread_mutex_t	**forks, t_flag *flag);

// create threads (philos and observer)
int	create_threads(t_input input)
{
	t_th			*th;
	int				i;
	pthread_mutex_t	*forks;
	t_flag			flag;

	if (init_create_philos(input, &th, &forks, &flag) == ERR)
		return (ERR);
	i = -1;
	while (++i < input.num)
	{
		th[i].flag = &flag;
		set_philo_data(th, i, forks, &input);
		if (pthread_create(&th[i].th, NULL, philo, (void *) &th[i]) == ERR)
			return (ERR);
		if (pthread_create(&th[i].th_obs, NULL, obs, (void *) &th[i]) == ERR)
			return (ERR);
		pthread_detach(th[i].th);
		pthread_detach(th[i].th_obs);
	}
	while (flag.clear_count != input.num)
		if (flag.dead == TRUE)
			return (delete_all(forks, input.num, th, EXIT_FAILURE));
	return (delete_all(forks, input.num, th, EXIT_SUCCESS));
}

static void	*obs(void *arg)
{
	t_th	*th;
	long	time;

	th = (t_th *)arg;
	while (1)
	{
		time = get_time();
		if (time >= th->last_eat + (long)th->input.die)
		{
			print_died(th, time);
			th->flag->dead = TRUE;
			return (NULL);
		}
		if (th->clear == TRUE)
			return (NULL);
	}
}

static void	*philo(void *arg)
{
	t_th	*th;
	int		eat_count;

	th = (t_th *)arg;
	eat_count = 0;
	while (1)
	{
		pthread_mutex_lock(th->l_fork);
		print_take_fork(th, get_time());
		pthread_mutex_lock(th->r_fork);
		th->last_eat = get_time();
		print_take_fork(th, th->last_eat);
		print_eating(th);
		usleep(th->input.eat * 1000);
		pthread_mutex_unlock(th->r_fork);
		pthread_mutex_unlock(th->l_fork);
		if (++eat_count == th->input.must_eat)
			break ;
		print_sleeping(th);
		usleep(th->input.sleep * 1000);
		print_thinking(th);
	}
	th->clear = TRUE;
	(th->flag->clear_count)++;
	return (NULL);
}

static int	init_create_philos(t_input input, t_th **th, \
							pthread_mutex_t	**forks, t_flag *flag)
{
	int	i;

	*th = (t_th *)malloc(sizeof(t_th) * input.num);
	if (*th == NULL)
		return (ERR);
	*forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * input.num);
	if (*forks == NULL)
	{
		free(*th);
		return (ERR);
	}
	i = -1;
	while (++i < input.num)
		if (pthread_mutex_init((&(*forks)[i]), NULL) == ERR)
			return (delete_all(*forks, (long)i, *th, ERR));
	flag->clear_count = 0;
	flag->dead = FALSE;
	return (EXIT_SUCCESS);
}

static void	set_philo_data(t_th *th, int i, \
						pthread_mutex_t *forks, t_input *input)
{
	th[i].i = i + 1;
	th[i].input = *input;
	th[i].l_fork = &forks[(i + input->num - 1) % input->num];
	th[i].r_fork = &forks[i];
	th[i].last_eat = get_time();
	th[i].clear = FALSE;
}
