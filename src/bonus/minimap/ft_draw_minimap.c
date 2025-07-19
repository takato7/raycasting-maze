/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:33:50 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/10 15:25:26 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	ft_fill_line(int y, t_mmap *mmap)
{
	int		i;
	int		color;
	int		*pxl_start;
	char	*curr_img_data;
	int		cell_id;

	curr_img_data = &mmap->mmap[y * mmap->img.sl];
	i = 0;
	while (i < mmap->img.sl)
	{
		cell_id = ft_get_cell_id(y, i, mmap);
		if (cell_id == WALL_CELL)
			color = mmap->cols.wall;
		else if (cell_id == BACKGROUND_CELL)
			color = mmap->cols.background;
		else
			color = mmap->cols.floor;
		pxl_start = (int *)(curr_img_data + i);
		*pxl_start = color;
		i += mmap->img.bpp / 8;
	}
}

static void	ft_fill_image_buffer(t_mmap *mmap)
{
	int		y;

	y = 0;
	while (y < mmap->height)
	{
		ft_fill_line(y, mmap);
		y++;
	}
}

void	ft_draw_minimap(t_mmap *mmap)
{
	static t_imgs	*img;
	static void		*mlx;
	static void		*win;

	img = &mmap->img;
	mlx = mmap->mlx;
	win = mmap->win;
	ft_fill_image_buffer(mmap);
	ft_add_objects(mmap);
	mlx_put_image_to_window(mlx, win, img->img, img->x, img->y);
}
