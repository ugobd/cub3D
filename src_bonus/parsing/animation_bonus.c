/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thphilip <thphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 11:40:55 by thphilip          #+#    #+#             */
/*   Updated: 2025/08/28 11:45:57 by thphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	init_image_anim(t_game *game)
{
	mlx_t	*m;

	m = game->mlx;
	game->image->anim[0] = mlx_texture_to_image(m, game->texture->anim[0]);
	game->image->anim[1] = mlx_texture_to_image(m, game->texture->anim[1]);
	game->image->anim[2] = mlx_texture_to_image(m, game->texture->anim[2]);
	game->image->anim[3] = mlx_texture_to_image(m, game->texture->anim[3]);
	game->image->anim[4] = mlx_texture_to_image(m, game->texture->anim[4]);
	game->image->anim[5] = mlx_texture_to_image(m, game->texture->anim[5]);
	game->image->anim[6] = mlx_texture_to_image(m, game->texture->anim[6]);
	game->image->anim[7] = mlx_texture_to_image(m, game->texture->anim[7]);
	game->image->anim[8] = mlx_texture_to_image(m, game->texture->anim[8]);
	game->image->anim[9] = mlx_texture_to_image(m, game->texture->anim[9]);
	game->image->anim[10] = mlx_texture_to_image(m, game->texture->anim[10]);
	game->image->anim[11] = mlx_texture_to_image(m, game->texture->anim[11]);
	game->image->anim[12] = mlx_texture_to_image(m, game->texture->anim[12]);
	game->image->anim[13] = mlx_texture_to_image(m, game->texture->anim[13]);
	game->image->anim[14] = mlx_texture_to_image(m, game->texture->anim[14]);
	game->image->anim[15] = mlx_texture_to_image(m, game->texture->anim[15]);
	game->image->anim[16] = mlx_texture_to_image(m, game->texture->anim[16]);
}

void	init_texture_anim(t_game *game)
{
	game->texture->anim[0] = mlx_load_png("textures_bonus/anim_frame_0.png");
	game->texture->anim[1] = mlx_load_png("textures_bonus/anim_frame_1a.png");
	game->texture->anim[2] = mlx_load_png("textures_bonus/anim_frame_1b.png");
	game->texture->anim[3] = mlx_load_png("textures_bonus/anim_frame_2.png");
	game->texture->anim[4] = mlx_load_png("textures_bonus/anim_frame_3.png");
	game->texture->anim[5] = mlx_load_png("textures_bonus/anim_frame_4.png");
	game->texture->anim[6] = mlx_load_png("textures_bonus/anim_frame_5.png");
	game->texture->anim[7] = mlx_load_png("textures_bonus/anim_frame_6.png");
	game->texture->anim[8] = mlx_load_png("textures_bonus/anim_frame_7.png");
	game->texture->anim[9] = mlx_load_png("textures_bonus/anim_frame_8.png");
	game->texture->anim[10] = mlx_load_png("textures_bonus/anim_frame_9.png");
	game->texture->anim[11] = mlx_load_png("textures_bonus/anim_frame_10.png");
	game->texture->anim[12] = mlx_load_png("textures_bonus/anim_frame_11.png");
	game->texture->anim[13] = mlx_load_png("textures_bonus/anim_frame_12.png");
	game->texture->anim[14] = mlx_load_png("textures_bonus/anim_frame_13.png");
	game->texture->anim[15] = mlx_load_png("textures_bonus/anim_frame_14.png");
	game->texture->anim[16] = mlx_load_png("textures_bonus/anim_frame_15.png");
}

int	init_animation(t_game *game)
{
	int	i;

	init_texture_anim(game);
	i = 0;
	while (i < 17)
	{
		if (!game->texture->anim[i++])
			return (error(game, "animation : failed to load png"));
	}
	init_image_anim(game);
	i = 0;
	while (i < 17)
	{
		if (!game->image->anim[i++])
			return (error(game, "animation : failed to load image"));
	}
	game->frame = 0;
	game->anim_inst = 0;
	return (0);
}
