/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_static.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnutaba <rnutaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:54:27 by nutar             #+#    #+#             */
/*   Updated: 2023/04/24 17:07:24 by rnutaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	recieve_char(int sig, siginfo_t *info, void *p)
{
	static char	c;
	static int	bit_count;

	if (sig == SIGUSR2)
		c = c + (1 << bit_count) & 0x000000FF;
	bit_count++;
	if (bit_count == 8)
	{
		write(1, &c, 1);
		c = 0;
		bit_count = 0;
		if (kill(info->si_pid, SIGUSR1) == -1)
		{
			ft_printf("[kill error\n");
			exit(FAILURE);
		}
	}
}

void	serverreciever(void handler(int, siginfo_t *, void *))
{
	struct sigaction	act;

	bzero(&act, sizeof(struct sigaction));
	act.sa_sigaction = handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
}

int	main(void)
{
	unsigned char	uc;

	ft_printf("PID: %d\n", getpid());
	serverreciever(recieve_char);
	while (1)
		;
	return (SUCCESS);
}
