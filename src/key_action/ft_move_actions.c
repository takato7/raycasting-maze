/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:33:25 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/11 17:56:37 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_action.h"
#include "bonus.h"

static void	ft_valid_move(t_cub3d *c, double add_row, double add_col)
{
	if (ft_wall_collision(c, add_row, add_col))
		return ;
	c->pos_row += add_row;
	c->pos_col += add_col;
}

static void	ft_action_move(int key, t_cub3d *c)
{
	double	add_row;
	double	add_col;

	if (key == XK_w)
	{
		add_row = c->dir_row * c->move_speed;
		add_col = c->dir_col * c->move_speed;
	}
	else if (key == XK_s)
	{
		add_row = -c->dir_row * c->move_speed;
		add_col = -c->dir_col * c->move_speed;
	}
	else if (key == XK_d)
	{
		add_row = c->plane_row * c->move_speed;
		add_col = c->plane_col * c->move_speed;
	}
	else
	{
		add_row = -c->plane_row * c->move_speed;
		add_col = -c->plane_col * c->move_speed;
	}
	ft_valid_move(c, add_row, 0.0);
	ft_valid_move(c, 0.0, add_col);
}

void	ft_move_actions(t_cub3d *cub3d, t_keys *keys)
{
	if (keys->w)
		ft_action_move(XK_w, cub3d);
	if (keys->a)
		ft_action_move(XK_a, cub3d);
	if (keys->s)
		ft_action_move(XK_s, cub3d);
	if (keys->d)
		ft_action_move(XK_d, cub3d);
}
