/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_moves_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thphilip <thphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:31:06 by thphilip          #+#    #+#             */
/*   Updated: 2025/08/18 15:17:03 by thphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	open_close_doors(mlx_key_data_t key_data, void *param)
{
	t_game	*game;
	int		ydoors;
	int		yplayer;
	int		xdoors;
	int		xplayer;

	(void) key_data;
	game = (t_game *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_E))
	{
		ydoors = (int)(game->data.y + game->data.pdy * 60) >> 6;
		yplayer = (int)(game->data.y + game->data.pdy) >> 6;
		xdoors = (int)(game->data.x + game->data.pdx * 60) >> 6;
		xplayer = (int)(game->data.x + game->data.pdx) >> 6;
		if (game->map[ydoors][xdoors] == '2')
			game->map[ydoors][xdoors] = '3';
		else if (game->map[ydoors][xdoors] == '3'
				&& (ydoors != yplayer || xdoors != xplayer))
			game->map[ydoors][xdoors] = '2';
	}
}

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

void	mouse_input(void *param)
{
	t_game	*game;
	int		x;
	int		y;

	game = (t_game *)param;
	mlx_get_mouse_pos(game->mlx, &x, &y);
	if (x <= 200)
		turn_left(game);
	else if (x > WIDTH - 200)
		turn_right(game);
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
