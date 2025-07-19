/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcurrenttime.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:42:46 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/15 15:32:25 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

long	ft_getcurrenttime(void)
{
	struct timeval	ct;
	long			time;

	if (gettimeofday(&ct, NULL) == -1)
		return (ft_error(EGETTIME, NULL));
	time = (ct.tv_sec * 1000) + (ct.tv_usec / 1000);
	return (time);
}
