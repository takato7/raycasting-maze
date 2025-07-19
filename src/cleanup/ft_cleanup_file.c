/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:56:24 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/10 16:19:23 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleanup.h"

static void	ft_cleanup_tex(t_tex *curr)
{
	t_tex	*next;

	while (curr)
	{
		next = curr->next;
		free(curr->tex_path);
		free(curr);
		curr = next;
	}
}

static void	ft_cleanup_col(t_col *curr)
{
	t_col	*next;

	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
}

void	ft_cleanup_str_array(char **sa, size_t nlines)
{
	size_t	i;

	if (!sa)
		return ;
	i = 0;
	while (i < nlines)
	{
		free(sa[i]);
		sa[i] = NULL;
		i++;
	}
	free(sa);
	sa = NULL;
}

void	ft_cleanup_file(t_file *f)
{
	ft_cleanup_tex(f->tex);
	ft_cleanup_col(f->col);
	ft_cleanup_str_array(f->file, f->nlines);
	ft_cleanup_str_array(f->map.map, f->map.height);
}
