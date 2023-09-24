/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:54:27 by nutar             #+#    #+#             */
/*   Updated: 2023/09/25 02:23:55 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/ft_minitalk.h"

void	init_c_bit_count(char *c, int *bit_count)
{
	*c = 0;
	*bit_count = 0;
}

void	recieve_char(int sig, siginfo_t *info, void *p)
{
	static int	waiting_time;
	static int	bit_count;
	static char	c;

	waiting_time = 0;
	if (sig == SIGUSR2)
		c = c + (1 << bit_count) & 0x000000FF;
	bit_count++;
	if (bit_count >= 8)
	{
		write(1, &c, 1);
		init_c_bit_count(&c, &bit_count);
		if (kill(info->si_pid, SIGUSR2) == -1)
			kill_error();
	}
	(void)p;
	while (waiting_time++ != 0)
	{
		if (waiting_time == 100000000)
		{
			if (kill(info->si_pid, SIGUSR1) == -1)
				kill_error();
			init_c_bit_count(&c, &bit_count);
		}
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
