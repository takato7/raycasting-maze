/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:35:20 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/11 17:48:37 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include <math.h>
# include <stdint.h>
# include "mlx.h"
# include "utils.h"
# include "macros.h"
# include "structs.h"

void	ft_init_checker(t_collision *check, double row, double col, t_cub3d *c);
int		ft_wall_collision(t_cub3d *c, double add_row, double add_col);
int		ft_init_minimap(t_cub3d *cub);
void	ft_draw_minimap(t_mmap *mmap);
int		ft_get_cell_id(int line, int i, t_mmap *mmap);
void	ft_add_objects(t_mmap *mmap);
void	ft_destroy_minimap(t_mmap *mmap);
void	ft_set_minimap_dimensions(t_mmap *mmap, int win_w, int win_h);
void	ft_draw_door_hor(int line, int i, int color, t_mmap *mmap);
void	ft_draw_door_ver(int line, int i, int color, t_mmap *mmap);
int		ft_mouse_move(int x, int y, void *param);
void	ft_init_mouse(t_cub3d *cub);
int		ft_focus_out(void *param);
int		ft_focus_in(void *param);
int		ft_init_sprite(t_cub3d *cub3d);
void	ft_sort_sprite(t_sprite *sprite, size_t num);
void	ft_draw_sprite(t_sprite sprite, t_cub3d *cub3d);
void	ft_sprite_casting(t_cub3d *cub3d, t_sprite *sprite);
int		ft_sprite_animation(t_cub3d *cub3d);
void	ft_destroy_sprite(t_cub3d *cub3d);
int		ft_init_doors(t_cub3d *cub3d, t_map map);
void	ft_destroy_doors(t_cub3d *cub3d);
int		ft_door_hit(t_dda *dda, t_dist dist, t_ray ray, t_cub3d *cub3d);
int		ft_door_side_wall(t_dda *dda, t_cub3d *cub3d);
void	ft_door_action(t_cub3d *cub3d, t_keys *keys);
void	ft_door_positioning(t_cub3d *cub3d);

#endif
