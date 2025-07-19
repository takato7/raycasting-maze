/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:37:03 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/11 12:00:40 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	ft_init_mouse(t_cub3d *cub)
{
	t_mouse	*mouse;

	mouse = &cub->mouse;
	mouse->mlx = cub->mlx;
	mouse->win = cub->win;
	mouse->max_x = cub->win_x * 3 / 4;
	mouse->max_y = cub->win_y * 3 / 4;
	mouse->min_x = cub->win_x * 1 / 4;
	mouse->min_y = cub->win_y * 1 / 4;
	mouse->center_x = cub->win_x / 2;
	mouse->center_y = cub->win_y / 2;
	mouse->x_prev = mouse->center_x;
	mouse->max_diff = mouse->max_x - mouse->center_x;
	mouse->skip = 0;
	mouse->focus = 1;
	mouse->rot.dir_col = &cub->dir_col;
	mouse->rot.dir_row = &cub->dir_row;
	mouse->rot.plane_col = &cub->plane_col;
	mouse->rot.plane_row = &cub->plane_row;
	mlx_mouse_move(mouse->mlx, mouse->win, mouse->center_x, mouse->center_y);
	mlx_mouse_hide(mouse->mlx, mouse->win);
}
