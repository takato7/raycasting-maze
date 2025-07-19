/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:24:45 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/15 16:20:52 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_action.h"

static void	ft_settings_key_press(int key, t_keys *keys)
{
	if (key == XK_m)
		keys->m = 1;
	else if (key == XK_KP_Subtract)
		keys->minus = 1;
	else if (key == XK_KP_Add)
		keys->plus = 1;
	else if (key == XK_KP_Insert)
		keys->zero = 1;
	else if (key == XK_KP_Multiply)
		keys->mult = 1;
	else if (key == XK_KP_Divide)
		keys->div = 1;
	else if (key == XK_KP_Equal)
		keys->equal = 1;
	else if (key == XK_f)
		keys->f = 1;
}

static void	ft_interaction_key_press(int key, t_keys *keys)
{
	if (key == XK_Left)
		keys->left = 1;
	else if (key == XK_Right)
		keys->right = 1;
	else if (key == XK_w)
		keys->w = 1;
	else if (key == XK_a)
		keys->a = 1;
	else if (key == XK_s)
		keys->s = 1;
	else if (key == XK_d)
		keys->d = 1;
	else if (key == XK_space)
		keys->space = 1;
}

int	ft_key_press(int key, void *param)
{
	t_keys	*keys;

	keys = (t_keys *)param;
	if (key == XK_Escape)
		keys->esc = 1;
	ft_interaction_key_press(key, keys);
	ft_settings_key_press(key, keys);
	return (1);
}
