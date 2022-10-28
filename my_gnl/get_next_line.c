/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 23:18:48 by nutar             #+#    #+#             */
/*   Updated: 2022/10/28 02:18:22 by nutar            ###   ########.fr       */
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
			save = ft_strjoin(NULL, &buf[i + 1]);
			buf[i + 1] = '\0';
			return (save);
		}
	}
	save = ft_strjoin(NULL, NULL);
	return (save);
}

static char	*check_save(char *save_fd, char *line)
{
	char	*save;
	int		i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if ((size_t)i != ft_strlen(line))
	{
		save = ft_strjoin(NULL, &line[i + 1]);
		if (!save)
			return (NULL);
		line[i + 1] = '\0';
		return (save);
	}
	save = ft_strjoin(NULL, NULL);
	return (save);
}

static char	*free_func(char *buf, char *line, char *save, int rc)
{
	free(buf);
	if (rc == -1)
		free(line);
	if (rc == 0 || rc == -1)
		free(save);
	return (NULL);
}

char	*get_next_line(int fd)
{
	int			rc;
	char		*buf;
	char		*line;
	static char	*save[1024];

	line = ft_strjoin(save[fd], NULL);
	if (line == NULL)
		return (NULL);
	save[fd] = check_save(save[fd], line);//if save [fd] is NULL, return NULL and free line
	if (save[fd][0] != '\0')
		return (line);//save need to be free
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	rc = BUFFER_SIZE;
	if (!buf || fd < 0 || fd > 65535)
		return (NULL);//line and save need to be free
	while (rc == BUFFER_SIZE)
	{
		rc = read(fd, buf, BUFFER_SIZE);
		if (rc == -1)
			return (free_func(buf, line, save[fd], rc));
		save[fd] = check_buf(buf, rc);// if save[fd] is NULL, return NULL
		line = ft_strjoin(line, buf);//if line is is NULL, return NULL with freeing buf and save
		if (rc == 0 || save[fd][0] != '\0' || buf[rc -1] == '\n')
			break ;
	}
	free_func(buf, line, save[fd], rc);
	return (line);
}
