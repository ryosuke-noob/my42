/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:46:46 by nutar             #+#    #+#             */
/*   Updated: 2023/09/24 15:08:44 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	arg_error(void)
{
	printf("wrong argument\n");
	return (EXIT_FAILURE);
}

int	input_error(void)
{
	printf("wrong input\n");
	return (EXIT_FAILURE);
}
