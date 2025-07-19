/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_minimap_dimensions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:32:46 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/11 16:36:15 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static int	ft_set_minimap_cell_size(int win_w, int win_h)
{
	if (win_w <= 720 || win_h <= (720 * 3 / 4))
		return (CELL_SIZE_DEFAULT * 3 / 4);
	return (CELL_SIZE_DEFAULT);
}

static int	ft_set_minimap_player_border(int win_w, int win_h)
{
	if (win_w <= 720 || win_h <= (720 * 3 / 4))
		return (PLAYER_BORDER_DEFAULT - 1);
	return (PLAYER_BORDER_DEFAULT);
}

static int	ft_set_minimap_size(int win_w, int win_h, int cell_size)
{
	int	size;

	size = win_h;
	if (win_h > win_w)
		size = win_w;
	size /= 5;
	size -= (size % cell_size);
	if ((size / cell_size) % 2 == 0)
		size += cell_size;
	if (size > MM_MAX_SIZE)
		size = MM_MAX_SIZE - (MM_MAX_SIZE % cell_size) + cell_size;
	else if (size < MM_MIN_SIZE)
		size = MM_MIN_SIZE - (MM_MIN_SIZE % cell_size) + cell_size;
	return (size);
}

void	ft_set_minimap_dimensions(t_mmap *mmap, int win_w, int win_h)
{
	int	size;
	int	vis_dist;
	int	cell_size;
	int	player_border;

	cell_size = ft_set_minimap_cell_size(win_w, win_h);
	player_border = ft_set_minimap_player_border(win_w, win_h);
	size = ft_set_minimap_size(win_w, win_h, cell_size);
	vis_dist = (size / cell_size) / 2;
	mmap->height = size;
	mmap->width = size;
	mmap->vis_dist = vis_dist;
	mmap->cell_size = cell_size;
	mmap->player_border = player_border;
}
