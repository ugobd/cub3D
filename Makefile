# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ugbrouar <ugbrouar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 10:17:48 by ugbrouar          #+#    #+#              #
#    Updated: 2025/08/27 12:55:41 by ugbrouar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
NAME_BONUS = cub3D_bonus

CC= cc
CFLAGS = -Wall -Werror -Wextra -g
MLXFLAGS= -ldl -lX11 -lglfw -lm -lz -lbsd -lXext

INCLUD = -I./include
INCLUD_BONUS = -I./include_bonus

LIBFT_HEAD = ./include/Libft/include
LIBFT_HEAD_BONUS = ./include_bonus/Libft/include

SRC = 	main.c \
		parsing/parsing.c \
		parsing/parsing_utils.c \
		parsing/map.c \
		parsing/getmap.c \
		game/game.c \
		game/game_utils.c \
		game/print_wall.c \
		game/moves.c \
		game/moves_utils.c \
		game/raycasting.c \
		error.c \

SRC_BONUS = 	main_bonus.c \
				parsing/parsing_bonus.c \
				parsing/parsing_utils_bonus.c \
				parsing/map_bonus.c \
				parsing/getmap_bonus.c \
				parsing/animation_bonus.c \
				game/game_bonus.c \
				game/game_utils_bonus.c \
				game/moves_bonus.c \
				game/moves_utils_bonus.c \
				game/raycasting_bonus.c \
				game/minimap_bonus.c \
				game/animation_bonus.c \
				game/print_wall_bonus.c \
				error_bonus.c \

SRCS = $(addprefix src/, $(SRC))
SRCS_BONUS = $(addprefix src_bonus/, $(SRC_BONUS))

DIR_OBJ = obj/
DIR_OBJ_BONUS = obj_bonus/

OBJ = $(addprefix $(DIR_OBJ), $(SRC:%.c=%.o))
OBJ_BONUS = $(addprefix $(DIR_OBJ_BONUS), $(SRC_BONUS:%.c=%.o))

$(DIR_OBJ)%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -I$(LIBFT_HEAD) -I MLX42 -o $@
$(DIR_OBJ_BONUS)%.o: src_bonus/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -I$(LIBFT_HEAD_BONUS) -I MLX42 -o $@

all: LIBFT MLX $(NAME)
bonus: LIBFT MLX $(NAME_BONUS)

LIBFT:
	$(MAKE) -C ./include/Libft

MLX:
	@if ls | grep -q "MLX42"; then \
		echo -n; \
	else \
		git clone https://github.com/codam-coding-college/MLX42.git; \
		cmake ./MLX42 -B ./MLX42/build; \
		make -C ./MLX42/build --no-print-directory -j4; \
		make --directory ./MLX42/build; \
	fi

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L ./include/Libft -lft $(LIBFT) $(INCLUD) $(MLXFLAGS) MLX42/build/libmlx42.a -o $(NAME)
$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -L ./include/Libft -lft $(LIBFT) $(INCLUD_BONUS) $(MLXFLAGS) MLX42/build/libmlx42.a -o $(NAME_BONUS)

end:
	rm -rf MLX42

clean:
		rm -rf $(DIR_OBJ)
		rm -rf $(DIR_OBJ_BONUS)
		$(MAKE) clean -C ./include/Libft
fclean:	clean
		rm -rf $(NAME)
		rm -rf $(NAME_BONUS)
		$(MAKE) fclean -C ./include/Libft
re:		fclean all

.PHONY: all clean fclean re LIBFT