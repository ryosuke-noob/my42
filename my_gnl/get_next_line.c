/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 23:18:48 by nutar             #+#    #+#             */
/*   Updated: 2022/10/30 23:09:08 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*check_buf(char *buf, int rc)
{
	char	*save;
	int		i;

	buf[rc] = '\0';
	i = -1;
	while (++i < rc)
	{
		if (buf[i] == '\n')
		{
			save = ft_strjoin_edit(NULL, &buf[i + 1]);
			buf[i + 1] = '\0';
			return (save);
		}
	}
	save = ft_strjoin_edit(NULL, NULL);
	return (save);
}

static char	*check_save(char *save_fd, char **line)
{
	char	*ret;
	size_t	i;

	if (save_fd == NULL || save_fd[0] == '\0')
		return (ft_strjoin_edit(NULL, NULL));
	i = 0;
	while (save_fd[i] != '\0' && save_fd[i] != '\n')//max of i == SIZE_MAX - 1
		i++;
	if (i != ft_strlen(save_fd))// <-> if save_fd[i] != '\0'  //max of i == SIZE_MAX - 2
	{
		ret = ft_strjoin_edit(NULL, &save_fd[i + 1]);
		if (ret == NULL)
			return (NULL);
		save_fd[i + 1] = '\0';
		*line = ft_strjoin_edit(save_fd, NULL);
		if (*line == NULL)//free ret
			return (NULL);
		return (ret);
	}
	*line = ft_strjoin_edit(save_fd, NULL);
	if (*line == NULL)
		return (NULL);
	ret = ft_strjoin_edit(NULL, NULL);
	return (ret);
}

static char	*free_func(char *buf, char *line, char *save, long long int rc)//long long or not
{
	free(buf);
	if (rc == -5)
		return (line);
	if (rc == -1)
	{
		if (line != NULL)
			free(line);
		if (save != NULL)
			free(save);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	ssize_t		rc;
	char		*buf;
	char		*line;
	static char	*save[1024];

	if (BUFFER_SIZE >= SIZE_MAX || BUFFER_SIZE > 9223372036854775807 || fd < 0 || fd > 1023)//SSIZE_MAX == 9223372036854775807 in Limux //FD_MAX == 65535
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	rc = BUFFER_SIZE;
	line = NULL;
	if (buf == NULL)
		return (NULL);
	while (rc == BUFFER_SIZE)
	{
		rc = read(fd, buf, BUFFER_SIZE);
		printf("[%zu]",rc);
		if (rc == -1)
			return (free_func(buf, line, save[fd], -1));//free buf, and if either line or save[fd] is NULL, free it
		if ((rc == 0 && save[fd] == NULL) || (rc == 0 && save[fd] != NULL && save[fd][0] == '\0'))
			break ;
		save[fd] = check_save(save[fd], &line);//if save [fd] is NULL, free buf, and if line isn't NULL, free line
		if (save[fd] == NULL)
			return (free_func(buf, line, save[fd], -1));
		if (save[fd][0] != '\0')
			return (free_func(buf, line, save[fd], -5));//free buf. return line
		free(save[fd]);
		save[fd] = check_buf(buf, rc);
		line = ft_strjoin_edit(line, buf);//if line is is NULL, return NULL with freeing buf and save
		if (line == NULL || save[fd] == NULL)
			return (free_func(buf, line, save[fd], -1));//we need to free buf and line and save[fd]
		if (save[fd][0] != '\0' || buf[rc -1] == '\n')
			break ;
	}
	free(buf);
	if (rc == 0)
	{
		if (save[fd] != NULL)
		{
			free(save[fd]);
			save[fd] = NULL;
		}
	}
	return (line);
}
