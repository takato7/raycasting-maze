/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:50:21 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/15 15:48:59 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static int	ft_is_mandatory_element(char *s, int *el_id)
{
	if (!ft_strncmp(s, "NO ", 3))
		*el_id = TEXNORTH;
	else if (!ft_strncmp(s, "EA ", 3))
		*el_id = TEXEAST;
	else if (!ft_strncmp(s, "SO ", 3))
		*el_id = TEXSOUTH;
	else if (!ft_strncmp(s, "WE ", 3))
		*el_id = TEXWEST;
	else if (!ft_strncmp(s, "F ", 2))
		*el_id = COLFLOOR;
	else if (!ft_strncmp(s, "C ", 2))
		*el_id = COLCEILING;
	else
		*el_id = NOELEMENT;
	return (*el_id);
}

static int	ft_is_bonus_element(char *s, int *el_id)
{
	if (!ft_strncmp(s, "DO ", 3))
		*el_id = TEXDOOR;
	else if (!ft_strncmp(s, "DOS ", 4))
		*el_id = TEXDOORSIDE;
	else if (!ft_strncmp(s, "SQ0 ", 4))
		*el_id = TEXSQUIRREL_ZERO;
	else if (!ft_strncmp(s, "SQ1 ", 4))
		*el_id = TEXSQUIRREL_ONE;
	else if (!ft_strncmp(s, "SQ2 ", 4))
		*el_id = TEXSQUIRREL_TWO;
	else if (!ft_strncmp(s, "SQ3 ", 4))
		*el_id = TEXSQUIRREL_THREE;
	else
		*el_id = NOELEMENT;
	return (*el_id);
}

static int	ft_is_element(char *s, int *el_id)
{
	if (ft_is_mandatory_element(s, el_id))
		return (*el_id);
	if (ft_is_bonus_element(s, el_id))
		return (*el_id);
	return (*el_id);
}

static int	ft_find_elements(t_file *f, size_t *x, size_t y)
{
	int	el_id;

	*x += ft_skip_space(&f->file[y][*x]);
	if (ft_is_element(&f->file[y][*x], &el_id))
	{
		if (!ft_get_element_info(f, &f->file[y][*x], el_id))
			return (0);
		*x += ft_move_past_element(&f->file[y][*x]);
	}
	else if (f->file[y][*x])
		return (ft_error(EUNEXPECTED, &f->file[y][*x]));
	return (1);
}

int	ft_get_elements(t_file *f)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (f->file[y])
	{
		x = 0;
		if (ft_found_map(f->file[y]))
		{
			if (!ft_get_map(f, y))
				return (0);
			break ;
		}
		while (f->file[y][x])
		{
			if (!ft_find_elements(f, &x, y))
				return (0);
		}
		y++;
	}
	return (1);
}
