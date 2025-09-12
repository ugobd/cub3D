/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thphilip <thphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:31:06 by thphilip          #+#    #+#             */
/*   Updated: 2025/08/18 14:42:27 by thphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	turn_left(t_game *game)
{
	game->data.dir -= DR * GRA * 2;
	if (game->data.dir < 0)
		game->data.dir += 2 * PI;
	game->data.pdx = cos(game->data.dir);
	game->data.pdy = sin(game->data.dir);
}

void	turn_right(t_game *game)
{
	game->data.dir += DR * GRA * 2;
	if (game->data.dir > 2 * PI)
		game->data.dir -= 2 * PI;
	game->data.pdx = cos(game->data.dir);
	game->data.pdy = sin(game->data.dir);
}

void	key_input(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_forward(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_backward(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		move_left(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		move_right(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		turn_left(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		turn_right(game);
}
