/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_static.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnutaba <rnutaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:54:27 by nutar             #+#    #+#             */
/*   Updated: 2023/04/24 21:51:11 by rnutaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	recieve_char(int sig, siginfo_t *info, void *p)
{
	static char	c;
	static int	bit_count;

	ft_printf("%d ",sig);
	if (sig == SIGUSR2)
		c = c + (1 << bit_count) & 0x000000FF;
	bit_count++;
	if (bit_count >= 8)
	{
		ft_printf("%d",c);
		// write(1, &c, 1);
		write(1, "\n", 1);
		c = 0;
		bit_count = 0;
		if (kill(info->si_pid, SIGUSR2) == -1)
		{
			ft_printf("[kill error\n");
			exit(FAILURE);
		}
		return ;
	}
	(void)p;
	usleep(50);
	if (kill(info->si_pid, SIGUSR1) == -1)
	{
		ft_printf("[kill error\n");
		exit(FAILURE);
	}
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
		;
	return (SUCCESS);
}
