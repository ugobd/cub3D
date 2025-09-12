/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugbrouar <ugbrouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 12:27:39 by thphilip          #+#    #+#             */
/*   Updated: 2025/09/11 14:28:24 by ugbrouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	put_anim(t_game *game)
{
	int	i;

	i = 0;
	while (game->image->anim[i])
	{
		mlx_image_to_window(game->mlx, game->image->anim[i], 736, 318);
		game->image->anim[i++]->enabled = false;
	}
}

void	animation(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	game->image->anim[game->anim_inst]->enabled = false;
	game->anim_inst++;
	if (!game->image->anim[game->anim_inst])
		game->anim_inst = 0;
	game->image->anim[game->anim_inst]->enabled = true;
	game->frame++;
}
