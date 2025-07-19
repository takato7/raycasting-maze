/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_color_info.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:20:19 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/15 15:35:00 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static int	ft_got_color_info(t_col *col, int type)
{
	int	nfound;

	nfound = 0;
	while (col)
	{
		if (col->id == type)
			nfound++;
		col = col->next;
	}
	if (nfound > 1)
		return (ft_error(EDUPENTRIES, NULL));
	if (nfound == 0)
		return (ft_error(EMISSINGCOL, NULL));
	return (1);
}

static int	ft_got_all_necessary_color_info(t_col *col)
{
	if (!ft_got_color_info(col, COLFLOOR))
		return (0);
	if (!ft_got_color_info(col, COLCEILING))
		return (0);
	return (1);
}

int	ft_validate_color_info(t_col *col)
{
	if (!ft_got_all_necessary_color_info(col))
		return (0);
	return (1);
}
