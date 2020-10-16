# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/21 17:49:46 by ehafidi           #+#    #+#              #
#    Updated: 2020/10/15 17:54:41 by ehafidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LINUX = no

ifeq ($(LINUX),yes)
	MLX_ROOT = ./minilibx-linux
	FRAMEWORKS = -lXext -lX11 -lm
	LIBMLX = libmlx.a
	SRC = src/events/key_manager.c \
		src/events/player_movement.c \
		src/events/keyhandle_linux.c \
		src/events/free.c \
		src/raycaster/raycaster.c \
		src/raycaster/sprite_caster.c \
		src/raycaster/wall_caster_1.c \
		src/raycaster/wall_caster.c \
		src/parse/create_maps.c \
		src/parse/error_mngmnt.c \
		src/parse/flood_fill_alg.c \
		src/parse/get_infos_utils.c \
		src/parse/get_infos_utils_2.c \
		src/parse/get_infos.c \
		src/parse/init_and_checking.c \
		src/parse/parse_map_utils.c \
		src/parse/parse_map.c \
		src/parse/parsing.c \
		src/parse/verifying_functions_1.c \
		src/parse/verifying_functions_2.c \
		src/bitmap/bitmapy.c \
		src/main.c \
		src/mlx.c \
		src/spawn.c \

else 
	MLX_ROOT = ./minilibx_mms
	FRAMEWORKS = -framework OpenGL -framework AppKit
	LIBMLX = libmlx.dylib
	SRC = src/events/key_manager.c \
		src/events/player_movement.c \
		src/events/keyhandle_mac.c \
		src/events/free.c \
		src/raycaster/raycaster.c \
		src/raycaster/sprite_caster.c \
		src/raycaster/wall_caster_1.c \
		src/raycaster/wall_caster.c \
		src/parse/create_maps.c \
		src/parse/error_mngmnt.c \
		src/parse/flood_fill_alg.c \
		src/parse/get_infos_utils.c \
		src/parse/get_infos_utils_2.c \
		src/parse/get_infos.c \
		src/parse/init_and_checking.c \
		src/parse/parse_map_utils.c \
		src/parse/parse_map.c \
		src/parse/parsing.c \
		src/parse/verifying_functions_1.c \
		src/parse/verifying_functions_2.c \
		src/bitmap/bitmapy.c \
		src/main.c \
		src/mlx.c \
		src/spawn.c \

endif

LIBFT_ROOT = ./src/libft

OBJ = $(SRC:.c=.o)

CC = gcc 
CCFLAGS = -Wall -Wextra -Werror

MAKE = make

NAME = cub3d
RM = rm -rf

ifeq ($(LINUX),yes)
all	: mlx_all libft_all $(OBJ) $(NAME)

$(NAME):
	$(CC) $(CCFLAGS) -o $(NAME) $(OBJ) $(MLX_ROOT)/$(LIBMLX) $(FRAMEWORKS) -L$(LIBFT_ROOT) -lft

clean: libft_fclean mlx_clean
	$(RM) $(OBJ)
	$(RM) $(MLX_ROOT)/$(LIBMLX)	

else 
all	: mlx_move libft_all $(OBJ) $(NAME)

$(NAME):
	$(CC) $(CCFLAGS) -o $(NAME) $(OBJ) $(LIBMLX) $(FRAMEWORKS) -L$(LIBFT_ROOT) -lft 

clean: libft_fclean mlx_clean
	$(RM) $(OBJ)
	$(RM) $(LIBMLX)	

endif

%.o: %.c
		$(CC) $(CCFLAGS) -o $@ -c $<

fclean: clean bmp_clean
	$(RM) $(NAME)

bmp_clean:
	$(RM) firstpic.bmp

re: fclean all

libft_all:
	$(MAKE) -C $(LIBFT_ROOT) all

libft_clean:
	$(MAKE) -C $(LIBFT_ROOT) clean

libft_fclean:
	$(MAKE) -C $(LIBFT_ROOT) fclean		

mlx_move : mlx_all
	mv $(MLX_ROOT)/libmlx.dylib ./

mlx_all:
	$(MAKE) -C $(MLX_ROOT) all		

mlx_clean:
	$(MAKE) -C $(MLX_ROOT) clean	