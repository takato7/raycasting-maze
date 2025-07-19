/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_fov_adjustment.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:36:50 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/11 12:09:05 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_action.h"

static int	ft_update_fov_settings(t_settings *di, double fov)
{
	di->show_info = 1;
	di->start_show = ft_getcurrenttime();
	if (!di->start_show)
		return (0);
	di->value = fov;
	return (1);
}

static void	ft_update_fov_factor(t_fov *fov, t_keys *keys)
{
	if (fov->can_adjust && keys->mult)
	{
		if (fov->fov_factor + FOV_FACTOR_STEPS > FOV_FACTOR_MAX)
			fov->fov_factor = FOV_FACTOR_MAX;
		else
			fov->fov_factor += FOV_FACTOR_STEPS;
	}
	if (fov->can_adjust && keys->div)
	{
		if (fov->fov_factor - FOV_FACTOR_STEPS < FOV_FACTOR_MIN)
			fov->fov_factor = FOV_FACTOR_MIN;
		else
			fov->fov_factor -= FOV_FACTOR_STEPS;
	}
	if (fov->can_adjust && keys->equal)
		fov->fov_factor = FOV_FACTOR;
}

int	ft_handle_fov_adjustment(t_cub3d *cub, t_fov *fov, t_keys *keys)
{
	ft_update_fov_factor(fov, keys);
	if (fov->can_adjust && (keys->mult || keys->div || keys->equal))
	{
		fov->can_adjust = 0;
		if (!ft_update_fov_settings(&fov->set, fov->fov_factor))
			return (0);
	}
	cub->plane_row = fov->fov_factor * cub->dir_col;
	cub->plane_col = -fov->fov_factor * cub->dir_row;
	if (!keys->mult && !keys->div && !keys->equal)
		fov->can_adjust = 1;
	return (1);
}
