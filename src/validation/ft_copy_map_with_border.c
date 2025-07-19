/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_map_with_border.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:25:07 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/15 15:32:39 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static size_t	ft_get_nrows(char **src)
{
	size_t	nrows;

	nrows = 0;
	while (src[nrows])
		nrows++;
	return (nrows);
}

static int	ft_malloc_exp_arr(char ***dst, size_t new_rows, size_t new_width)
{
	size_t	i;

	*dst = malloc(sizeof(char *) * (new_rows + 1));
	if (!*dst)
		return (ft_error(EMALLOC, NULL));
	i = 0;
	while (i < new_rows)
	{
		(*dst)[i] = malloc(new_width + 1);
		if (!(*dst)[i])
		{
			ft_cleanup_str_array(*dst, i);
			return (ft_error(EMALLOC, NULL));
		}
		i++;
	}
	(*dst)[i] = NULL;
	return (1);
}

static void	ft_fill_border_line(char *line, size_t new_width)
{
	size_t	i;

	i = 0;
	while (i < new_width)
	{
		line[i] = ' ';
		i++;
	}
	line[i] = '\0';
}

static void	ft_fill_middle_line(char *dst, char *src, size_t old_width)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	dst[0] = ' ';
	i = 0;
	while (i < src_len && i < old_width)
	{
		dst[i + 1] = src[i];
		i++;
	}
	dst[old_width + 1] = ' ';
	dst[old_width + 2] = '\0';
}

int	ft_copy_map_with_border(char ***dst, char **src, t_map_val *mval)
{
	size_t	orig_rows;
	size_t	src_row;
	size_t	dst_row;

	orig_rows = ft_get_nrows(src);
	if (!ft_malloc_exp_arr(dst, mval->height, mval->width))
		return (0);
	ft_fill_border_line((*dst)[0], mval->width);
	dst_row = 1;
	src_row = 0;
	while (src_row < orig_rows)
	{
		ft_fill_middle_line((*dst)[dst_row], src[src_row], mval->old_width);
		dst_row++;
		src_row++;
	}
	ft_fill_border_line((*dst)[dst_row], mval->width);
	return (1);
}
