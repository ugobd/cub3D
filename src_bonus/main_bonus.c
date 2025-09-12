/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugbrouar <ugbrouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:39:36 by ugbrouar          #+#    #+#             */
/*   Updated: 2025/09/11 14:53:00 by ugbrouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

int	pars_define(void)
{
	if (WIDTH < 1 || WIDTH > 10000)
	{
		error(NULL, "WIDTH value is invalid (1 <= WIDTH <= 20000)");
		printf("and yes 20000 because it's realy funny, try it !\n");
		return (1);
	}
	if (HEIGHT < 1 || HEIGHT > 1080)
	{
		error(NULL, "HEIGHT value is invalid (1 <= HEIGHT <= 1080)");
		printf("and yes 1 because it's realy funny, try it !\n");
		return (1);
	}
	if (GRA < 1 || GRA > 100)
		return (error(NULL, "GRA value is invalid (1 <= GRA <= 100)"));
	if (FOV < 20 * GRA || FOV > 80 * GRA)
		return (error(NULL, "FOV value is invalid (20 <= FOV <= 80)"));
	if (PI != 3.1415926535f)
		return (error(NULL, "PI value cannot be changed (PI = 3.1415926535f)"));
	if (DR != (0.0174532925f / GRA))
		return (error(NULL, "DR value cannot be changed"));
	return (0);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		return (error(NULL, "wrong number of argument (1 expected)"));
	if (pars_define())
		return (1);
	game = malloc(sizeof(t_game));
	if (!game)
		return (error(NULL, "malloc failed"));
	game->map = NULL;
	game->mlx = NULL;
	if (parsing(av[1], game) == 1)
		return (1);
	game->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (!game->mlx)
		return (error(game, "mlx_init error"));
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx_set_window_size(game->mlx, WIDTH, HEIGHT);
	if (init_image(game) == 1)
		return (error(game, "Unable to load image"));
	if (init_animation(game))
		return (1);
	init_game(game);
	free_all(game);
	return (0);
}
