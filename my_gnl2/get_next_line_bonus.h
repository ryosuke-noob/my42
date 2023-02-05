/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 23:19:10 by nutar             #+#    #+#             */
/*   Updated: 2022/10/30 23:20:00 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

// # define BUFFER_SIZE 5

char	*get_next_line(int fd);
char	*ft_strjoin_edit(char *s1, char *s2);
size_t	ft_strlen(const char *c);

#endif