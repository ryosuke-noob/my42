/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:54:27 by nutar             #+#    #+#             */
/*   Updated: 2023/04/20 01:01:35 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

unsigned int	count_bit;

void	recieve_char(int sig, siginfo_t *info, void *p)
{
	unsigned int	div;
	unsigned int	mod;
	int				i;
	char			c;

	div = count_bit / 256;
	mod = count_bit % 256;
	count_bit = 0x000000FF & count_bit;
	if (sig == SIGUSR2)
		count_bit = mod + (1 << div) & 0x000000FF;
	i = -1;
	while (++i < div + 1)
		count_bit += 0x00000100;
	if (div == 7)
	{
		c = (count_bit & 0x000000FF) + 0;
		write(1, &c, 1);
		count_bit = 0;
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

	count_bit = 0;
	printf("PID: %d\n", getpid());
	reciever(recieve_char);
	while (1)
		;
	return (SUCCESS);
}
