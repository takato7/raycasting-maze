/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:17:35 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/15 16:20:36 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"

static void	ft_init_sens(t_mouse *mouse, t_mmap *mmap)
{
	mouse->rot.set = (t_settings){0};
	mouse->rot.can_adjust = 1;
	mouse->rot.sens = MOUSE_SENS;
	mouse->rot.set.set_x = mmap->img.x + 5;
	mouse->rot.set.set_y = mmap->img.y + mmap->height + 20;
}

static void	ft_init_fov(t_fov *fov_data, t_mmap *mmap)
{
	fov_data->set = (t_settings){0};
	fov_data->can_adjust = 1;
	fov_data->fov_factor = FOV_FACTOR;
	fov_data->set.set_x = mmap->img.x + 5;
	fov_data->set.set_y = mmap->img.y + mmap->height + 40;
}

static void	ft_init_fps_counter(t_fps_counter *fps_c, t_cub3d *cub, void *ft)
{
	fps_c->can_toggle = 1;
	fps_c->visible = 0;
	fps_c->frame_time = ft;
	fps_c->x = cub->win_x - 60;
	fps_c->y = 30;
}

void	ft_init_settings(t_cub3d *cub)
{
	ft_init_sens(&cub->mouse, &cub->mmap);
	ft_init_fov(&cub->fov_data, &cub->mmap);
	ft_init_fps_counter(&cub->fps_counter, cub, &cub->frame_time);
}
