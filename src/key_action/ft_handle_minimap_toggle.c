/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_minimap_toggle.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:39:44 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/10 16:39:52 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_action.h"

void	ft_handle_minimap_toggle(t_mmap *mmap, t_keys *keys)
{
	if (mmap->can_toggle && keys->m)
	{
		mmap->visible = !mmap->visible;
		mmap->can_toggle = 0;
	}
	if (!keys->m)
		mmap->can_toggle = 1;
}
