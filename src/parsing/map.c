/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugbrouar <ugbrouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:02:55 by thphilip          #+#    #+#             */
/*   Updated: 2025/09/09 12:40:41 by ugbrouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	nsew(char c)
{
	if (c == 'N' || c == 'S')
		return (1);
	if (c == 'E' || c == 'W')
		return (1);
	return (0);
}

char	**subarray(char **strs)
{
	char	**cpy;
	int		i;

	cpy = malloc(sizeof(char *) * (ft_arraylen(strs) - 5));
	if (!cpy)
	{
		ft_free_array(strs);
		return (NULL);
	}
	i = 0;
	while (strs[i + 6])
	{
		cpy[i] = ft_strdup(strs[i + 6]);
		if (!cpy[i])
		{
			ft_free_array(strs);
			ft_free_array(cpy);
			return (NULL);
		}
		i++;
	}
	cpy[i] = NULL;
	ft_free_array(strs);
	return (cpy);
}

int	check_map(char **map)
{
	int	i;
	int	j;
	int	nb_p;

	if (ft_arraylen(map) < 9)
		return (1);
	nb_p = 0;
	i = 6;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (nsew(map[i][j]))
				nb_p++;
			if (map[i][j] != '0' && map[i][j] != '1'
					&& map[i][j] != ' ' && !nsew(map[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	if (nb_p != 1)
		return (1);
	return (0);
}

int	check_something(char **map, size_t i, size_t j)
{
	if (i == 6 || i == ft_arraylen(map) - 1)
		return (1);
	if (j == 0 || j == ft_strlen(map[i]) - 1)
		return (1);
	if (map[i + 1][j] != '0' && map[i + 1][j] != '1' && !nsew(map[i + 1][j]))
		return (1);
	if (map[i - 1][j] != '0' && map[i - 1][j] != '1' && !nsew(map[i - 1][j]))
		return (1);
	if (map[i][j + 1] != '0' && map[i][j + 1] != '1' && !nsew(map[i][j + 1]))
		return (1);
	if (map[i][j - 1] != '0' && map[i][j - 1] != '1' && !nsew(map[i][j - 1]))
		return (1);
	return (0);
}

int	map_surrounded_by_wall(char **map)
{
	size_t	i;
	size_t	j;

	i = 6;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || nsew(map[i][j]))
			{
				if (check_something(map, i, j))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
