/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:27:58 by nutar             #+#    #+#             */
/*   Updated: 2023/03/24 21:31:55 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

# ifndef FALSE
#  define FALSE 0
# endif
# ifndef TURE
#  define TRUE 0
# endif

typedef struct s_integers
{
	int	mid;
	int	*array;
	int	argc;
}	t_integers;


//arg_check
t_integers	arg_check_all(int argc, char **argv);
//arg_2_check
t_integers	arg_2_check_all(int argc, char **argv);
//util
void		error_func(int	*array);
int			ft_isdigit(int c);
int			ft_atoi_edit(const char *str, int *array);
//ft_split
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_strdup(const char *src);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlen(const char *c);

#endif