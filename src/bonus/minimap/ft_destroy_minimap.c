/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_minimap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 11:25:23 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/10 15:38:20 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	ft_destroy_minimap(t_mmap *mmap)
{
	mlx_destroy_image(mmap->mlx, mmap->img.img);
}
