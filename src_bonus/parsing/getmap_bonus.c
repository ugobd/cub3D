/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thphilip <thphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 12:49:08 by thphilip          #+#    #+#             */
/*   Updated: 2025/08/28 11:46:09 by thphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

size_t	get_max_size(char **map)
{
	size_t	max_size;
	int		i;

	max_size = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (max_size < ft_strlen(map[i]))
			max_size = ft_strlen(map[i]);
		i++;
	}
	return (max_size);
}

char	**replace_spaces(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ' ')
				map[i][j] = '1';
			j++;
		}
		i++;
	}
	return (map);
}

char	*ft_strscpy(char *str, size_t size)
{
	char	*cpy;
	size_t	i;

	cpy = malloc(sizeof(char) * (size + 1));
	if (!cpy)
		return (str);
	i = 0;
	while (str[i])
	{
		cpy[i] = str[i];
		i++;
	}
	while (i < size)
		cpy[i++] = '1';
	cpy[i] = '\0';
	free(str);
	return (cpy);
}

char	**cube_map(char **map)
{
	size_t	max_size;
	int		i;

	if (!map)
		return (NULL);
	max_size = get_max_size(map);
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) < max_size)
		{
			map[i] = ft_strscpy(map[i], max_size);
			if (ft_strlen(map[i]) != max_size)
			{
				ft_free_array(map);
				return (NULL);
			}
		}
		i++;
	}
	replace_spaces(map);
	return (map);
}
