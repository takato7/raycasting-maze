/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_casting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:14:42 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/10 15:27:18 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	ft_calc_pos_on_camera(t_sprite *s, t_cub3d *c)
{
	double	row;
	double	col;
	double	delta;
	double	inv_del;

	row = s->pos_row - c->pos_row;
	col = s->pos_col - c->pos_col;
	delta = c->plane_row * c->dir_col - c->dir_row * c->plane_col;
	if (fabs(delta) < EPSILON)
		inv_del = INFINITY;
	else
		inv_del = 1.0 / delta;
	s->x_on_camera = inv_del * (c->dir_col * row - c->dir_row * col);
	s->y_on_camera = inv_del * (-c->plane_col * row + c->plane_row * col);
	s->x_on_win = (int)((c->win_x / 2) * (1 + s->x_on_camera / s->y_on_camera));
	s->dist = s->x_on_camera * s->x_on_camera + s->y_on_camera * s->y_on_camera;
}

static void	ft_calc_size_on_win(t_sprite *s, int win_y)
{
	int	hight;

	hight = 0;
	if (fabs(s->y_on_camera) > EPSILON)
	{
		hight = (int)fabs(win_y / s->y_on_camera);
		s->hight = hight / SP_SIZE_DOWN;
		s->width = s->hight;
		s->y_on_win = (1.0 - 1.0 / SP_SIZE_DOWN) * hight;
	}
	else
	{
		s->hight = INT32_MAX;
		s->width = INT32_MAX;
	}
}

static int	ft_out_of_win_x(t_sprite s, int win_x)
{
	if (s.x_on_win + s.width / 2 < 0 || s.x_on_win - s.width / 2 > win_x)
		return (1);
	return (0);
}

void	ft_sprite_casting(t_cub3d *cub3d, t_sprite *sprite)
{
	size_t	i;

	i = 0;
	while (i < cub3d->num_sprite)
	{
		ft_calc_pos_on_camera(&sprite[i], cub3d);
		ft_calc_size_on_win(&sprite[i], cub3d->win_y);
		i++;
	}
	ft_sort_sprite(sprite, cub3d->num_sprite);
	i = 0;
	while (i < cub3d->num_sprite)
	{
		if (!ft_out_of_win_x(sprite[i], cub3d->win_x))
			ft_draw_sprite(sprite[i], cub3d);
		i++;
	}
}
