/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_element_info.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:23:36 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/11 08:52:08 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static void	ft_move_to_info(char **el)
{
	while (**el && **el != ' ')
		(*el)++;
	while (**el && **el == ' ')
		(*el)++;
}

int	ft_get_element_info(t_file *f, char *el, int el_id)
{
	ft_move_to_info(&el);
	if (el_id == COLFLOOR || el_id == COLCEILING)
	{
		if (!ft_new_col(&f->col, el, el_id))
			return (0);
	}
	else
	{
		if (!ft_new_tex(&f->tex, el, el_id))
			return (0);
	}
	return (1);
}
