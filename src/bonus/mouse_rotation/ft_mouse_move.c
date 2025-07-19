/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:06:40 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/10 15:25:59 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	ft_recenter_mouse(int x, int y, t_mouse *mouse)
{
	int	do_center;

	do_center = 0;
	if (x >= mouse->max_x || x <= mouse->min_x)
		do_center = 1;
	else if (y >= mouse->max_y || y <= mouse->min_y)
		do_center = 1;
	if (do_center)
	{
		mouse->skip = 1;
		mlx_mouse_move(mouse->mlx, mouse->win,
			mouse->center_x, mouse->center_y);
	}
}

static void	ft_vector_rotation(t_rot *rot, double diff)
{
	double	x;
	double	tmp;

	x = diff / rot->sens;
	tmp = *rot->dir_row;
	*rot->dir_row = *rot->dir_row * cos(x) - *rot->dir_col * sin(x);
	*rot->dir_col = tmp * sin(x) + *rot->dir_col * cos(x);
	tmp = *rot->plane_row;
	*rot->plane_row = *rot->plane_row * cos(x) - *rot->plane_col * sin(x);
	*rot->plane_col = tmp * sin(x) + *rot->plane_col * cos(x);
}

int	ft_mouse_move(int x, int y, void *param)
{
	t_mouse	*mouse;
	double	diff;

	mouse = (t_mouse *)param;
	if (!mouse->focus)
		return (1);
	if (mouse->skip)
	{
		mouse->x_prev = x;
		mouse->skip = 0;
		return (1);
	}
	diff = 0;
	if (x > mouse->x_prev)
		diff = (double)(x - mouse->x_prev);
	else if (x < mouse->x_prev)
		diff = (double)((mouse->x_prev - x) * -1);
	if (fabs(diff) < mouse->max_diff)
		ft_vector_rotation(&mouse->rot, -diff);
	ft_recenter_mouse(x, y, mouse);
	mouse->x_prev = x;
	return (1);
}
