/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:45:12 by nutar             #+#    #+#             */
/*   Updated: 2023/09/25 00:46:31 by nutar            ###   ########.fr       */
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
# define NO_INPUT -2

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

typedef struct s_flag
{
	int	dead;
	int	clear_count;
}	t_flag;

typedef struct s_th
{
	pthread_t		th;
	pthread_t		th_obs;
	int				i;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	t_input			input;
	long			last_eat;
	t_flag			*flag;
	int				clear;
}	t_th;

// utils
long	get_time(void);
int		delete_all(pthread_mutex_t *forks, long num, t_th *th, int status);

// set_input
t_input	*set_input(int argc, char **argv, t_input *ret);

// create_threads
int		create_threads(t_input input);

//error
int		arg_error(void);
int		input_error(void);

//print_message
void	print_take_fork(t_th *th, long time);
void	print_eating(t_th *th);
void	print_sleeping(t_th *th);
void	print_thinking(t_th *th);
void	print_died(t_th *th, long time);

#endif