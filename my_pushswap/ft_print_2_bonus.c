/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 02:20:45 by nutar             #+#    #+#             */
/*   Updated: 2023/04/12 11:39:06 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_putnbr_unsigned_hex(unsigned long long n, int flag, int count)
{
	char	c;

	if (n / 16)
		count = ft_putnbr_unsigned_hex(n / 16, flag, count + 1);
	if (0 <= n % 16 && n % 16 <= 9)
		c = n % 16 + '0';
	else if (flag == 'x')
		c = n % 16 + 'a' - 10;
	else
		c = n % 16 + 'A' - 10;
	write(1, &c, 1);
	return (count);
}

static int	ft_putnbr_int(int n, int count)
{
	char			c;
	unsigned int	n_abs;
	double			tmp;

	if (n < 0)
	{
		write(1, "-", 1);
		count++;
	}
	if (n < 0)
	{
		tmp = n;
		tmp *= -1;
		n_abs = (unsigned int)tmp;
	}
	else
		n_abs = n;
	if (n_abs / 10)
		count = ft_putnbr_int(n_abs / 10, count + 1);
	c = n_abs % 10 + '0';
	write(1, &c, 1);
	return (count);
}

int	print_x(va_list *ap, int flag)
{
	unsigned long long	u;
	int					count;

	count = 0;
	u = va_arg(*ap, unsigned int);
	count += ft_putnbr_unsigned_hex(u, flag, 1);
	return (count);
}

int	print_p(va_list *ap)
{
	void	*p;
	int		count;

	count = 2;
	p = va_arg(*ap, void *);
	write(1, "0x", 2);
	count += ft_putnbr_unsigned_hex((unsigned long long)p, 'x', 1);
	return (count);
}

int	print_i_d(va_list *ap)
{
	int	d;
	int	count;

	count = 0;
	d = va_arg(*ap, int);
	count += ft_putnbr_int(d, 1);
	return (count);
}
