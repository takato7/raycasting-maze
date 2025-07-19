/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 11:47:37 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/15 16:21:31 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# include <stdint.h>
# include <math.h>
# include "structs.h"
# include "macros.h"
# include "utils.h"

void	ft_update_field_of_view(t_cub3d *cub3d);
void	ft_draw_vertic_line(t_cub3d *cub3d, t_imgs img, int win_x, int tex_x);
void	ft_get_target_img(t_dda *dda, t_ray ray);
void	ft_ray_casting(t_rcast *rc, t_cub3d *cub3d, int x);
void	ft_set_wall_dist(t_cub3d *cub3d, double wall_dist, int win_x);
int		ft_show_sens_settings(t_settings *set, void *mlx, void *win);
int		ft_show_fov_settings(t_settings *set, void *mlx, void *win);
void	ft_show_fps(t_fps_counter *fps_counter, void *mlx, void *win);
int		ft_wall_hit(t_dda *dda, t_dist dist, t_ray ray, t_cub3d *cub3d);

#endif
