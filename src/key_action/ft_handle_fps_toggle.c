/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_fps_toggle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:39:44 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/15 10:35:24 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_action.h"

void	ft_handle_fps_toggle(t_fps_counter *fps_counter, t_keys *keys)
{
	if (fps_counter->can_toggle && keys->f)
	{
		fps_counter->visible = !fps_counter->visible;
		fps_counter->can_toggle = 0;
	}
	if (!keys->f)
		fps_counter->can_toggle = 1;
}
