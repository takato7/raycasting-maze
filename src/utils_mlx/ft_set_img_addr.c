/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_img_addr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:02:43 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/10 15:44:07 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_set_img_addr(t_imgs *imgs)
{
	int	bpp;
	int	sl;
	int	endian;

	imgs->data = mlx_get_data_addr(imgs->img, &bpp, &sl, &endian);
	imgs->bpp = bpp;
	imgs->sl = sl;
	imgs->endian = endian;
}
