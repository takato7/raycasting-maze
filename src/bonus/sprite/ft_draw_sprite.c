/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:51:44 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/10 15:26:56 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static int	ft_out_of_win_y(t_sprite s, double wall_dist)
{
	if (s.y_on_camera < EPSILON || s.y_on_camera - wall_dist > EPSILON)
		return (1);
	return (0);
}

static void	ft_set_sprite_color(char *dest, char *src)
{
	unsigned int	color;

	color = *((unsigned int *)(src));
	if (color == 3288131)
		return ;
	*(unsigned int *)(dest) = color;
}

static void	ft_set_sprite_pixel(t_sprite s, t_cub3d *c, int i, int j)
{
	t_imgs	img;
	int		tex_x;
	int		tex_y;
	char	*src;
	char	*dest;

	img = c->imgs[s.id];
	tex_x = (i - (-s.width / 2 + s.x_on_win)) * img.x / s.width;
	tex_y = (j - s.y_on_win - (-s.hight / 2 + c->win_y / 2)) * img.y / s.hight;
	src = img.data + tex_x * 4 + tex_y * img.sl;
	dest = c->fov.data + i * 4 + j * c->fov.sl;
	ft_set_sprite_color(dest, src);
}

static void	ft_set_draw_range(t_draw *x, t_draw *y, t_sprite s, t_cub3d *c)
{
	y->begin = -s.hight / 2 + c->win_y / 2 + s.y_on_win;
	if (y->begin < 0)
		y->begin = 0;
	y->end = s.hight / 2 + c->win_y / 2 + s.y_on_win;
	if (y->end > c->win_y)
		y->end = c->win_y;
	x->begin = -s.width / 2 + s.x_on_win;
	if (x->begin < 0)
		x->begin = 0;
	x->end = s.width / 2 + s.x_on_win;
	if (x->end > c->win_x)
		x->end = c->win_x;
}

void	ft_draw_sprite(t_sprite sprite, t_cub3d *cub3d)
{
	t_draw	x;
	t_draw	y;
	int		i;
	int		j;

	ft_set_draw_range(&x, &y, sprite, cub3d);
	i = x.begin;
	while (i < x.end)
	{
		if (!ft_out_of_win_y(sprite, cub3d->wall_dists[i]))
		{
			j = y.begin;
			while (j < y.end)
			{
				ft_set_sprite_pixel(sprite, cub3d, i, j);
				j++;
			}
		}
		i++;
	}
}
