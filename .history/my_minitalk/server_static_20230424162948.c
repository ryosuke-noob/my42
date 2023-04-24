/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_static.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnutaba <rnutaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:54:27 by nutar             #+#    #+#             */
/*   Updated: 2023/04/24 16:29:48 by rnutaba          ###   ########.fr       */
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
	ft_printf("%x | ", c);
	if (bit_count == 8)
	{
		write(1, &c, 1);
		write(1, " : ", 3);
		ft_printf("%x", c);
		write(1, "]\n[", 3);
		c = 0;
		bit_count = 0;
	}
}

void	reciever(void handler(int, siginfo_t *, void *))
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
	reciever(recieve_char);
	while (1)
		;
	return (SUCCESS);
}
