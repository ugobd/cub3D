/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thphilip <thphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:42:52 by thphilip          #+#    #+#             */
/*   Updated: 2025/08/25 15:54:21 by thphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

float	get_xray(t_data data, t_game *game)
{
	int	x;
	int	y;

	while (1)
	{
		x = (int)(game->xray.xray) >> 6;
		y = (int)(game->xray.yray) >> 6;
		if (x < 0 || y < 0)
			return (-1);
		if (y > game->mheight - 1)
			return (-1);
		if (x > game->mwidth - 1)
			return (-1);
		if (game->map[y][x] == '1' || game->map[y][x] == '2')
			break ;
		game->xray.xray += game->xray.xoff;
		game->xray.yray += game->xray.yoff;
	}
	return (ptgr(game->xray.xray - data.x, game->xray.yray - data.y));
}

float	get_yray(t_data data, t_game *game)
{
	int	x;
	int	y;

	while (1)
	{
		x = (int)(game->yray.xray) >> 6;
		y = (int)(game->yray.yray) >> 6;
		if (x < 0 || y < 0)
			return (-1);
		if (y > game->mheight - 1)
			return (-1);
		if (x > game->mwidth - 1)
			return (-1);
		if (game->map[y][x] == '1' || game->map[y][x] == '2')
			break ;
		game->yray.xray += game->yray.xoff;
		game->yray.yray += game->yray.yoff;
	}
	return (ptgr(game->yray.xray - data.x, game->yray.yray - data.y));
}

float	cast_xray(t_data data, t_game *game, float dir)
{
	float	atan;

	atan = -1 / tan(dir);
	if (dir == 0 || dir == PI)
		return (-1);
	if (dir > PI)
	{
		game->xray.yray = (((int)data.y >> 6) << 6) - 0.0001;
		game->xray.xray = (data.y - game->xray.yray) * atan + data.x;
		game->xray.yoff = -64;
		game->xray.xoff = 64 * atan;
	}
	else if (dir < PI)
	{
		game->xray.yray = (((int)data.y >> 6) << 6) + 64;
		game->xray.xray = (data.y - game->xray.yray) * atan + data.x;
		game->xray.yoff = 64;
		game->xray.xoff = -64 * atan;
	}
	else
		return (-1);
	return (get_xray(data, game));
}

float	cast_yray(t_data data, t_game *game, float dir)
{
	float	atan;

	atan = -tan(dir);
	if (dir == PI / 2 || dir == 3 * PI / 2)
		return (-1);
	if (dir > PI / 2 && dir < 3 * PI / 2)
	{
		game->yray.xray = (((int)data.x >> 6) << 6) - 0.0001;
		game->yray.yray = (data.x - game->yray.xray) * atan + data.y;
		game->yray.xoff = -64;
		game->yray.yoff = 64 * atan;
	}
	else if (dir < PI / 2 || dir > 3 * PI / 2)
	{
		game->yray.xray = (((int)data.x >> 6) << 6) + 64;
		game->yray.yray = (data.x - game->yray.xray) * atan + data.y;
		game->yray.xoff = 64;
		game->yray.yoff = -64 * atan;
	}
	else
		return (-1);
	return (get_yray(data, game));
}
