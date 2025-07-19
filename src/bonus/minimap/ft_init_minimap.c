/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:48:04 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/15 15:31:28 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	ft_set_colors(t_mmap *mmap)
{
	mmap->cols.wall = ft_bgra(128, 128, 128, 0);
	mmap->cols.background = ft_bgra(64, 64, 64, 0);
	mmap->cols.floor = ft_bgra(0, 0, 100, 0);
	mmap->cols.player = ft_bgra(0, 100, 0, 0);
	mmap->cols.door_closed = ft_bgra(0, 120, 150, 0);
	mmap->cols.door_open = ft_bgra(0, 70, 100, 0);
	mmap->cols.squirrel = ft_bgra(19, 69, 139, 0);
}

static int	ft_init_image(t_cub3d *cub, t_mmap *mmap)
{
	mmap->img.img = mlx_new_image(mmap->mlx, mmap->width, mmap->height);
	if (!mmap->img.img)
		return (ft_error(EMLXNEWIMG, NULL));
	ft_set_img_addr(&mmap->img);
	mmap->mmap = mmap->img.data;
	mmap->img.x = cub->win_x / MM_POS;
	mmap->img.y = mmap->img.x;
	return (1);
}

int	ft_init_minimap(t_cub3d *cub)
{
	t_mmap	*mmap;

	mmap = &cub->mmap;
	mmap->map = cub->map;
	mmap->mlx = cub->mlx;
	mmap->win = cub->win;
	mmap->pos_x = &cub->pos_col;
	mmap->pos_y = &cub->pos_row;
	mmap->map_width = cub->map_data->width;
	mmap->map_height = cub->map_data->height;
	ft_set_minimap_dimensions(mmap, cub->win_x, cub->win_y);
	if (!ft_init_image(cub, mmap))
		return (0);
	ft_set_colors(mmap);
	mmap->can_toggle = 1;
	mmap->visible = 1;
	return (1);
}
