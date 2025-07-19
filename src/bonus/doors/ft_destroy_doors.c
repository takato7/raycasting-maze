/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_doors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:36:04 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/10 15:24:51 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	ft_destroy_doors(t_cub3d *cub3d)
{
	size_t	i;

	if (cub3d->doors)
	{
		i = 0;
		while (cub3d->doors[i])
		{
			free(cub3d->doors[i]);
			i++;
		}
		free(cub3d->doors);
	}
}
