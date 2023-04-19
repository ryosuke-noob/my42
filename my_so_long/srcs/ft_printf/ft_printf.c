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

// int	main(void)
// {
// 	int				d = 0;//INT_MIN - 1, INT_MIN, 0, INT_MAX, INT_MAX + 1
// 	int				i = 0;//INT_MIN - 1, INT_MIN, 0, INT_MAX, INT_MAX + 1
// 	char			s[] = "abcde";//NULL, isprint, !isprint 
// 	char			c = 'c';//isprint, !isprint
// 	int				p = -1;//NUll, !NULL, -1
// 	int				x = -16;//INT_MIN, 0, INT_MAX, 9223372036854775807LL
// 	unsigned int	u = 10;//UINT_MAX, UINT_MAX + 1, 0, -1, 10

// 	ft_printf(" : %i]\n",ft_printf("[%d",d));
// 	ft_printf(" : %i]\n",ft_printf("[%i",i));
// 	ft_printf(" : %i]\n",ft_printf("[%s",s));
// 	ft_printf(" : %i]\n",ft_printf("[%s",(char *)0));
// 	ft_printf(" : %i]\n",ft_printf("[%c",c));
// 	ft_printf(" : %i]\n",ft_printf("[%p",&p));
// 	ft_printf(" : %i]\n",ft_printf("[%p",NULL));
// 	ft_printf(" : %i]\n",ft_printf("[%x",x));
// 	ft_printf(" : %i]\n",ft_printf("[%X",x));
// 	ft_printf(" : %i]\n",ft_printf("[%u",u));
// 	// // ft_printf("%d|%i|%s|%c|%p|%x|%X|%u\n",d,i,s,c,&p,x,x,u);
// 	printf("\n");
// 	// printf("%d|%i|%s|%c|%p|%x|%X|%u\n",d,i,s,c,&p,x,x,u);
// 	printf(" : %i]\n",printf("[%d",d));
// 	printf(" : %i]\n",printf("[%i",i));
// 	printf(" : %i]\n",printf("[%s",s));
// 	printf(" : %i]\n",printf("[%s",(char *)0));
// 	printf(" : %i]\n",printf("[%c",c));
// 	printf(" : %i]\n",printf("[%p",&p));
// 	printf(" : %i]\n",printf("[%p",NULL));
// 	printf(" : %i]\n",printf("[%x",x));
// 	printf(" : %i]\n",printf("[%X",x));
// 	printf(" : %i]\n",printf("[%u",u));
// 	return (0);
// }
