/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_minimap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thphilip <thphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:51:18 by thphilip          #+#    #+#             */
/*   Updated: 2025/08/11 12:57:22 by thphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	put_square(t_game *game, int posx, int posy, char c)
{
	uint32_t	col;
	int			i;
	int			j;

	if (c == '1')
		col = 0xDDDDDDFF;
	else if (c == '2')
		col = 0xBBBBBBFF;
	else if (c == '3')
		col = 0x555555FF;
	else
		col = 0x333333FF;
	i = 0;
	while (i < 16)
	{
		j = 0;
		while (j < 16)
			mlx_put_pixel(game->img, posx + i, posy + j++, col);
		i++;
	}
}

void	put_player(t_game *game, int to_big)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = game->data.x / 4 + 8;
	if (x > 96 && to_big == 1)
		x -= ((int)(game->data.x) >> 6) * 16 - 80;
	y = game->data.y / 4 + 8;
	if (y > 96 && to_big == 1)
		y -= ((int)(game->data.y) >> 6) * 16 - 80;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			mlx_put_pixel(game->img, x + i, y + j++, 0xFFFF00FF);
		i++;
	}
}

void	put_small_minimap(t_game *game)
{
	int	i;
	int	j;
	int	posx;
	int	posy;

	i = 0;
	posy = 10;
	while (game->map[i])
	{
		j = 0;
		posx = 10;
		while (game->map[i][j])
		{
			put_square(game, posx, posy, game->map[i][j]);
			posx += 16;
			j++;
		}
		posy += 16;
		i++;
	}
	put_player(game, 0);
}

void	put_big_minimap(t_game *game, int posx, int posy)
{
	int	i;
	int	j;

	i = ((int)(game->data.y) >> 6) - 5;
	if (i < 0)
		i = 0;
	while (game->map[i] && i <= ((int)(game->data.y) >> 6) + 5)
	{
		j = ((int)(game->data.x) >> 6) - 5;
		if (j < 0)
			j = 0;
		posx = 10;
		while (game->map[i][j] && j <= ((int)(game->data.x) >> 6) + 5)
		{
			put_square(game, posx, posy, game->map[i][j]);
			posx += 16;
			j++;
		}
		posy += 16;
		i++;
	}
	put_player(game, 1);
}

void	put_minimap(t_game *game)
{
	if (game->mheight < 11 && game->mwidth < 11)
		put_small_minimap(game);
	else
		put_big_minimap(game, 10, 10);
}
