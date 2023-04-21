/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnutaba <rnutaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 22:17:13 by rnutaba           #+#    #+#             */
/*   Updated: 2022/10/07 22:17:13 by rnutaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <malloc/malloc.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	i;
	char	*ret;

	if (s == NULL || len == SIZE_MAX)
		return (NULL);
	s_len = ft_strlen(s);
	ret = (char *)malloc((len + 1));
	if (ret == NULL)
		return (NULL);
	if (s_len <= (size_t)start || len == 0)
		ret[0] = 0;
	else
	{
		i = start;
		while (i < (size_t)start + len && s[i] != 0)
		{
			ret[i - (size_t)start] = s[i];
			i++;
		}	
		ret[i - (size_t)start] = 0;
	}
	return (ret);
}

// //MKO because malloc size (2 -> 16)
// //this depends on environment like OS
// int	main(int argc, char **argv)
// {
// 	// char	*ret;
// 	// int		i;

// 	// i = -1;
// 	// while (++i < argc)
// 	// {
// 	// 	ret = ft_substr(argv[1], 0, argc - i);
// 	// 	printf("%s\n", ret);
// 	// 	free(ret);
// 	// }
// 	// printf("\n");
// 	char *s;
// 	s = ft_substr("tripouille", 1, 1);
// 	printf("len: %d, str: %s\n", (int)ft_strlen(s), s);
// 	printf("malloc size: %d\n", (int)malloc_size(s));
// 	free(s);
// 	return (0);
// }

// __attribute__((destructor))
// static void destructor(void){
//     system("leaks -q a.out");
// }