/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:54:27 by nutar             #+#    #+#             */
/*   Updated: 2023/09/25 11:42:39 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/ft_minitalk.h"

static int	g_waiting_time;

void	init_c_bit_count(char *c, int *bit_count, void *p)
{
	*c = 0;
	*bit_count = 0;
	(void)p;
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
		init_c_bit_count(&c, &bit_count, p);
		if (kill(client_pid, SIGUSR1) == ERR)
			kill_error();
		return ;
	}
	if (info->si_pid)
		client_pid = info->si_pid;
	g_waiting_time = 0;
	if (sig == SIGUSR2)
		c = c + (1 << bit_count) & 0x000000FF;
	if (++bit_count >= 8)
	{
		write(1, &c, 1);
		init_c_bit_count(&c, &bit_count, p);
		if (kill(info->si_pid, SIGUSR2) == ERR)
			kill_error();
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
	{
		g_waiting_time++;
		if (g_waiting_time == 100000000)
		{
			recieve_char(RE, NULL, NULL);
			g_waiting_time = 0;
		}
	}
	return (SUCCESS);
}
