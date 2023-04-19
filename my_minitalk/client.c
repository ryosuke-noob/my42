/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:07:22 by nutar             #+#    #+#             */
/*   Updated: 2023/04/20 00:48:35 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

//send lower bit first
//SIGUSR1 + bit == SIGUSR1 || SIGUSR2
void	send_char(pid_t pid, char c)
{
	int				bit;
	int				i;
	unsigned char	uc;

	uc = (unsigned)c;
	// printf("uc: %d\n", uc);
	i = -1;
	while (++i < 8)
	{
		usleep(100000);
		bit = (uc >> i) & 0x01;
		// printf("bit:%d\n", bit);
		if (kill(pid, SIGUSR1 + bit) == -1)
		{
			printf("[%d:kill error]\n", i);
			exit(FAILURE);
		}
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	if (argc != 3)
		return (1);
	pid = (pid_t)ft_atoi(argv[1]);
	if (pid < MIN_PID || pid > MAX_PID)
		return (FAILURE);
	i = -1;
	while (++i < (int)ft_strlen(argv[2]))
		send_char(pid, argv[2][i]);
	return (SUCCESS);
}
