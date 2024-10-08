CC = cc

CFLAGS = -Wall -Wextra -Werror -O3 -g3

DFLAGS = -MD -MP

LFLAGS = -L$(MLX_DIR) -lmlx -L$(LIBFT_DIR) -lft -L/usr/X11R6/lib -lXext -lX11 -lz -lm

INCLUDE_DIR = include

IFLAGS = \
		 -I $(INCLUDE_DIR) \
		 -I $(LIBFT_DIR)/$(INCLUDE_DIR) \
		 -I $(MLX_DIR)

GAME_LOOP_SRC = game_loop.c \
				images.c

INIT_SRC = init_main.c \
		   init_parsing.c

RENDER_SRC = render_frame.c \
			 find_closest_wall.c \
			 trace_column.c \
			 find_h_wall.c \
			 find_v_wall.c \
			 find_orientation.c \
			 find_closest_inter.c \
			 get_map_point.c \
			 normalize_angle.c

MLX_FUNCS_SRC = pixel_put.c \
			   window.c \
			   new_image.c \
			   display_image.c \
			   get_pixel_color.c \
			   free_img.c

TEXTURES_SRC = draw_column.c \
			   draw_pixel.c \
			   find_pos_tex_x.c

PLAYER_SRC = keys.c \
             move_player.c \
             rotate_player.c \
			 mouse_move.c \
			 player_size.c \
			 mouse_button.c

CHECK_MAP_SRC = pre_parsing.c \
				parsing_gnl.c \
				fill_path.c \
				fill_nsew_struct.c \
				convert_textures.c \
				convert_color.c \
				control_player_map.c \
				control_cub.c \
				check_if_textures_or_colors.c

MAP_SRC = draw_map.c \
		  draw_square.c \
		  draw_player.c

ASSETS_SRC = open_img.c \
			 open_img_obj.c \
			 open_xpm.c

DOORS_SRC = doors.c

SRC = main.c \
	  $(addprefix render/, $(RENDER_SRC)) \
	  $(addprefix game_loop/, $(GAME_LOOP_SRC)) \
	  $(addprefix mlx_funcs/, $(MLX_FUNCS_SRC)) \
	  $(addprefix check_map/, $(CHECK_MAP_SRC)) \
	  $(addprefix textures/, $(TEXTURES_SRC)) \
	  $(addprefix player/, $(PLAYER_SRC)) \
	  $(addprefix init/, $(INIT_SRC)) \
	  $(addprefix map/, $(MAP_SRC)) \
	  $(addprefix assets/, $(ASSETS_SRC)) \
	  $(addprefix doors/, $(DOORS_SRC))

BUILD_DIR = .build

OBJ = $(addprefix $(BUILD_DIR)/, $(SRC:.c=.o))

DEP = $(OBJ:.o=.d)

SRC_DIR = src

LIBS_DIR = libs

LIBFT_DIR = $(LIBS_DIR)/libft

LIBFT = libft.a

MLX_DIR = $(LIBS_DIR)/minilibx-linux

MLX = libmlx.a

NAME = cub3D

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_DIR)/$(LIBFT) $(MLX_DIR)/$(MLX)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LIBFT_DIR)/$(LIBFT) $(MLX_DIR)/$(MLX) $(LFLAGS)

-include $(DEP)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(LIBFT_DIR)/$(LIBFT) $(MLX_DIR)/$(MLX)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DFLAGS) $(IFLAGS) -c $< -o $@

$(LIBFT_DIR)/$(LIBFT): FORCE
	$(MAKE) -C $(LIBFT_DIR) $(LIBFT)

$(MLX_DIR)/$(MLX): FORCE
	$(MAKE) -C $(MLX_DIR) all

.PHONY: clean
clean:
	$(RM) -r $(BUILD_DIR)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MLX_DIR) clean

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: FORCE
FORCE:

.PHONY: re
re: fclean
	$(MAKE) all
