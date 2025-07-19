/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:09:10 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/15 15:30:50 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_open(const char *path, int *fd)
{
	*fd = open(path, O_RDONLY);
	if (*fd == -1)
		return (ft_error(ERRNO, path));
	return (1);
}
