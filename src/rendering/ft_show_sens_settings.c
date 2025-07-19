/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_sens_settings.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 11:11:41 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/11 17:06:33 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

static int	ft_build_sens_str(char *s, double value, size_t size, char *type)
{
	size_t	sval_sl;
	size_t	type_sl;
	char	*sval;

	sval = ft_itoa(21 - (int)value / 100);
	if (!sval)
		return (0);
	type_sl = ft_strlen(type);
	ft_strlcpy(s, type, size);
	s += type_sl;
	size -= type_sl;
	sval_sl = ft_strlen(sval);
	if (sval_sl == 1)
	{
		s[0] = ' ';
		s++;
		size--;
	}
	ft_strlcpy(s, sval, size);
	free(sval);
	s += sval_sl;
	size -= sval_sl;
	ft_strlcpy(s, " / 20", size);
	return (1);
}

int	ft_show_sens_settings(t_settings *set, void *mlx, void *win)
{
	long	ct;
	char	s[30];

	ct = 0;
	if (set->show_info)
	{
		ct = ft_getcurrenttime();
		if (!ct)
			return (0);
		if (ct - set->start_show < 2000)
		{
			if (!ft_build_sens_str(s, set->value, 30, "Mouse sens: "))
				return (0);
			mlx_string_put(mlx, win, set->set_x, set->set_y, 0xFFFFFF00, s);
		}
		else
		{
			set->start_show = 0;
			set->show_info = 0;
		}
	}
	return (1);
}
