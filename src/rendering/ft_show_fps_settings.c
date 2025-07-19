/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_fps_settings.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 12:37:01 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/15 16:20:43 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

static int	ft_build_fps_str(char *s, int value, size_t size, char *type)
{
	char	*sval;
	size_t	type_sl;

	type_sl = ft_strlen(type);
	sval = ft_itoa(value);
	if (!sval)
		return (0);
	ft_strlcpy(s, type, size);
	ft_strlcpy(s + type_sl, sval, size - type_sl);
	return (free(sval), 1);
}

void	ft_show_fps(t_fps_counter *fps_counter, void *mlx, void *win)
{
	char	s[30];
	int		fps;

	fps = (int)round(1.0 / *fps_counter->frame_time);
	ft_build_fps_str(s, fps, 30, "FPS: ");
	mlx_string_put(mlx, win, fps_counter->x, fps_counter->y, 0xFFFFFF00, s);
}
