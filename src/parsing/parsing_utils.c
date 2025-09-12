/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugbrouar <ugbrouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:06:59 by ugbrouar          #+#    #+#             */
/*   Updated: 2025/09/09 12:30:46 by ugbrouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

size_t	ft_arraylen(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	init_image(t_game *game)
{
	game->image->no = mlx_texture_to_image(game->mlx, game->texture->no);
	game->image->so = mlx_texture_to_image(game->mlx, game->texture->so);
	game->image->we = mlx_texture_to_image(game->mlx, game->texture->we);
	game->image->ea = mlx_texture_to_image(game->mlx, game->texture->ea);
	if (!game->image->no || !game->image->so || !game->image->we
		|| !game->image->ea)
		return (1);
	mlx_resize_image(game->image->no, S_IMG, S_IMG);
	mlx_resize_image(game->image->so, S_IMG, S_IMG);
	mlx_resize_image(game->image->we, S_IMG, S_IMG);
	mlx_resize_image(game->image->ea, S_IMG, S_IMG);
	return (0);
}

int	check_cub(char *str)
{
	if (ft_strlen(str) < 5)
		return (1);
	if (str[ft_strlen(str) - 1] != 'b' || str[ft_strlen(str) - 2] != 'u')
		return (1);
	if (str[ft_strlen(str) - 3] != 'c' || str[ft_strlen(str) - 4] != '.')
		return (1);
	return (0);
}

char	*ft_strjoinf(char *s1, char *s2)
{
	char	*str;

	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	str = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (str);
}

void	init_game_null(t_game *game)
{
	game->map = NULL;
	game->mlx = NULL;
	if (game->texture)
	{
		game->texture->no = NULL;
		game->texture->so = NULL;
		game->texture->we = NULL;
		game->texture->ea = NULL;
	}
	if (game->image)
	{
		game->image->no = NULL;
		game->image->so = NULL;
		game->image->we = NULL;
		game->image->ea = NULL;
		game->img = NULL;
	}
}
