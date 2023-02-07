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

#include "ft_printf.h"

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

// int	main(void)
// {
// 	int				d = 0;//INT_MIN - 1, INT_MIN, 0, INT_MAX, INT_MAX + 1
// 	int				i = 0;//INT_MIN - 1, INT_MIN, 0, INT_MAX, INT_MAX + 1
// 	char			s[] = "abcde";//NULL, isprint, !isprint 
// 	char			c = 'c';//isprint, !isprint
// 	int				p = 10;//NUll, !NULL
// 	int				x = INT_MAX;//INT_MIN - 1, INT_MIN, 0, INT_MAX, INT_MAX + 1
// 	unsigned int	u = 10;//UINT_MAX, UINT_MAX + 1, 0, -1, 10

// 	// ft_printf("%d\n",d);
// 	// ft_printf("%i\n",i);
// 	// ft_printf("%s\n",s);
// 	// ft_printf("%s\n",(char *)0);
// 	// ft_printf("%c\n",c);
// 	// ft_printf("%p\n",&p);
// 	// ft_printf("%p\n",NULL);
// 	// ft_printf("%x\n",x);
// 	// ft_printf("%X\n",x);
// 	// ft_printf("%u\n",u);
// 	ft_printf("%d|%i|%s|%c|%p|%x|%X|%u\n",d,i,s,c,&p,x,x,u);
// 	printf("\n");
// 	printf("%d|%i|%s|%c|%p|%x|%X|%u\n",d,i,s,c,&p,x,x,u);
// 	// printf("%d\n",d);
// 	// printf("%i\n",i);
// 	// printf("%s\n",s);
// 	// printf("%s\n",(char *)0);
// 	// printf("%c\n",c);
// 	// printf("%p\n",&p);
// 	// printf("%p\n",NULL);
// 	// printf("%x\n",x);
// 	// printf("%X\n",x);
// 	// printf("%u\n",u);
// 	return (0);
// }
