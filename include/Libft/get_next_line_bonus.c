/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thphilip <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:08:55 by thphilip          #+#    #+#             */
/*   Updated: 2024/11/04 17:34:27 by thphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlenchar(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
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
		buffer = ft_strjoin(buffer, line);
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

	line = ft_calloc(sizeof(char), (ft_strlenchar(buffer, '\n') + 2));
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

	i = ft_strlenchar(buffer, '\n');
	j = 0;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	res = ft_calloc(sizeof(char), (ft_strlenchar(buffer, '\0') - i + 1));
	i++;
	while (buffer[i])
		res[j++] = buffer[i++];
	res[j] = '\0';
	free(buffer);
	return (res);
}

char	*get_next_line_bonus(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE < 0)
		return (NULL);
	if (!buffer[fd])
	{
		buffer[fd] = ft_calloc(sizeof(char), 1);
		if (!buffer[fd])
			return (NULL);
	}
	buffer[fd] = ft_read(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_get_line(buffer[fd]);
	if (!line)
		return (NULL);
	buffer[fd] = ft_del_line(buffer[fd]);
	return (line);
}
