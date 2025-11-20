/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloubiat <sloubiat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:48:34 by sloubiat          #+#    #+#             */
/*   Updated: 2025/11/20 18:07:29 by sloubiat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char buffer[42];
	int	rd;

	while ((rd = read(fd, buffer, 42)))
	{
		buffer[rd] = '\0';
		printf("\n'%s'\n", buffer);
	}
	return (buffer);
}

int main(void)
{
	int fd = open("test.c", O_RDONLY);
	get_next_line(fd);
	return (0);
}
