# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/16 12:34:50 by dlippelt          #+#    #+#              #
#    Updated: 2025/07/16 12:12:36 by dlippelt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		cub3D

CC =		cc
RM =		rm -rf
VALG =		valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes

CFLAGS =	-Wall -Werror -Wextra -g3
IFLAGS =	-I$(INCDIR) -I$(MLXDIR)
OUTPUT =	-o
EXLIBS =	-L$(MLXDIR) -lmlx -lXext -lX11 -lm -lXfixes

MLXDIR =	./mlx
SRCDIR =	./src
INCDIR =	./inc
OBJDIR =	./obj

MLXLIB =	$(MLXDIR)/libmlx.a
MLXMAKE =	make -C $(MLXDIR)

SRCS =		bonus/doors/ft_destroy_doors.c \
			bonus/doors/ft_door_action.c \
			bonus/doors/ft_door_hit.c \
			bonus/doors/ft_door_positioning.c \
			bonus/doors/ft_door_side_wall.c \
			bonus/doors/ft_init_doors.c \
			bonus/minimap/ft_add_objects.c \
			bonus/minimap/ft_destroy_minimap.c \
			bonus/minimap/ft_draw_doors.c \
			bonus/minimap/ft_draw_minimap.c \
			bonus/minimap/ft_get_cell_id.c \
			bonus/minimap/ft_init_minimap.c \
			bonus/minimap/ft_set_minimap_dimensions.c \
			bonus/mouse_rotation/ft_focus.c \
			bonus/mouse_rotation/ft_init_mouse.c \
			bonus/mouse_rotation/ft_mouse_move.c \
			bonus/sprite/ft_destroy_sprite.c \
			bonus/sprite/ft_draw_sprite.c \
			bonus/sprite/ft_init_sprite.c \
			bonus/sprite/ft_sort_sprite.c \
			bonus/sprite/ft_sprite_animation.c \
			bonus/sprite/ft_sprite_casting.c \
			bonus/wall_collision/ft_init_checker.c \
			bonus/wall_collision/ft_wall_collision.c \
			cleanup/ft_cleanup_file.c \
			cleanup/ft_destroy_cub3d.c \
			init/ft_init_cub3d.c \
			init/ft_init_file.c \
			key_action/ft_handle_fov_adjustment.c \
			key_action/ft_handle_fps_toggle.c \
			key_action/ft_handle_minimap_toggle.c \
			key_action/ft_handle_mouse_sens_adjustment.c \
			key_action/ft_key_action.c \
			key_action/ft_key_press.c \
			key_action/ft_key_release.c \
			key_action/ft_move_actions.c \
			key_action/ft_rotate_actions.c \
			key_action/ft_vector_rotation.c \
			main.c \
			rendering/ft_draw_vertic_line.c \
			rendering/ft_get_target_img.c \
			rendering/ft_ray_casting.c \
			rendering/ft_set_wall_dist.c \
			rendering/ft_show_fov_settings.c \
			rendering/ft_show_fps_settings.c \
			rendering/ft_show_sens_settings.c \
			rendering/ft_update_field_of_view.c \
			rendering/ft_wall_hit.c \
			setup/ft_calc_speed.c \
			setup/ft_get_path.c \
			setup/ft_init_field_of_view.c \
			setup/ft_init_game_condition.c \
			setup/ft_init_mlx_setup_win.c \
			setup/ft_init_player.c \
			setup/ft_init_settings.c \
			setup/ft_init_texture_imgs.c \
			setup/ft_rendering_loop.c \
			setup/ft_setup_cub3d.c \
			setup/ft_setup_hooks.c \
			setup/ft_start_cub3d.c \
			utils/ft_bgra.c \
			utils/ft_colortoi.c \
			utils/ft_error.c \
			utils/ft_found_player.c \
			utils/ft_get_time_diff_sec.c \
			utils/ft_getcurrenttime.c \
			utils/ft_is_printable.c \
			utils/ft_itoa.c \
			utils/ft_open.c \
			utils/ft_putstr.c \
			utils/ft_strcmp.c \
			utils/ft_strlcpy.c \
			utils/ft_strlen.c \
			utils/ft_strncmp.c \
			utils/get_next_line.c \
			utils/get_next_line_utils.c \
			utils_mlx/ft_put_img_to_win.c \
			utils_mlx/ft_set_img_addr.c \
			utils_mlx/ft_setup_loop_hook.c \
			validation/ft_copy_map_with_border.c \
			validation/ft_found_map.c \
			validation/ft_get_element_info.c \
			validation/ft_get_elements.c \
			validation/ft_get_map.c \
			validation/ft_get_map_utils.c \
			validation/ft_move_index.c \
			validation/ft_new_col.c \
			validation/ft_new_tex.c \
			validation/ft_validate_color_info.c \
			validation/ft_validate_doors.c \
			validation/ft_validate_elements.c \
			validation/ft_validate_file.c \
			validation/ft_validate_file_content.c \
			validation/ft_validate_map.c \
			validation/ft_validate_playable_area.c \
			validation/ft_validate_player.c \
			validation/ft_validate_texture_info.c \
			validation/ft_validate_wall.c


HDRS =		bonus.h \
			cleanup.h \
			cub3D.h \
			enums.h \
			get_next_line.h \
			init.h \
			key_action.h \
			macros.h \
			rendering.h \
			setup.h \
			structs.h \
			utils.h \
			validation.h


OBJS =		$(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

OBJDIRS =	$(sort $(dir $(OBJS)))

all: $(NAME)

$(OBJDIRS):
	mkdir -p $@

$(NAME): $(MLXLIB) $(OBJDIRS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(EXLIBS) $(OUTPUT) $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(addprefix $(INCDIR)/, $(HDRS))
	$(CC) $(CFLAGS) $(IFLAGS) -c $< $(OUTPUT) $@

$(MLXLIB):
	$(MLXMAKE)

clean:
	$(RM) $(OBJDIR)
	$(RM) *.xml
	$(MLXMAKE) clean

fclean: clean
	$(RM) $(NAME)

re: fclean all

valgrind: $(NAME)
	$(VALG) ./$(NAME) $(ARGS)

memory: CFLAGS += -fsanitize=address
memory: re

.PHONY: all clean fclean re valgrind memory
