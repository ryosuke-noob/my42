/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:54:27 by nutar             #+#    #+#             */
/*   Updated: 2023/04/20 00:50:21 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

unsigned int	count_bit;

void	recieve_char(int sig, siginfo_t *info, void *p)
{
	unsigned int	div;
	unsigned int	mod;
	int				i;

	div = count_bit / 256;
	mod = count_bit % 256;
	// printf("1 [count_bit:%x, div: %d, mod: %d]\n", count_bit, div, mod);
	if (sig != SIGUSR1 && sig != SIGUSR2)
	{
		printf("else!\n");
		return ;
	}
	count_bit = 0x000000FF & count_bit;
	if (sig == SIGUSR2)
		count_bit = mod + (1 << div) & 0x000000FF;
	// printf("2 [count_bit:%x, div: %d, mod: %d]\n", count_bit, div, mod);
	i = -1;
	while (++i < div + 1)
		count_bit += 0x00000100;
	// div = count_bit / 0x00000100;
	// printf("3 [count_bit:%x, div: %d, mod: %d]\n\n", count_bit, div, mod);
	if (div == 7)
	{
		printf("%c", count_bit & 0x000000FF);
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
