/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:53:28 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/15 15:44:31 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	ft_errno(int e)
{
	if (e == ERRNO)
		ft_putstr(strerror(errno), 2);
}

static void	ft_validation_error(int e)
{
	if (e == ENUMPARAM)
		ft_putstr("Incorrect number of parameters", 2);
	else if (e == EFILEFORMAT)
		ft_putstr("Configuration file has incorrect file format", 2);
	else if (e == EMALLOC)
		ft_putstr("Failed to allocate memory", 2);
	else if (e == ECOLORFORMAT)
		ft_putstr("Invalid RGB format", 2);
	else if (e == EUNEXPECTED)
		ft_putstr("Configuration file contains unexpected symbol", 2);
	else if (e == EMISSINGTEX)
		ft_putstr("Configuration file is missing a required texture path", 2);
	else if (e == EMISSINGCOL)
		ft_putstr("Configuration file is missing required color info", 2);
	else if (e == EDUPENTRIES)
		ft_putstr("Configuration file contains duplicate entries", 2);
	else if (e == EWALL)
		ft_putstr("The map is not fully surrounded by a wall", 2);
	else if (e == ENUMPLAYERS)
		ft_putstr("Incorrect number of players found", 2);
	else if (e == EDOORS)
		ft_putstr("Incorrect door placement", 2);
	else if (e == EMAP)
		ft_putstr("Map contains space characters in playable area", 2);
}

static void	ft_mlx_error(int e)
{
	if (e == EMLXINIT)
		ft_putstr("Failed to initialize MLX", 2);
	else if (e == EMLXWIN)
		ft_putstr("Failed to create MLX window", 2);
	else if (e == EMLXLOADTEX)
		ft_putstr("Failed to load a texture", 2);
	else if (e == EMLXNEWIMG)
		ft_putstr("Failed to create new image buffer", 2);
}

static void	ft_misc_error(int e)
{
	if (e == EGETTIME)
		ft_putstr("Failed to get current time", 2);
}

int	ft_error(int e, const char *detail)
{
	ft_putstr("Error\n", 2);
	ft_errno(e);
	ft_validation_error(e);
	ft_mlx_error(e);
	ft_misc_error(e);
	if (detail)
	{
		ft_putstr(": ", 2);
		ft_putstr(detail, 2);
	}
	ft_putstr("\n", 2);
	return (0);
}
