/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:05:02 by nutar             #+#    #+#             */
/*   Updated: 2023/04/25 16:10:34 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/ft_minitalk.h"

void	send_fail(void)
{
	ft_printf("fail\n");
	exit(FAILURE);
}

void	kill_error(void)
{
	ft_printf("kill error\n");
	exit(FAILURE);
}
