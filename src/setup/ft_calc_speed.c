/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_frame_time.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:39:09 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/15 13:51:19 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"

void	ft_calc_speed(t_cub3d *cub3d)
{
	cub3d->move_speed = DIST_PER_SECOND * cub3d->frame_time;
	cub3d->rot_speed = RADIAN_PER_SECOND * cub3d->frame_time;
}
