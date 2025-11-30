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

static char	*find_line_end(int fd, char *rest, char *buffer)
{
	int		readed;
	char	*temp;

	readed = 1;
	while (readed > 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
		{
			free(rest);
			return (0);
		}
		if (readed == 0)
			break ;
		buffer[readed] = '\0';
		if (!rest)
			rest = ft_strdup("");
		temp = rest;
		rest = ft_strjoin(temp, buffer);
		free(temp);
		temp = 0;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (rest);
}

static char	*get_line(char *line)
{
	int		i;
	char	*rest;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (!line[i] || !line[1])
		return (0);
	rest = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!rest)
	{
		free(rest);
		rest = 0;
		return (0);
	}
	line[i + 1] = 0;
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;
	char		*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		free(rest);
		buffer = 0;
		return (0);
	}
	line = find_line_end(fd, rest, buffer);
	free(buffer);
	if (!line)
		return (0);
	rest = get_line(line);
	return (line);
}
