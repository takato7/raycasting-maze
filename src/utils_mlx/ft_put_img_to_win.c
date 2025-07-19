/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_img_to_win.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:18:47 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/10 15:44:01 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_put_img_to_win(void *img, t_cub3d *cub3d)
{
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, img, 0, 0);
}
