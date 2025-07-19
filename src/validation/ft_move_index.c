/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:32:11 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/18 20:34:05 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

size_t	ft_skip_space(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] == ' ')
		i++;
	return (i);
}

size_t	ft_move_past_element(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && ft_is_printable(s[i]))
		i++;
	while (s[i] && s[i] == ' ')
		i++;
	while (s[i] && ft_is_printable(s[i]))
		i++;
	return (i);
}
