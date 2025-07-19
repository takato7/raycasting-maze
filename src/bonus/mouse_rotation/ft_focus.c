/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_focus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:39:14 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/10 15:25:51 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	ft_focus_out(void *param)
{
	t_mouse	*mouse;

	mouse = (t_mouse *)param;
	mlx_mouse_show(mouse->mlx, mouse->win);
	mouse->focus = 0;
	return (1);
}

int	ft_focus_in(void *param)
{
	t_mouse	*mouse;

	mouse = (t_mouse *)param;
	mlx_mouse_hide(mouse->mlx, mouse->win);
	mlx_mouse_move(mouse->mlx, mouse->win, mouse->center_x, mouse->center_y);
	mouse->x_prev = mouse->center_x;
	mouse->focus = 1;
	return (1);
}
