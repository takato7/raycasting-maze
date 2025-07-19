/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_casting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:16:42 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/10 18:18:53 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"
#include "bonus.h"

static void	ft_set_ray_dir(t_ray *ray, t_cub3d *cub3d, int i)
{
	double	x_coordinate_on_camera;

	x_coordinate_on_camera = 2 * i / (double)(cub3d->win_x - 1) - 1;
	ray->dir_row = cub3d->dir_row + cub3d->plane_row * x_coordinate_on_camera;
	ray->dir_col = cub3d->dir_col + cub3d->plane_col * x_coordinate_on_camera;
}

static void	ft_calc_dist_for_dda(t_dist *dist, t_ray ray, t_cub3d *cub3d)
{
	int	map_row;
	int	map_col;

	if (fabs(ray.dir_row) < EPSILON)
		dist->delta_row = INFINITY;
	else
		dist->delta_row = fabs(1 / ray.dir_row);
	if (fabs(ray.dir_col) < EPSILON)
		dist->delta_col = INFINITY;
	else
		dist->delta_col = fabs(1 / ray.dir_col);
	map_row = (int)cub3d->pos_row;
	map_col = (int)cub3d->pos_col;
	if (ray.dir_row < 0)
		dist->side_row = (cub3d->pos_row - map_row) * dist->delta_row;
	else
		dist->side_row = (map_row + 1 - cub3d->pos_row) * dist->delta_row;
	if (ray.dir_col < 0)
		dist->side_col = (cub3d->pos_col - map_col) * dist->delta_col;
	else
		dist->side_col = (map_col + 1 - cub3d->pos_col) * dist->delta_col;
}

static void	ft_set_step_for_dda(t_dda *dda, t_ray ray)
{
	if (ray.dir_row < 0)
		dda->step_row = -1;
	else
		dda->step_row = 1;
	if (ray.dir_col < 0)
		dda->step_col = -1;
	else
		dda->step_col = 1;
}

static void	ft_digi_diff_analyze(t_dda *dda, t_dist dist, t_ray r, t_cub3d *c)
{
	dda->map_row = (int)c->pos_row;
	dda->map_col = (int)c->pos_col;
	dda->hit_type = 0;
	while (!dda->hit_type)
	{
		if (dist.side_row < dist.side_col)
		{
			dist.side_row += dist.delta_row;
			dda->map_row += dda->step_row;
			dda->side = ROW_SIDE;
		}
		else
		{
			dist.side_col += dist.delta_col;
			dda->map_col += dda->step_col;
			dda->side = COL_SIDE;
		}
		if (ft_wall_hit(dda, dist, r, c))
			dda->hit_type = C_WALL;
		if (ft_door_side_wall(dda, c))
			dda->hit_type = C_DOOR_SIDE;
		if (ft_door_hit(dda, dist, r, c))
			dda->hit_type = C_DOOR;
	}
}

void	ft_ray_casting(t_rcast *rc, t_cub3d *cub3d, int win_x)
{
	ft_set_ray_dir(&rc->ray, cub3d, win_x);
	ft_calc_dist_for_dda(&rc->dist, rc->ray, cub3d);
	ft_set_step_for_dda(&rc->dda, rc->ray);
	ft_digi_diff_analyze(&rc->dda, rc->dist, rc->ray, cub3d);
	ft_get_target_img(&rc->dda, rc->ray);
}
