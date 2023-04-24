/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_static.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnutaba <rnutaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:07:22 by nutar             #+#    #+#             */
/*   Updated: 2023/04/24 17:20:57 by rnutaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

int	wait_flag;

//send lower bit first
//SIGUSR1 + bit == SIGUSR1 || SIGUSR2
void	send_char(pid_t pid, char c)
{
	int				bit;
	int				i;
	unsigned char	uc;

	uc = (unsigned)c;
	i = -1;
	while (++i < 8)
	{
		usleep(100);
		bit = (uc >> i) & 0x01;
		if (kill(pid, SIGUSR1 + bit) == -1)
		{
			printf("[kill error]\n");
			exit(FAILURE);
		}
	}
}

void	wait_until_success(int sig, siginfo_t *info, void *p)
{
	wait
}

void	client_reciever(void handler(int, siginfo_t *, void *))
{
	struct sigaction	act;

	bzero(&act, sizeof(struct sigaction));
	act.sa_sigaction = handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	// sigaction(SIGUSR2, &act, NULL);
}


int	main(int argc, char **argv)
{
	pid_t		pid;
	int			i;

	if (argc != 3)
		return (FAILURE);
	pid = (pid_t)ft_atoi(argv[1]);
	if (pid < MIN_PID || pid > MAX_PID)
		return (FAILURE);
	client_reciever(wait_until_success);
	i = -1;
	while (++i < (int)ft_strlen(argv[2]))
		send_char(pid, argv[2][i]);
	return (SUCCESS);
}
