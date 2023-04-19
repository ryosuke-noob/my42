/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 01:28:57 by nutar             #+#    #+#             */
/*   Updated: 2023/04/19 11:17:12 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/ft_printf.h"

static int	ft_putnbr_unsigned(unsigned int n, int count)
{
	char	c;

	if (n / 10)
		count = ft_putnbr_unsigned(n / 10, count + 1);
	c = n % 10 + '0';
	write(1, &c, 1);
	return (count);
}

int	print_c(va_list *ap)
{
	char	c;

	c = va_arg(*ap, int);
	write(1, &c, 1);
	return (1);
}

int	print_s(va_list *ap)
{
	char	*s;

	s = va_arg(*ap, char *);
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(1, s, ft_strlen(s));
	return ((int)ft_strlen(s));
}

int	print_u(va_list *ap)
{
	unsigned int	u;
	int				count;

	u = va_arg(*ap, unsigned int);
	count = ft_putnbr_unsigned(u, 1);
	return (count);
}

int	print_percent(void)
{
	write(1, "%", 1);
	return (1);
}
