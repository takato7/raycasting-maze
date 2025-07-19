/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 17:36:57 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/11 17:48:26 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static int	ft_get_next_map_pos(double curr_pos, double dir)
{
	if (fabs(dir) < EPSILON)
		return ((int)curr_pos);
	if (dir > 0)
		return ((int)curr_pos + 1);
	else
		return ((int)curr_pos - 1);
}

void	ft_init_checker(t_collision *check, double row, double col, t_cub3d *c)
{
	check->add_row = row;
	check->add_col = col;
	check->pos_row = c->pos_row + row;
	check->pos_col = c->pos_col + col;
	check->nexmap_row = ft_get_next_map_pos(c->pos_row, row);
	check->nexmap_col = ft_get_next_map_pos(c->pos_col, col);
	if (fabs(row) < EPSILON)
		check->side_row = 1;
	else
		check->side_row = 0;
	if (fabs(col) < EPSILON)
		check->side_col = 1;
	else
		check->side_col = 0;
}
