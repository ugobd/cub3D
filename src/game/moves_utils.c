/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugbrouar <ugbrouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:17:57 by thphilip          #+#    #+#             */
/*   Updated: 2025/08/25 13:35:02 by ugbrouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	move_left(t_game *game)
{
	float	strafe;
	int		yl;
	int		xl;
	int		yr;
	int		xr;

	strafe = game->data.dir - PI / 2;
	yl = (int)(game->data.y + sin(strafe) * 20) >> 6;
	xl = (int)(game->data.x) >> 6;
	yr = (int)(game->data.y) >> 6;
	xr = (int)(game->data.x + cos(strafe) * 20) >> 6;
	if (game->map[yl][xl] == '1' && game->map[yr][xr] == '1')
		return ;
	if (game->map[yl][xl] == '1')
	{
		game->data.x += cos(strafe) * 2;
		return ;
	}
	if (game->map[yr][xr] == '1')
	{
		game->data.y += sin(strafe) * 2;
		return ;
	}
	game->data.x += cos(strafe) * 2;
	game->data.y += sin(strafe) * 2;
}

void	move_right(t_game *game)
{
	float	strafe;
	int		yl;
	int		xl;
	int		yr;
	int		xr;

	strafe = game->data.dir + PI / 2;
	yl = (int)(game->data.y + sin(strafe) * 20) >> 6;
	xl = (int)(game->data.x) >> 6;
	yr = (int)(game->data.y) >> 6;
	xr = (int)(game->data.x + cos(strafe) * 20) >> 6;
	if (game->map[yl][xl] == '1' && game->map[yr][xr] == '1')
		return ;
	if (game->map[yl][xl] == '1')
	{
		game->data.x += cos(strafe) * 2;
		return ;
	}
	if (game->map[yr][xr] == '1')
	{
		game->data.y += sin(strafe) * 2;
		return ;
	}
	game->data.x += cos(strafe) * 2;
	game->data.y += sin(strafe) * 2;
}

void	move_forward(t_game *game)
{
	int	yl;
	int	xl;
	int	yr;
	int	xr;

	yl = (int)(game->data.y + game->data.pdy * 26) >> 6;
	xl = (int)(game->data.x) >> 6;
	yr = (int)(game->data.y) >> 6;
	xr = (int)(game->data.x + game->data.pdx * 26) >> 6;
	if (game->map[yl][xl] == '1' && game->map[yr][xr] == '1')
		return ;
	if (game->map[yl][xl] == '1')
	{
		game->data.x += game->data.pdx * 2;
		return ;
	}
	if (game->map[yr][xr] == '1')
	{
		game->data.y += game->data.pdy * 2;
		return ;
	}
	game->data.x += game->data.pdx * 2;
	game->data.y += game->data.pdy * 2;
}

void	move_backward(t_game *game)
{
	int	yl;
	int	xl;
	int	yr;
	int	xr;

	yl = (int)(game->data.y - game->data.pdy * 26) >> 6;
	xl = (int)(game->data.x) >> 6;
	yr = (int)(game->data.y) >> 6;
	xr = (int)(game->data.x - game->data.pdx * 26) >> 6;
	if (game->map[yl][xl] == '1' && game->map[yr][xr] == '1')
		return ;
	if (game->map[yl][xl] == '1')
	{
		game->data.x -= game->data.pdx * 2;
		return ;
	}
	if (game->map[yr][xr] == '1')
	{
		game->data.y -= game->data.pdy * 2;
		return ;
	}
	game->data.x -= game->data.pdx * 2;
	game->data.y -= game->data.pdy * 2;
}
