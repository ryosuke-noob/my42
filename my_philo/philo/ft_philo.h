/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:45:12 by nutar             #+#    #+#             */
/*   Updated: 2023/08/15 21:41:08 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILO_H
# define FT_PHILO_H

/*----------includes-----------*/
# include <stdio.h>
//printf
# include <stdlib.h>
//malloc, free
# include <unistd.h>
//write, usleep
# include <string.h>
//memset
# include <pthread.h>
//pthread_create, pthread_detach, pthread_join, pthread_mutex_init
//pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock
# include <sys/time.h>
//gettimeofday
# include <limits.h>
/*------------------------------*/

# define ERR -1
# define TRUE 1
# define FALSE 0

// typedef struct s_fork
// {
// 	pthread_mutex_t	*fork;
// }	t_fork;

typedef struct s_input
{
	int	num;
	int	die;
	int	eat;
	int	sleep;
	int	must_eat;
}	t_input;

typedef struct s_th
{
	pthread_t		th;
	void			*th_return;
	long			i;
	long			num;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
}	t_th;

// utils
long	get_time(void);

//
t_input	*set_input(int argc, char **argv, t_input *ret);

#endif