/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloubiat <sloubiat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 23:48:34 by sloubiat          #+#    #+#             */
/*   Updated: 2026/04/01 23:51:29 by sloubiat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*ft_free(char *str)
{
	free(str);
	return (0);
}

static char	*join_and_free(char *s1, char *s2)
{
	char	*line;

	line = ft_strjoin(s1, s2);
	free(s1);
	return (line);
}

static char	*read_line(int fd, char *buffer)
{
	int		bytes;
	char	*line;

	line = ft_strdup(buffer);
	if (!line)
		return (0);
	bytes = 1;
	if (ft_strchr(line, '\n'))
		return (line);
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (ft_free(line));
		if (bytes == 0)
			return (line);
		buffer[bytes] = '\0';
		line = join_and_free(line, buffer);
		if (!line)
			return (0);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (line);
}

static char	*extract_rest(char *buffer, char *line)
{
	int		i;
	char	*tmp;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
	{
		i++;
		ft_strlcpy(buffer, &line[i], BUFFER_SIZE);
		line[i] = '\0';
		tmp = line;
		line = ft_strdup(tmp);
		free(tmp);
	}
	else
		buffer[0] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line = read_line(fd, buffer[fd]);
	if (!line || !line[0])
	{
		buffer[fd][0] = '\0';
		return (ft_free(line));
	}
	line = extract_rest(buffer[fd], line);
	return (line);
}
