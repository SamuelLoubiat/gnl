/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloubiat <sloubiat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:48:34 by sloubiat          #+#    #+#             */
/*   Updated: 2025/11/28 15:37:04 by sloubiat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static void	free_buffer(char *buffer, char *rest)
{
	buffer[0] = 0;
	rest[0] = 0;
}

static char	*find_line_end(int fd, char *rest, char *buffer)
{
	int		readed;
	char	*line;
	char	*tmp;

	line = ft_strdup(rest);
	if (!line)
		return (0);
	rest[0] = '\0';
	readed = 1;
	if (ft_strchr(line, '\n'))
		readed = 0;
	while (readed > 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == 0)
			return (line);
		if (readed < 0)
			return (0);
		buffer[readed] = '\0';
		tmp = line;
		line = ft_strjoin(tmp, buffer);
		if (!line)
		{
			free(tmp);
			return (0);
		}
		free(tmp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (line);
}

static char	*fill_rest(char *rest, char *line)
{
	int	i;
	char *tmp;
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

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free_buffer(rest, buffer);
		return (0);
	}
	line = find_line_end(fd, rest, buffer);
	if (!line || !line[0])
	{
		free(line);
		free_buffer(rest, buffer);
		return (0);
	}
	line = fill_rest(rest, line);
	return (line);
}
