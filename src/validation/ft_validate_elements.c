/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_elements.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:29:34 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/10 16:07:09 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

int	ft_validate_elements(t_file *f)
{
	if (!ft_get_elements(f))
		return (0);
	if (!ft_validate_texture_info(f->tex))
		return (0);
	if (!ft_validate_color_info(f->col))
		return (0);
	if (!ft_validate_map(&f->map))
		return (0);
	return (1);
}
