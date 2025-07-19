/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_target_img.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 18:05:09 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/10 18:21:50 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

static void	ft_get_wall_img(t_dda *dda, t_ray ray)
{
	if (dda->side == ROW_SIDE)
	{
		if (ray.dir_row > 0)
			dda->img = NO;
		else
			dda->img = SO;
	}
	else
	{
		if (ray.dir_col > 0)
			dda->img = WE;
		else
			dda->img = EA;
	}
}

void	ft_get_target_img(t_dda *dda, t_ray ray)
{
	if (dda->hit_type == C_WALL)
		ft_get_wall_img(dda, ray);
	else if (dda->hit_type == C_DOOR)
		dda->img = DOOR;
	else if (dda->hit_type == C_DOOR_SIDE)
		dda->img = DOOR_SIDE;
}
