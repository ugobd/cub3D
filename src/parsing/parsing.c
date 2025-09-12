/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thphilip <thphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 11:57:06 by ugbrouar          #+#    #+#             */
/*   Updated: 2025/08/28 11:44:53 by thphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	get_color(t_game *game, uint32_t *color, char *str)
{
	char	**strs;

	strs = ft_split(str, ',');
	if (!strs)
		return (error(game, "malloc failed"));
	if (ft_arraylen(strs) != 3)
		error(game, "Invalid color declaration");
	else if (ft_atoi(strs[0]) >= 256 || ft_atoi(strs[0]) < 0)
		error(game, "Invalid color declaration");
	else if (ft_atoi(strs[1]) >= 256 || ft_atoi(strs[1]) < 0)
		error(game, "Invalid color declaration");
	else if (ft_atoi(strs[2]) >= 256 || ft_atoi(strs[2]) < 0)
		error(game, "Invalid color declaration");
	else
	{
		*color = (uint8_t)ft_atoi(strs[0]);
		*color = *color * 256 + (uint8_t)ft_atoi(strs[1]);
		*color = *color * 256 + (uint8_t)ft_atoi(strs[2]);
		*color = *color * 256 + (uint8_t)255;
		ft_free_array(strs);
		return (0);
	}
	ft_free_array(strs);
	return (1);
}

int	set_color(t_game *game, char **map)
{
	if (!ft_strcmp(map[0], "F"))
	{
		if (get_color(game, &game->floor, map[1]))
		{
			ft_free_array(map);
			return (1);
		}
		return (0);
	}
	else if (!ft_strcmp(map[0], "C"))
	{
		if (get_color(game, &game->ceiling, map[1]))
		{
			ft_free_array(map);
			return (1);
		}
		return (0);
	}
	ft_free_array(map);
	return (error(game, "Unknown line declaration"));
}

int	init_texture(t_game *game, char *str)
{
	char	**map;

	map = ft_split(str, ' ');
	if (!map)
		return (error(game, "Malloc failed"));
	if (ft_arraylen(map) != 2)
	{
		ft_free_array(map);
		return (error(game, "Invalid line declaration"));
	}
	if (!ft_strcmp(map[0], "NO") && !game->texture->no)
		game->texture->no = mlx_load_png(map[1]);
	else if (!ft_strcmp(map[0], "SO") && !game->texture->so)
		game->texture->so = mlx_load_png(map[1]);
	else if (!ft_strcmp(map[0], "WE") && !game->texture->we)
		game->texture->we = mlx_load_png(map[1]);
	else if (!ft_strcmp(map[0], "EA") && !game->texture->ea)
		game->texture->ea = mlx_load_png(map[1]);
	else if (set_color(game, map))
		return (1);
	ft_free_array(map);
	return (0);
}

int	get_utils(t_game *game, int fd)
{
	char	*map;
	char	*tmp;
	int		i;

	map = NULL;
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		map = ft_strjoinf(map, tmp);
	}
	game->map = ft_split(map, '\n');
	free(map);
	close(fd);
	if (!game->map)
		return (error(game, "malloc failed"));
	i = 0;
	while (i < 6)
		if (init_texture(game, game->map[i++]))
			return (1);
	if (!game->texture->no || !game->texture->so
		|| !game->texture->ea || !game->texture->we)
		return (error(game, "Unable to load textures"));
	return (0);
}

int	parsing(char *path, t_game *game)
{
	int	fd;

	game->texture = malloc(sizeof(t_texture));
	game->image = malloc(sizeof(t_image));
	init_game_null(game);
	if (!game->texture || !game->image)
		return (error(game, "Malloc failed"));
	if (check_cub(path) == 1)
		return (error(game, "Map not found"));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (error(game, "Unable to open the map"));
	if (get_utils(game, fd) == 1)
		return (1);
	if (check_map(game->map) == 1)
		return (error(game, "Invalid map"));
	if (map_surrounded_by_wall(game->map) == 1)
		return (error(game, "Map not surrounded by Wall"));
	game->map = subarray(game->map);
	game->map = cube_map(game->map);
	if (!game->map)
		return (error(game, "Malloc failed"));
	game->mheight = ft_arraylen(game->map);
	game->mwidth = ft_strlen(game->map[0]);
	return (0);
}
