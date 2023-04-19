/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:45:12 by nutar             #+#    #+#             */
/*   Updated: 2023/04/19 23:09:56 by nutar            ###   ########.fr       */
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
# include <limits.h>
# include <string.h>
/*------------------------------*/

# define SUCCESS 0
# define FAILURE 1
# define MAX_PID 99998
# define MIN_PID 100

//server
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *c);

#endif