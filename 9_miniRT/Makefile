NAME = miniRT 
SRC =	main.c\
		get_next_line.c get_next_line_utils.c error.c\
		mlx_init_n_hooking.c mlx_put_image.c\
		vector.c vector_cal.c vector_scalar_cal.c vector_compare.c\
		parse.c parse_number.c parse_string.c parse_check.c\
		parse_lights_n_camera.c parse_objects.c parse_bumpmap.c\
		init_objs_axis.c\
		render_viewport.c\
		ray_tracing.c draw_phong_lighting.c draw_shadow.c draw_pattern.c check_invalid_angle.c\
		object_sphere.c object_plane.c object_cylinder.c object_cone.c objects_utils.c
SRC_OBJ = $(SRC:.c=.o)
HEADER = get_next_line.h error.h ray_trace.h vector.h minirt_types.h mlx_info.h parse.h

BONUS_DIR = 
BONUS_HEADER = get_next_line_bonus.h error_bonus.h ray_trace_bonus.h vector_bonus.h minirt_types_bonus.h mlx_info_bonus.h parse_bonus.h
BONUS_HEADER := $(addprefix $(BONUS_DIR),$(BONUS_HEADER))
BONUS_SRC = main_bonus.c\
			get_next_line_bonus.c get_next_line_utils_bonus.c error_bonus.c\
			mlx_init_n_hooking_bonus.c mlx_put_image_bonus.c\
			vector_bonus.c vector_cal_bonus.c vector_scalar_cal_bonus.c vector_compare_bonus.c\
			parse_bonus.c parse_number_bonus.c parse_string_bonus.c parse_check_bonus.c\
			parse_lights_n_camera_bonus.c parse_objects_bonus.c parse_bumpmap_bonus.c\
			init_objs_axis_bonus.c\
			render_viewport_bonus.c\
			ray_tracing_bonus.c draw_phong_lighting_bonus.c draw_shadow_bonus.c draw_pattern_bonus.c check_invalid_angle_bonus.c\
			object_sphere_bonus.c object_plane_bonus.c object_cylinder_bonus.c object_cone_bonus.c objects_utils_bonus.c
BONUS_SRC := $(addprefix $(BONUS_DIR),$(BONUS_SRC))
BONUS_OBJ = $(BONUS_SRC:.c=.o)
CFLAGS =	-Wall -Werror -Wextra -L$(LIBFT_DIR) -lft -lm -Imlx -lmlx\
			-framework AppKit -framework OpenGL
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

all: $(NAME)

$(NAME): $(SRC) $(LIBFT) $(HEADER)
	cc $(CFLAGS) -o $@ $(SRC) -I$(LIBFT_DIR)

bonus: $(BONUS_SRC) $(LIBFT) $(BONUS_HEADER)
	cc $(CFLAGS) -o $(NAME) $(BONUS_SRC) -I$(LIBFT_DIR)
	touch $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(SRC_OBJ) $(BONUS_OBJ)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	rm -rf debug*
	rm -f bonus

re:
	make fclean
	make all

debug: $(SRC) $(LIBFT) $(MLX)
	gcc -g $(CFLAGS) -o debug $(SRC) -I$(LIBFT_DIR)

.PHONY: all clean fclean re
