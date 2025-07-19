/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_field_of_view.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:02:43 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/10 15:40:50 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

static int	ft_get_texture_x(t_dda dda, t_ray ray, int tex_size)
{
	int	texture_x;

	texture_x = (int)(dda.hit_x * tex_size);
	if (dda.hit_type == C_WALL)
	{
		if (dda.side == ROW_SIDE && ray.dir_row > 0)
			texture_x = tex_size - texture_x - 1;
		else if (dda.side == COL_SIDE && ray.dir_col < 0)
			texture_x = tex_size - texture_x - 1;
	}
	return (texture_x);
}

void	ft_update_field_of_view(t_cub3d *cub3d)
{
	int		win_x;
	t_rcast	rc;
	t_imgs	target;
	int		tex_x;

	win_x = 0;
	while (win_x < cub3d->win_x)
	{
		ft_ray_casting(&rc, cub3d, win_x);
		ft_set_wall_dist(cub3d, rc.dda.wall_dist, win_x);
		target = cub3d->imgs[rc.dda.img];
		tex_x = ft_get_texture_x(rc.dda, rc.ray, target.x);
		ft_draw_vertic_line(cub3d, target, win_x, tex_x);
		win_x++;
	}
}
