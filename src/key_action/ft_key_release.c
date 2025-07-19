/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_release.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:24:45 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/15 16:20:48 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_action.h"

static void	ft_settings_key_release(int key, t_keys *keys)
{
	if (key == XK_m)
		keys->m = 0;
	else if (key == XK_KP_Subtract)
		keys->minus = 0;
	else if (key == XK_KP_Add)
		keys->plus = 0;
	else if (key == XK_KP_Insert)
		keys->zero = 0;
	else if (key == XK_KP_Multiply)
		keys->mult = 0;
	else if (key == XK_KP_Divide)
		keys->div = 0;
	else if (key == XK_KP_Equal)
		keys->equal = 0;
	else if (key == XK_f)
		keys->f = 0;
}

static void	ft_interaction_key_release(int key, t_keys *keys)
{
	if (key == XK_Left)
		keys->left = 0;
	else if (key == XK_Right)
		keys->right = 0;
	else if (key == XK_w)
		keys->w = 0;
	else if (key == XK_a)
		keys->a = 0;
	else if (key == XK_s)
		keys->s = 0;
	else if (key == XK_d)
		keys->d = 0;
	else if (key == XK_space)
		keys->space = 0;
}

int	ft_key_release(int key, void *param)
{
	t_keys	*keys;

	keys = (t_keys *)param;
	if (key == XK_Escape)
		keys->esc = 0;
	ft_interaction_key_release(key, keys);
	ft_settings_key_release(key, keys);
	return (1);
}
