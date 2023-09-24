/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnutaba <rnutaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:16:02 by rnutaba           #+#    #+#             */
/*   Updated: 2022/10/18 17:16:02 by rnutaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/ft_printf.h"

static int	ft_print_all(va_list *ap, char c)
{
	int	count;

	count = 0;
	if (c == 'i' || c == 'd')
		count = print_i_d(ap);
	else if (c == 'c')
		count = print_c(ap);
	else if (c == 's')
		count = print_s(ap);
	else if (c == 'u')
		count = print_u(ap);
	else if (c == 'p')
		count = print_p(ap);
	else if (c == 'c')
		count = print_c(ap);
	else if (c == 'x')
		count = print_x(ap, 'x');
	else if (c == 'X')
		count = print_x(ap, 'X');
	else if (c == '%')
		count = print_percent();
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	i;
	int		count;

	count = 0;
	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			count += ft_print_all(&ap, format[++i]);
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(ap);
	return (count);
}

size_t	ft_strlen(const char *c)
{
	size_t	count;

	count = 0;
	while (c[count] != 0)
		count++;
	return (count);
}
