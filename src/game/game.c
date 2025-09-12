/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thphilip <thphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:54:26 by thphilip          #+#    #+#             */
/*   Updated: 2025/08/28 11:43:57 by thphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	get_side(t_game *game, int boolean, float dir)
{
	if (boolean == 0)
	{
		if (dir > PI / 2 && dir < 3 * PI / 2)
			game->side = 1;
		else
			game->side = 2;
	}
	if (boolean == 1)
	{
		if (dir > PI)
			game->side = 3;
		else
			game->side = 4;
	}
}

float	cast_ray(t_data data, t_game *game, float dir)
{
	float	xdist;
	float	ydist;

	xdist = cast_xray(data, game, dir);
	ydist = cast_yray(data, game, dir);
	if (xdist == -1)
	{
		get_side(game, 0, dir);
		return (ydist);
	}
	else if (ydist == -1)
	{
		get_side(game, 1, dir);
		return (xdist);
	}
	else if (xdist < ydist)
	{
		get_side(game, 1, dir);
		return (xdist);
	}
	else
	{
		get_side(game, 0, dir);
		return (ydist);
	}
}

void	multy_cast_ray(void *param)
{
	t_game	*game;
	float	size;
	float	line;
	float	dir;
	int		i;

	game = (t_game *)param;
	line = 0;
	i = -(FOV / 2);
	while (i < (FOV / 2))
	{
		dir = game->data.dir + (i * DR);
		if (dir < 0)
			dir += 2 * PI;
		else if (dir > 2 * PI)
			dir -= 2 * PI;
		game->texy = 0;
		size = cast_ray(game->data, game, dir);
		size = get_wall_size(game, size, dir);
		put_wall(game, size, (int)line);
		line += (float)WIDTH / (float)FOV;
		i++;
	}
}

void	init_game(t_game *game)
{
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img)
		return ;
	mlx_image_to_window(game->mlx, game->img, 0, 0);
	game->data = init_pos(game);
	mlx_loop_hook(game->mlx, &key_input, game);
	mlx_loop_hook(game->mlx, &multy_cast_ray, game);
	mlx_loop(game->mlx);
	mlx_delete_image(game->mlx, game->img);
}
