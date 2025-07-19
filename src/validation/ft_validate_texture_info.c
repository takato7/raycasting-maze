/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_texture_info.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:05:56 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/15 15:37:02 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static int	ft_got_tex_info(t_tex *tex, int type)
{
	int	nfound;

	nfound = 0;
	while (tex)
	{
		if (tex->id == type)
			nfound++;
		tex = tex->next;
	}
	if (nfound > 1)
		return (ft_error(EDUPENTRIES, NULL));
	if (nfound == 0)
		return (ft_error(EMISSINGTEX, NULL));
	return (1);
}

static int	ft_got_all_necessary_tex_info(t_tex *tex)
{
	if (!ft_got_tex_info(tex, TEXNORTH))
		return (0);
	if (!ft_got_tex_info(tex, TEXEAST))
		return (0);
	if (!ft_got_tex_info(tex, TEXSOUTH))
		return (0);
	if (!ft_got_tex_info(tex, TEXWEST))
		return (0);
	if (!ft_got_tex_info(tex, TEXDOOR))
		return (0);
	if (!ft_got_tex_info(tex, TEXDOORSIDE))
		return (0);
	if (!ft_got_tex_info(tex, TEXSQUIRREL_ZERO))
		return (0);
	if (!ft_got_tex_info(tex, TEXSQUIRREL_ONE))
		return (0);
	if (!ft_got_tex_info(tex, TEXSQUIRREL_TWO))
		return (0);
	if (!ft_got_tex_info(tex, TEXSQUIRREL_THREE))
		return (0);
	return (1);
}

static int	ft_texture_files_readable(t_tex *tex)
{
	int	fd;

	while (tex)
	{
		if (!ft_open(tex->tex_path, &fd))
			return (0);
		close(fd);
		tex = tex->next;
	}
	return (1);
}

int	ft_validate_texture_info(t_tex *tex)
{
	if (!ft_got_all_necessary_tex_info(tex))
		return (0);
	if (!ft_texture_files_readable(tex))
		return (0);
	return (1);
}
