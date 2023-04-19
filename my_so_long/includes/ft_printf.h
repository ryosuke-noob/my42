/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:18:24 by nutar             #+#    #+#             */
/*   Updated: 2023/04/19 11:24:04 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# include <stdio.h>
# include <limits.h>

int		ft_printf(const char *format, ...);
int		print_c(va_list *ap);
int		print_s(va_list *ap);
int		print_u(va_list *ap);
int		print_percent(void);
int		print_x(va_list *ap, int flag);
int		print_p(va_list *ap);
int		print_i_d(va_list *ap);
size_t	ft_strlen(const char *c);

#endif