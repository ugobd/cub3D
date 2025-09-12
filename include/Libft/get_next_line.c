/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugbrouar <ugbrouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:08:55 by thphilip          #+#    #+#             */
/*   Updated: 2025/08/25 13:23:44 by ugbrouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*tab;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	tab = malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (tab == NULL)
		return (NULL);
	while (s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
		tab[j++] = s2[i++];
	tab[j] = '\0';
	free(s1);
	return (tab);
}

static char	*ft_read(int fd, char *buffer)
{
	char	*line;
	int		i;

	line = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	i = 1;
	while (i > 0 && !ft_strchr(buffer, '\n'))
	{
		i = read(fd, line, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			free(line);
			return (NULL);
		}
		line[i] = '\0';
		buffer = ft_strjoin_gnl(buffer, line);
	}
	free(line);
	if (i == 0 && !buffer[0])
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

static char	*ft_get_line(char *buffer)
{
	char	*line;
	int		i;

	line = ft_calloc(sizeof(char), (ft_strlenc(buffer, '\n') + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i] = '\n';
	line[i + 1] = '\0';
	return (line);
}

static char	*ft_del_line(char *buffer)
{
	int		i;
	int		j;
	char	*res;

	i = ft_strlenc(buffer, '\n');
	j = 0;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	res = ft_calloc(sizeof(char), (ft_strlenc(buffer, '\0') - i + 1));
	i++;
	while (buffer[i])
		res[j++] = buffer[i++];
	res[j] = '\0';
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (!buffer)
	{
		buffer = ft_calloc(sizeof(char), 1);
		if (!buffer)
			return (NULL);
	}
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	if (!line)
		return (NULL);
	buffer = ft_del_line(buffer);
	return (line);
}
