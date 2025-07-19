/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_mouse_sens_adjustment.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:38:51 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/11 12:09:13 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_action.h"

static int	ft_update_sens_settings(t_settings *di, int sens)
{
	di->show_info = 1;
	di->start_show = ft_getcurrenttime();
	if (!di->start_show)
		return (0);
	di->value = (double)sens;
	return (1);
}

static void	ft_update_mouse_sens(t_rot *rot, t_keys *keys)
{
	if (rot->can_adjust && keys->plus)
	{
		if (rot->sens - MOUSE_SENS_STEPS > MOUSE_SENS_MIN)
			rot->sens -= MOUSE_SENS_STEPS;
		else
			rot->sens = MOUSE_SENS_MIN;
	}
	if (rot->can_adjust && keys->minus)
	{
		if (rot->sens + MOUSE_SENS_STEPS < MOUSE_SENS_MAX)
			rot->sens += MOUSE_SENS_STEPS;
		else
			rot->sens = MOUSE_SENS_MAX;
	}
	if (rot->can_adjust && keys->zero)
		rot->sens = MOUSE_SENS;
}

int	ft_handle_mouse_sens_adjustment(t_rot *rot, t_keys *keys)
{
	ft_update_mouse_sens(rot, keys);
	if (rot->can_adjust && (keys->plus || keys->minus || keys->zero))
	{
		rot->can_adjust = 0;
		if (!ft_update_sens_settings(&rot->set, rot->sens))
			return (0);
	}
	if (!keys->minus && !keys->plus && !keys->zero)
		rot->can_adjust = 1;
	return (1);
}
