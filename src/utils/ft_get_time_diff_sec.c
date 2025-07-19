/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_time_diff_sec.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:58:19 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/10 15:58:27 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

double	ft_get_time_diff_sec(struct timeval curr, struct timeval prev)
{
	double	usec_now;
	double	usec_from;

	usec_now = curr.tv_sec * 1e6 + curr.tv_usec;
	usec_from = prev.tv_sec * 1e6 + prev.tv_usec;
	return ((usec_now - usec_from) / 1e6);
}
