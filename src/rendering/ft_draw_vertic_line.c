/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_vertic_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:03:10 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/10 15:39:41 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

static void	ft_calc_win_pos(t_draw *ln, double wall_dist, int win_y)
{
	ln->len_win = win_y;
	if (wall_dist < EPSILON)
		ln->len_tex = INT32_MAX;
	else
		ln->len_tex = (int)(ln->len_win / wall_dist);
	ln->begin = win_y / 2 - ln->len_tex / 2;
	if (ln->begin < 0)
		ln->begin = 0;
	ln->end = win_y / 2 + ln->len_tex / 2;
	if (ln->end > win_y)
		ln->end = win_y;
}

static void	ft_set_ceiling_pixel(char *dest, t_draw ln, t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (i < ln.begin)
	{
		*(unsigned int *)(dest + i * cub3d->fov.sl) = cub3d->c_color;
		i++;
	}
}

static void	ft_set_floor_pixel(char *dest, t_draw ln, t_cub3d *cub3d)
{
	int	i;

	i = ln.end;
	while (i < ln.len_win)
	{
		*(unsigned int *)(dest + i * cub3d->fov.sl) = cub3d->f_color;
		i++;
	}
}

static void	ft_set_color(char *dest, char *src)
{
	unsigned int	color;

	color = *((unsigned int *)src);
	*(unsigned int *)(dest) = color;
}

void	ft_draw_vertic_line(t_cub3d *cub3d, t_imgs img, int win_x, int tex_x)
{
	t_draw			ln;
	int				textr_y;
	char			*dest;
	char			*src;
	int				i;

	ft_calc_win_pos(&ln, cub3d->wall_dist, cub3d->win_y);
	dest = cub3d->fov.data + win_x * 4;
	ft_set_ceiling_pixel(dest, ln, cub3d);
	i = ln.begin;
	while (i < ln.end)
	{
		textr_y = (i - (ln.len_win / 2 - ln.len_tex / 2)) * img.x / ln.len_tex;
		src = img.data + tex_x * 4 + textr_y * img.sl;
		ft_set_color(dest + i * cub3d->fov.sl, src);
		i++;
	}
	ft_set_floor_pixel(dest, ln, cub3d);
}
