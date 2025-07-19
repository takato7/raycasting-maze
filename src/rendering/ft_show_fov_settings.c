/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_fov_settings.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 12:37:27 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/11 17:07:48 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

static void	ft_add_pre_dec(char **s, size_t *size, int pre_dec, int post_dec)
{
	if (pre_dec == 0)
		(*s)++[0] = '0';
	else
		(*s)++[0] = '1';
	(*size)--;
	(*s)++[0] = '.';
	(*size)--;
	if (post_dec < 10)
	{
		(*s)++[0] = '0';
		(*size)--;
	}
}

static void	ft_add_post_dec(char *s, char *post_dec, size_t size)
{
	ft_strlcpy(s, post_dec, size);
}

static int	ft_build_fov_str(char *s, double value, size_t size, char *type)
{
	size_t	type_sl;
	char	*post_dec;
	int		pre_dec_int;
	int		post_dec_int;

	pre_dec_int = (int)value;
	post_dec_int = (int)round(value * 100) % 100;
	post_dec = ft_itoa(post_dec_int);
	if (!post_dec)
		return (free(post_dec), 0);
	type_sl = ft_strlen(type);
	ft_strlcpy(s, type, size);
	s += type_sl;
	size -= type_sl;
	ft_add_pre_dec(&s, &size, pre_dec_int, post_dec_int);
	ft_add_post_dec(s, post_dec, size);
	return (free(post_dec), 1);
}

int	ft_show_fov_settings(t_settings *set, void *mlx, void *win)
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
			ft_build_fov_str(s, set->value, 30, "Fov factor: ");
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
