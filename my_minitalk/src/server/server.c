/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:54:27 by nutar             #+#    #+#             */
/*   Updated: 2023/09/25 11:34:55 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/ft_minitalk.h"

static int	waiting_time;

void	init_c_bit_count(char *c, int *bit_count)
{
	*c = 0;
	*bit_count = 0;
}

void	recieve_char(int sig, siginfo_t *info, void *p)
{
	static pid_t	client_pid;
	static int		bit_count;
	static char		c;

	if (sig == RE)
	{
		if (client_pid == 0 || bit_count == 0)
			return ;
		// write(1, "\nHere\n", 7);
		init_c_bit_count(&c, &bit_count);
		if (kill(client_pid, SIGUSR1) == ERR)
			kill_error();
		// ft_printf("client_pid: %d, bitcount: %d\n", client_pid, bit_count);
		// waiting_time = 0;
		return ;
	}
	if (info->si_pid)
		client_pid = info->si_pid;
	waiting_time = 0;
	if (sig == SIGUSR2)
		c = c + (1 << bit_count) & 0x000000FF;
	bit_count++;
	if (bit_count >= 8)
	{
		write(1, &c, 1);
		init_c_bit_count(&c, &bit_count);
		if (kill(info->si_pid, SIGUSR2) == ERR)
			kill_error();
	}
	(void)p;
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
		waiting_time++;
		if (waiting_time == 100000000)
		{
			recieve_char(RE, NULL, NULL);
			waiting_time = 0;
		}
	}
	return (SUCCESS);
}
