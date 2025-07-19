/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_found_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:00:32 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/15 11:03:33 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_found_player(char c)
{
	if (c == C_PLAYER_N)
		return (1);
	if (c == C_PLAYER_E)
		return (1);
	if (c == C_PLAYER_S)
		return (1);
	if (c == C_PLAYER_W)
		return (1);
	return (0);
}
