/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thphilip <thphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:42:00 by ugbrouar          #+#    #+#             */
/*   Updated: 2025/08/26 18:31:30 by thphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

uint32_t	ft_get_color(mlx_image_t *img, int y, int x)
{
	return ((uint32_t)((img->pixels[(y * S_IMG + x) * 4] << 24)
		| ((img->pixels[(y * S_IMG + x) * 4 + 1]) << 16)
		| ((img->pixels[(y * S_IMG + x) * 4 + 2]) << 8)
		| (img->pixels[(y * S_IMG + x) * 4 + 3])));
}

uint32_t	choose_wall(t_game *game, int texx, int texy)
{
	uint32_t	color;

	color = 0;
	if (texy < 0 || texy >= S_IMG)
		return (0);
	if (texx < 0 || texx >= S_IMG)
		return (0);
	if (game->side == 1)
		color = ft_get_color(game->image->we, texy, texx);
	else if (game->side == 2)
		color = ft_get_color(game->image->ea, texy, texx);
	else if (game->side == 3)
		color = ft_get_color(game->image->no, texy, texx);
	else if (game->side == 4)
		color = ft_get_color(game->image->so, texy, texx);
	return (color);
}

void	print_wall(t_game *game, int line, int *y)
{
	uint32_t	color;
	int			x;

	while (*y < HEIGHT / 2 + game->size / 2)
	{
		x = line;
		game->texy += game->step;
		color = choose_wall(game, game->texx, game->texy);
		while (x <= line + WIDTH / FOV)
		{
			if (*y < 0 || *y > HEIGHT)
				x++;
			else
				mlx_put_pixel(game->img, x++, *y, color);
		}
		*y = *y + 1;
	}
}

void	p_col(t_game *game, int indices[2], int *y, uint32_t col)
{
	int	x;

	while (*y < indices[1])
	{
		x = indices[0];
		while (x <= indices[0] + WIDTH / FOV)
			mlx_put_pixel(game->img, x++, *y, col);
		*y = *y + 1;
	}
}

void	put_wall(t_game *game, float size, int line)
{
	int			y;

	y = 0;
	if (size < 50)
	{
		p_col(game, (int [2]){line, HEIGHT / 2 - 25}, &y, game->ceiling);
		p_col(game, (int [2]){line, HEIGHT / 2 + 25}, &y, 0xA0A0A0FF);
		p_col(game, (int [2]){line, HEIGHT}, &y, game->floor);
	}
	else
	{
		p_col(game, (int [2]){line, HEIGHT / 2 - size / 2}, &y, game->ceiling);
		print_wall(game, line, &y);
		p_col(game, (int [2]){line, HEIGHT}, &y, game->floor);
	}
}
