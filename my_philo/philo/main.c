/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:38:41 by nutar             #+#    #+#             */
/*   Updated: 2023/08/08 18:18:13 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_philo.h"

void	*thread(void *arg)
{
	printf("in thread\n");
	return (NULL);
}

int	create_thread(int num)
{
	pthread_t	th;
	void		*th_return;

	if (pthread_create(&th, NULL, thread, (void *) NULL) == ERR)
		return (ERR);
	// printf("thread ID:%d\n", th);
	// usleep(10000);
	// pthread_detach(th);
	pthread_join(th, &th_return);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	// if (argc != 5 && argc != 6)
	// 	return (EXIT_FAILURE);
	printf("time_stamp: %ld\n", get_time());
	create_thread(argc);
	return (EXIT_SUCCESS);
}
