/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_cub3d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:46:46 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/10 15:47:23 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleanup.h"
#include "bonus.h"

static void	ft_destroy_texture_imgs(t_cub3d *cub3d)
{
	int	i;

	if (!cub3d->imgs)
		return ;
	i = 0;
	while (i < MAX_IMAGE)
	{
		if (cub3d->imgs[i].img)
			mlx_destroy_image(cub3d->mlx, cub3d->imgs[i].img);
		i++;
	}
	free(cub3d->imgs);
}

static void	ft_destroy_fov(t_cub3d *cub3d)
{
	if (cub3d->fov.img)
		mlx_destroy_image(cub3d->mlx, cub3d->fov.img);
}

static void	ft_destroy_win(t_cub3d *cub3d)
{
	if (cub3d->win)
		mlx_destroy_window(cub3d->mlx, cub3d->win);
}

static void	ft_destroy_mlx(t_cub3d *cub3d)
{
	if (!cub3d->mlx)
		return ;
	mlx_destroy_display(cub3d->mlx);
	free(cub3d->mlx);
}

void	ft_destroy_cub3d(t_cub3d *cub3d)
{
	ft_destroy_texture_imgs(cub3d);
	ft_destroy_minimap(&cub3d->mmap);
	ft_destroy_fov(cub3d);
	ft_destroy_sprite(cub3d);
	ft_destroy_doors(cub3d);
	ft_destroy_win(cub3d);
	ft_destroy_mlx(cub3d);
}
