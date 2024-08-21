CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

DFLAGS = -MD -MP

LFLAGS = -L$(MLX_DIR) -lmlx -L$(LIBFT_DIR) -lft -L/usr/X11R6/lib -lXext -lX11 -lz -lm

INCLUDE_DIR = include

IFLAGS = \
		 -I $(INCLUDE_DIR) \
		 -I $(LIBFT_DIR)/$(INCLUDE_DIR) \
		 -I $(MLX_DIR)

GAME_LOOP_SRC = game_loop.c \
				keys.c \
				move_player.c \
				rotate_player.c

RENDER_SRC = render_frame.c \
			 find_closest_wall.c \
			 trace_column.c \
			 find_h_wall.c \
			 find_v_wall.c \
			 find_orientation.c \
			 draw_pixels.c \
			 find_closest_inter.c \
			 get_map_point.c \
			 get_pixel_color.c \

MLX_FUNCS_SRC = pixel_put.c \
			   window.c \
			   new_image.c

CHECK_MAP_SRC = pre_parsing.c

SRC = main.c \
	  normalize_angle.c \
	  $(addprefix render/, $(RENDER_SRC)) \
	  $(addprefix game_loop/, $(GAME_LOOP_SRC)) \
	  $(addprefix mlx_funcs/, $(MLX_FUNCS_SRC)) \
	  $(addprefix check_map/, $(CHECK_MAP_SRC))

BUILD_DIR = .build

OBJ = $(addprefix $(BUILD_DIR)/, $(SRC:.c=.o))

DEP = $(OBJ:.o=.d)

SRC_DIR = src

LIBS_DIR = libs

LIBFT_DIR = $(LIBS_DIR)/libft

LIBFT = libft.a

MLX_DIR = $(LIBS_DIR)/minilibx-linux

MLX = libmlx.a

NAME = cub3d

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
