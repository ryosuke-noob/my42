/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:45:12 by nutar             #+#    #+#             */
/*   Updated: 2023/09/25 01:17:43 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINITALK_H
# define FT_MINITALK_H

/*----------includes-----------*/
# include <stdio.h>
//
# include <stdlib.h>
//exit, malloc, free
# include <unistd.h>
//write, getpid, sleep, usleep, pause, 
# include <signal.h>
//signal, sig..., kill 
// # include <limits.h>
# include <string.h>

# include "ft_printf.h"
/*------------------------------*/

# define SUCCESS 0
# define FAILURE 1
# define ERR -1
# define MAX_PID 99998
# define MIN_PID 100
# define RE 3
# define END 2
# define GO 1
# define WAIT 0
# define TRUE 1
# define FALSE 0

//server
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *c);
void	kill_error(void);
void	send_fail(void);

#endif