/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloubiat <sloubiat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:48:34 by sloubiat          #+#    #+#             */
/*   Updated: 2025/12/05 18:05:29 by sloubiat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static void	reset_buffers(char *buffer, char *rest)
{
	buffer[0] = '\0';
	rest[0] = '\0';
}

static char	*join_and_free(char *s1, char *s2)
{
	char	*line;

	line = ft_strjoin(s1, s2);
	free(s1);
	return (line);
}

static char	*read_line(int fd, char *rest, char *buffer)
{
	int		bytes;
	char	*line;

	line = ft_strdup(rest);
	if (!line)
		return (NULL);
	bytes = 1;
	if (ft_strchr(line, '\n'))
		return (line);
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free(line), NULL);
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

static char	*extract_rest(char *rest, char *line)
{
	int		i;
	char	*tmp;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
	{
		i++;
		ft_strlcpy(rest, &line[i], BUFFER_SIZE);
		line[i] = '\0';
		tmp = line;
		line = ft_strdup(tmp);
		free(tmp);
	}
	else
	{
		rest[0] = '\0';
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	rest[BUFFER_SIZE + 1];
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		reset_buffers(buffer, rest);
		return (0);
	}
	line = read_line(fd, rest, buffer);
	if (!line || !line[0])
	{
		free(line);
		reset_buffers(buffer, rest);
		return (0);
	}
	line = extract_rest(rest, line);
	return (line);
}
