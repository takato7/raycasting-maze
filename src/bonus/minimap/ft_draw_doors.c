/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_doors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:42:24 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/10 16:22:44 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	ft_draw_door_hor(int line, int i, int color, t_mmap *mmap)
{
	char	*curr_img_data;
	int		*pxl_start;
	int		i_start;
	int		x;
	int		y;

	i_start = i;
	y = mmap->player_border;
	line += mmap->player_border;
	while (y < mmap->cell_size - mmap->player_border)
	{
		curr_img_data = &mmap->img.data[(line * mmap->img.sl)];
		i = i_start;
		x = 0;
		while (x < mmap->cell_size)
		{
			pxl_start = (int *)(curr_img_data + i);
			*pxl_start = color;
			i += mmap->img.bpp / 8;
			x++;
		}
		y++;
		line++;
	}
}

void	ft_draw_door_ver(int line, int i, int color, t_mmap *mmap)
{
	char	*curr_img_data;
	int		*pxl_start;
	int		i_start;
	int		x;
	int		y;

	i_start = i + (mmap->player_border * (mmap->img.bpp / 8));
	y = 0;
	while (y < mmap->cell_size)
	{
		curr_img_data = &mmap->img.data[(line * mmap->img.sl)];
		i = i_start;
		x = mmap->player_border;
		while (x < mmap->cell_size - mmap->player_border)
		{
			pxl_start = (int *)(curr_img_data + i);
			*pxl_start = color;
			i += mmap->img.bpp / 8;
			x++;
		}
		y++;
		line++;
	}
}
