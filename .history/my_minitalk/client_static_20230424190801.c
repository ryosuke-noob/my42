/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_static.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnutaba <rnutaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:07:22 by nutar             #+#    #+#             */
/*   Updated: 2023/04/24 19:08:01 by rnutaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

int	flag;

//send lower bit first
//SIGUSR1 + bit == SIGUSR1 || SIGUSR2
void	send_char(pid_t pid, char c)
{
	int				bit;
	int				i;
	unsigned char	uc;

	flag = WAIT;
	uc = (unsigned)c;
	i = -1;
	while (++i < 8)
	{
		usleep(100);
		bit = (uc >> i) & 0x01;
		if (kill(pid, SIGUSR1 + bit) == -1)
		{
			ft_printf("[kill error]\n");
			exit(FAILURE);
		}
	}
}

void	wait_until_success(int sig, siginfo_t *info, void *p)
{
	if (sig == SIGUSR1)
		flag = GO;
	else if (sig == SIGUSR2)
		flag = SUCCESS;
	(void)info;
	(void)p;
}

void	client_reciever(void handler(int, siginfo_t *, void *))
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

int	main(int argc, char **argv)
{
	pid_t		pid;
	size_t		time_count;
	int			i;

	if (argc != 3)
		return (FAILURE);
	pid = (pid_t)ft_atoi(argv[1]);
	if (pid < MIN_PID || pid > MAX_PID)
		return (FAILURE);
	client_reciever(wait_until_success);
	usleep(1000);
	flag = GO;
	time_count = 0;
	i = -1;
	while (++i < (int)ft_strlen(argv[2]))
	{
		while (flag == WAIT)
		{
			time_count++;
			if (time_count == SIZE_MAX / )
		}
		send_char(pid, argv[2][i]);
		time_count = 0;
	}
	if (flag == SUCCESS)
		ft_printf("success\n");
	return (SUCCESS);
}
