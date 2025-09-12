/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thphilip <thphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:17:57 by thphilip          #+#    #+#             */
/*   Updated: 2025/08/25 16:58:00 by thphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

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
	if ((game->map[yl][xl] == '1' && game->map[yr][xr] == '1') ||
		(game->map[yl][xl] == '2' && game->map[yr][xr] == '2'))
		return ;
	if (game->map[yl][xl] == '1' || game->map[yl][xl] == '2')
		game->data.x += cos(strafe) * 2;
	else if (game->map[yr][xr] == '1' || game->map[yr][xr] == '2')
		game->data.y += sin(strafe) * 2;
	else
	{
		game->data.x += cos(strafe) * 2;
		game->data.y += sin(strafe) * 2;
	}
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
	if ((game->map[yl][xl] == '1' && game->map[yr][xr] == '1') ||
		(game->map[yl][xl] == '2' && game->map[yr][xr] == '2'))
		return ;
	if (game->map[yl][xl] == '1' || game->map[yl][xl] == '2')
		game->data.x += cos(strafe) * 2;
	else if (game->map[yr][xr] == '1' || game->map[yr][xr] == '2')
		game->data.y += sin(strafe) * 2;
	else
	{
		game->data.x += cos(strafe) * 2;
		game->data.y += sin(strafe) * 2;
	}
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
	if ((game->map[yl][xl] == '1' && game->map[yr][xr] == '1') ||
		(game->map[yl][xl] == '2' && game->map[yr][xr] == '2'))
		return ;
	if (game->map[yl][xl] == '1' || game->map[yl][xl] == '2')
		game->data.x += game->data.pdx * 2;
	else if (game->map[yr][xr] == '1' || game->map[yr][xr] == '2')
		game->data.y += game->data.pdy * 2;
	else
	{
		game->data.x += game->data.pdx * 2;
		game->data.y += game->data.pdy * 2;
	}
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
	if ((game->map[yl][xl] == '1' && game->map[yr][xr] == '1') ||
		(game->map[yl][xl] == '2' && game->map[yr][xr] == '2'))
		return ;
	if (game->map[yl][xl] == '1' || game->map[yl][xl] == '2')
		game->data.x -= game->data.pdx * 2;
	else if (game->map[yr][xr] == '1' || game->map[yr][xr] == '2')
		game->data.y -= game->data.pdy * 2;
	else
	{
		game->data.x -= game->data.pdx * 2;
		game->data.y -= game->data.pdy * 2;
	}
}
