/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:03:49 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/10 15:27:04 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	ft_swap_value(t_sprite *s1, t_sprite *s2)
{
	t_sprite	tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

void	ft_sort_sprite(t_sprite *sprite, size_t num)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (i < num)
	{
		j = 0;
		while (j < num - i - 1)
		{
			if (sprite[j].dist - sprite[j + 1].dist < EPSILON)
				ft_swap_value(&sprite[j], &sprite[j + 1]);
			j++;
		}
		i++;
	}
}
