/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 23:18:48 by nutar             #+#    #+#             */
/*   Updated: 2023/02/07 05:39:00 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
		return (ft_strjoin_edit(save_fd, NULL));
	i = 0;
	while (save_fd[i] != '\0' && save_fd[i] != '\n')
		i++;
	if (i != ft_strlen(save_fd))
	{
		ret = ft_strjoin_edit(NULL, &save_fd[i + 1]);
		if (ret == NULL)
			return (NULL);
		save_fd[i + 1] = '\0';
		*line = ft_strjoin_edit(save_fd, NULL);
		if (*line == NULL)
			return (NULL);
		return (ret);
	}
	*line = ft_strjoin_edit(save_fd, NULL);
	if (*line == NULL)
		return (NULL);
	return (ft_strjoin_edit(NULL, NULL));
}

static char	*free_func(char *buf, char *line, char **save, long long int rc)
{
	if (rc == -10)
	{
		if (*save == NULL)
			rc = -1;
		else if (*save[0] != '\0')
			rc = -5;
	}
	if (rc != -10)
		free(buf);
	if (rc == -5 || rc >= 0)
		return (line);
	if (rc == -1 && line != NULL)
		free(line);
	if (rc == -1 || rc == -10 || rc == 0)
	{
		if (*save != NULL)
			free(*save);
		*save = NULL;
	}
	return (NULL);
}

static char	*init(int fd, char **buf, char **line, ssize_t *rc)
{
	if (BUFFER_SIZE >= SIZE_MAX || BUFFER_SIZE > 9223372036854775807 \
								|| BUFFER_SIZE <= 0 || fd < 0 || fd > 1023)
		return (NULL);
	*buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	*rc = BUFFER_SIZE;
	*line = NULL;
	if (*buf == NULL)
		return (NULL);
	return (*buf);
}

char	*get_next_line(int fd)
{
	ssize_t		rc;
	char		*buf;
	char		*line;
	static char	*save[1024];

	if (init(fd, &buf, &line, &rc) == NULL)
		return (NULL);
	while (rc == BUFFER_SIZE)
	{
		save[fd] = check_save(save[fd], &line);
		if (free_func(buf, line, &save[fd], -10))
			return (line);
		rc = read(fd, buf, BUFFER_SIZE);
		if (rc == -1)
			return (free_func(buf, line, &save[fd], -1));
		if ((!rc && !save[fd]) || (!rc && save[fd] && save[fd][0] == '\0'))
			break ;
		save[fd] = check_buf(buf, rc);
		line = ft_strjoin_edit(line, buf);
		if (line == NULL || save[fd] == NULL)
			return (free_func(buf, line, &save[fd], -1));
		if (save[fd][0] != '\0' || buf[rc -1] == '\n')
			break ;
	}
	return (free_func(buf, line, &save[fd], rc));
}
