/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:05:02 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/15 13:51:46 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP_H
# define SETUP_H

# include "mlx.h"
# include "mlx_int.h"
# include "structs.h"
# include "macros.h"
# include "key_action.h"
# include "bonus.h"

void	ft_calc_speed(t_cub3d *cub3d);
char	*ft_get_path(int i, t_tex *tex);
int		ft_init_field_of_view(t_cub3d *cub3d);
int		ft_init_game_condition(t_cub3d *cub3d, t_file file);
int		ft_init_mlx_setup_win(t_cub3d *cub3d);
void	ft_init_player(t_cub3d *cub3d, char **map);
void	ft_init_settings(t_cub3d *cub);
int		ft_init_texture_imgs(t_cub3d *cub3d, t_tex *tex);
int		ft_rendering_loop(void *param);
int		ft_setup_cub3d(t_cub3d *cub3d, t_file file);
void	ft_setup_hooks(void *win, t_cub3d *cub, t_mouse *mouse, t_keys *keys);
void	ft_start_cub3d(t_cub3d *cub3d);

#endif
