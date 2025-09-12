/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugbrouar <ugbrouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:54:36 by thphilip          #+#    #+#             */
/*   Updated: 2025/09/11 14:26:17 by ugbrouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

float	get_dir(char c)
{
	if (c == 'N')
		return (3 * PI / 2);
	if (c == 'E')
		return (0);
	if (c == 'S')
		return (PI / 2);
	return (PI);
}

t_data	init_pos(t_game *game)
{
	t_data	data;
	int		i;
	int		j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (nsew(game->map[i][j]))
			{
				data.x = j * 64 + 32;
				data.y = i * 64 + 32;
				data.dir = get_dir(game->map[i][j]);
				data.pdx = cos(data.dir);
				data.pdy = sin(data.dir);
			}
			j++;
		}
		i++;
	}
	return (data);
}

float	ptgr(float x, float y)
{
	float	res;

	res = sqrt(x * x + y * y);
	return (res);
}

void	dim_img(t_game *game)
{
	if (game->side == 3 || game->side == 4 || game->side == 6)
	{
		game->texx = game->xray.xray / 2.0f / 32.0f;
		if (game->side == 4)
			game->texx = S_IMG - game->texx;
	}
	if (game->side == 1 || game->side == 2 || game->side == 5)
	{
		game->texx = game->yray.yray / 2.0f / 32.0f;
		if (game->side == 1)
			game->texx = S_IMG - game->texx;
	}
}

float	get_wall_size(t_game *game, float dist, float dir)
{
	float	size;
	float	fixe;

	fixe = game->data.dir - dir;
	if (fixe < 0)
		fixe += 2 * PI;
	else if (fixe > 2 * PI)
		fixe -= 2 * PI;
	dist *= cos(fixe);
	dim_img(game);
	game->texx -= floor(game->texx);
	game->texx *= (float)(S_IMG - 1);
	size = HEIGHT * 80 / dist;
	game->step = S_IMG / size;
	game->size = size;
	if (size > HEIGHT || size < 0)
	{
		game->size = HEIGHT;
		game->texy += game->step * ((size - HEIGHT) / 2);
	}
	return (size);
}
