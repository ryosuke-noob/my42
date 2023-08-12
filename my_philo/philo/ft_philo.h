/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:45:12 by nutar             #+#    #+#             */
/*   Updated: 2023/08/08 17:49:20 by nutar            ###   ########.fr       */
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
/*------------------------------*/

# define ERR -1

// utils
long	get_time(void);

#endif