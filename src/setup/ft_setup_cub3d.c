/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup_cub3d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:27:43 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/15 13:50:17 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"
#include "rendering.h"

int	ft_setup_cub3d(t_cub3d *cub3d, t_file file)
{
	if (!ft_init_mlx_setup_win(cub3d))
		return (0);
	if (!ft_init_minimap(cub3d))
		return (0);
	if (!ft_init_texture_imgs(cub3d, file.tex))
		return (0);
	if (!ft_init_field_of_view(cub3d))
		return (0);
	if (!ft_init_game_condition(cub3d, file))
		return (0);
	if (!ft_init_sprite(cub3d))
		return (0);
	if (!ft_init_doors(cub3d, file.map))
		return (0);
	ft_init_mouse(cub3d);
	ft_init_settings(cub3d);
	ft_setup_hooks(cub3d->win, cub3d, &cub3d->mouse, &cub3d->keys);
	return (1);
}
