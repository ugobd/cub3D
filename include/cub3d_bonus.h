/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugbrouar <ugbrouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:36:01 by ugbrouar          #+#    #+#             */
/*   Updated: 2025/09/09 12:17:51 by ugbrouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>

# include "../MLX42/include/MLX42/MLX42.h"
# include "Libft/libft.h"

# define HEIGHT 768
# define WIDTH 1536
# define GRA 64
# define FOV 3840
# define S_IMG 512

# ifdef PI
#  undef PI
# endif

# define PI 3.1415926535f
# define DR 0.0002727077f

typedef struct s_texture
{
	mlx_texture_t	*no;
	mlx_texture_t	*so;
	mlx_texture_t	*ea;
	mlx_texture_t	*we;
	mlx_texture_t	*door;
	mlx_texture_t	*anim[18];
}					t_texture;

typedef struct s_image
{
	mlx_image_t	*no;
	mlx_image_t	*so;
	mlx_image_t	*ea;
	mlx_image_t	*we;
	mlx_image_t	*door;
	mlx_image_t	*anim[18];
}				t_image;

typedef struct s_ray
{
	float	xray;
	float	yray;
	float	xoff;
	float	yoff;
}			t_ray;

typedef struct s_data
{
	float	x;
	float	y;
	float	pdx;
	float	pdy;
	float	dir;
}			t_data;

typedef struct s_game
{
	char		**map;
	int			mheight;
	int			mwidth;
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_texture	*texture;
	t_image		*image;
	uint32_t	floor;
	uint32_t	ceiling;
	t_data		data;
	int			side;
	int			size;
	float		step;
	float		texy;
	float		texx;
	t_ray		xray;
	t_ray		yray;
	int			frame;
	int			anim_inst;
}				t_game;

//parsing
size_t		ft_arraylen(char **array);
char		*ft_strjoinf(char *s1, char *s2);
void		init_game_null(t_game *game);
int			check_cub(char *str);
int			init_image(t_game *game);

int			nsew(char c);
char		**subarray(char **strs);
int			check_map(char **map);
int			map_surrounded_by_wall(char **map);

char		**cube_map(char **map);

int			init_animation(t_game *game);

int			parsing(char *path, t_game *game);

//game
void		init_game(t_game *game);
t_data		init_pos(t_game *game);

float		ptgr(float x, float y);

//moves
void		move_left(t_game *game);
void		move_right(t_game *game);
void		move_forward(t_game *game);
void		move_backward(t_game *game);

void		open_close_doors(mlx_key_data_t key_data, void *param);
void		mouse_input(void *param);
void		key_input(void *param);

//raycast
float		cast_xray(t_data data, t_game *game, float dir);
float		cast_yray(t_data data, t_game *game, float dir);

//print_wall
void		put_wall(t_game *game, float size, int line);
float		get_wall_size(t_game *game, float dist, float dir);
uint32_t	ft_get_color(mlx_image_t *img, int y, int x);
uint32_t	choose_wall(t_game *game, int texx, int texy);

//minimap
void		put_minimap(t_game *game);

//animation
void		put_anim(t_game *game);
void		animation(void *param);

//free
int			error(t_game *game, char *str);
void		free_all(t_game *game);

#endif
