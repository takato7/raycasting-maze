/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:59:29 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/10 15:42:15 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_putstr(const char *s, int fd)
{
	size_t	slen;

	slen = ft_strlen(s);
	if (write(fd, s, slen) == -1)
		return (0);
	return (1);
}
