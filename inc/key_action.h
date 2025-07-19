/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_action.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:12:23 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/15 16:21:40 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_ACTION_H
# define KEY_ACTION_H

# include <math.h>
# include "mlx.h"
# include "mlx_int.h"
# include "structs.h"
# include "macros.h"
# include "utils.h"

void	ft_key_action(t_cub3d *cub3d, t_keys *keys);
int		ft_key_press(int key, void *param);
int		ft_key_release(int key, void *param);
void	ft_move_actions(t_cub3d *cub3d, t_keys *keys);
void	ft_rotate_actions(t_cub3d *cub3d, t_keys *keys);
void	ft_vector_rotation(t_cub3d *cub3d, double x);
int		ft_handle_fov_adjustment(t_cub3d *cub, t_fov *fov, t_keys *keys);
int		ft_handle_mouse_sens_adjustment(t_rot *rot, t_keys *keys);
void	ft_handle_minimap_toggle(t_mmap *mmap, t_keys *keys);
void	ft_handle_fps_toggle(t_fps_counter *fps_counter, t_keys *keys);

#endif
