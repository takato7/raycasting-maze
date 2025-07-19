/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_texture_imgs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:29:29 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/15 15:32:11 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"

static void	ft_loading_texture(void *mlx, t_imgs *imgs, int i, char *path)
{
	if (!path)
		imgs[i].img = NULL;
	else
	{
		imgs[i].img = mlx_xpm_file_to_image(mlx, path, &imgs[i].x, &imgs[i].y);
		if (imgs[i].img)
			ft_set_img_addr(&imgs[i]);
	}
}

static int	ft_is_loading_success(t_imgs *imgs)
{
	int	i;

	i = 0;
	while (i < MAX_IMAGE)
	{
		if (!imgs[i].img)
			return (0);
		i++;
	}
	return (1);
}

int	ft_init_texture_imgs(t_cub3d *cub3d, t_tex *tex)
{
	int	i;

	cub3d->imgs = (t_imgs *)malloc(sizeof(t_imgs) * (MAX_IMAGE + 1));
	if (!cub3d->imgs)
		return (ft_error(EMALLOC, NULL));
	i = 0;
	while (i < MAX_IMAGE)
	{
		ft_loading_texture(cub3d->mlx, cub3d->imgs, i, ft_get_path(i, tex));
		i++;
	}
	cub3d->imgs[MAX_IMAGE].img = NULL;
	if (!ft_is_loading_success(cub3d->imgs))
		return (ft_error(EMLXLOADTEX, NULL));
	return (1);
}
