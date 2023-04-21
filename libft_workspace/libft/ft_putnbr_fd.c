/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnutaba <rnutaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 05:11:11 by rnutaba           #+#    #+#             */
/*   Updated: 2022/10/11 05:11:11 by rnutaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			c;
	unsigned int	n_abs;

	if (n < 0)
		write(fd, "-", 1);
	if (n < 0)
		n_abs = -n;
	else
		n_abs = n;
	if (n_abs / 10)
		ft_putnbr_fd(n_abs / 10, fd);
	c = n_abs % 10 + '0';
	write(fd, &c, 1);
}
