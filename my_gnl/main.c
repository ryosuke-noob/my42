/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:07:31 by nutar             #+#    #+#             */
/*   Updated: 2022/10/31 14:19:41 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>

int	main(void)
{
	int		i;

	// mand
	char	*l;
	// int	 fd = open("sample.txt", O_RDONLY);
	// int	 fd = open("41_no_nl", O_RDONLY);
	// int	 fd = open("alternate_line_nl_no_nl", O_RDONLY);
	int	 fd = open("alternate_line_nl_with_nl", O_RDONLY);
	// fd = 0;
	if (fd == -1)
	{
		printf("error");
		return (0);
	}
	i = -1;
	// while (++i < 8)
	{
		l = get_next_line(fd);
		printf("%s", l);
		l = get_next_line(fd);
		printf("%s", l);
		l = get_next_line(fd);
		printf("%s", l);
		l = get_next_line(fd);
		printf("%s", l);
		l = get_next_line(fd);
		printf("%s", l);
		l = get_next_line(fd);
		printf("%s", l);
		l = get_next_line(fd);
		printf("%s", l);
		l = get_next_line(fd);
		printf("%s", l);
		l = get_next_line(fd);
		printf("%s", l);
		l = get_next_line(fd);
		printf("%s", l);
	}
	close(fd);

	// //bonus
	// int		fd_b1 = open("sample_b1.txt", O_RDONLY);
	// int		fd_b2 = open("sample_b2.txt", O_RDONLY);
	// int		fd_b3 = open("sample_b3.txt", O_RDONLY);
	// char	*l1, *l2, *l3;
	// if (fd_b1 == -1 || fd_b2 == -1 || fd_b3 == -1)
	// {
	// 	printf("error");
	// 	return (0);
	// }
	// i = -1;
	// while (++i < 10)
	// {
	// 	l1 = get_next_line(fd_b1);
	// 	printf("%s", l1);
	// 	l2 = get_next_line(fd_b2);
	// 	printf("%s", l2);
	// 	l3 = get_next_line(fd_b3);
	// 	printf("%s", l3);
	// }
	// close(fd_b1);
	// close(fd_b2);
	// close(fd_b3);
}
