/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloubiat <sloubiat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:48:25 by sloubiat          #+#    #+#             */
/*   Updated: 2025/11/28 15:35:49 by sloubiat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strdup(char *s)
{
	int		size;
	char	*c;
	int		i;

	i = 0;
	size = ft_strlen(s);
	c = malloc(sizeof(char) * (size + 1));
	if (!c)
		return (0);
	while (s[i])
	{
		c[i] = s[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}

char	*ft_strchr(char *s, int c)
{
	unsigned int	i;
	char			cc;

	cc = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char *) &s[i]);
	return (NULL);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (malloc(1));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		size;
	int		i;
	int		j;

	size = ft_strlen(s1) + ft_strlen(s2);
	join = (char *) malloc(sizeof(char) * (size + 1));
	if (!join)
		return (0);
	i = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		join[i] = s2[j];
		i++;
		j++;
	}
	join[i] = '\0';
	return (join);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
