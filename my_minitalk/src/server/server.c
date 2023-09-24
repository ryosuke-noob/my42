/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:54:27 by nutar             #+#    #+#             */
/*   Updated: 2023/09/25 02:07:12 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/ft_minitalk.h"

static int	waiting_time;

void	recieve_char(int sig, siginfo_t *info, void *p)
{
	static int	bit_count;
	static char	c;

	// printf("catch\n");
	waiting_time = 0;
	if (sig == SIGUSR2)
		c = c + (1 << bit_count) & 0x000000FF;
	bit_count++;
	if (bit_count >= 8)
	{
		write(1, &c, 1);
		c = 0;
		bit_count = 0;
		if (kill(info->si_pid, SIGUSR2) == -1)
		{
			ft_printf("[kill error]\n");
			exit(FAILURE);
		}
		// return ;
	}
	(void)p;
	while (waiting_time++ != 0)
	{
		if (waiting_time % 10000000 == 0)
			printf("%d0000000",waiting_time);
		if (waiting_time == 100000000)
		{
			if (kill(info->si_pid, SIGUSR1) == -1)
			{
				ft_printf("[kill error]\n");
				exit(FAILURE);
			}
			c = 0;
			bit_count = 0;
		}
	}
	// usleep(50);
}

void	server_reciever(void handler(int, siginfo_t *, void *))
{
	struct sigaction	act;

	bzero(&act, sizeof(struct sigaction));
	act.sa_sigaction = handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaddset(&act.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
}

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	server_reciever(recieve_char);
	while (1)
	{
		// waiting_time++;
		// if (waiting_time % 1000000000 == 0)
		// 	printf("%d00000\n", waiting_time);
		// if (waiting_time == 1000000000)
		// 	recieve_char(0,NULL,NULL);
	}
	return (SUCCESS);
}
