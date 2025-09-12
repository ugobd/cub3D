/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugbrouar <ugbrouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:54:43 by ugbrouar          #+#    #+#             */
/*   Updated: 2025/07/03 12:07:55 by ugbrouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

int	error(t_game *game, char *str)
{
	printf("Error\n%s\n", str);
	if (game)
		free_all(game);
	return (1);
}

void	free_texture(t_game *game)
{
	int	i;

	if (game->texture->no)
		mlx_delete_texture(game->texture->no);
	if (game->texture->so)
		mlx_delete_texture(game->texture->so);
	if (game->texture->we)
		mlx_delete_texture(game->texture->we);
	if (game->texture->ea)
		mlx_delete_texture(game->texture->ea);
	if (game->texture->door)
		mlx_delete_texture(game->texture->door);
	i = 0;
	while (i < 17)
	{
		if (game->texture->anim[i])
			mlx_delete_texture(game->texture->anim[i]);
		i++;
	}
	free(game->texture);
}

void	free_image(t_game *game)
{
	int	i;

	if (game->image->no)
		mlx_delete_image(game->mlx, game->image->no);
	if (game->image->so)
		mlx_delete_image(game->mlx, game->image->so);
	if (game->image->we)
		mlx_delete_image(game->mlx, game->image->we);
	if (game->image->ea)
		mlx_delete_image(game->mlx, game->image->ea);
	if (game->image->door)
		mlx_delete_image(game->mlx, game->image->door);
	i = 0;
	while (i < 17)
	{
		if (game->image->anim[i])
			mlx_delete_image(game->mlx, game->image->anim[i]);
		i++;
	}
	free(game->image);
}

void	free_all(t_game *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		while (game->map[i])
			free(game->map[i++]);
		free(game->map);
	}
	if (game->texture)
		free_texture(game);
	if (game->image)
		free_image(game);
	if (game->mlx)
		mlx_terminate(game->mlx);
	if (game)
		free(game);
}
