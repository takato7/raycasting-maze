/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colortoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:20:23 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/18 17:09:41 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	ft_check_leading_zeros(char *s, int *error)
{
	if (*s == '0' && *(s + 1) >= '0' && *(s + 1) <= '9')
	{
		*error = 1;
		return (0);
	}
	return (1);
}

u_int8_t	ft_colortoi(char **s, int *error)
{
	u_int8_t	num;
	u_int8_t	num_new;

	if (!ft_check_leading_zeros(*s, error))
		return (*error);
	num = 0;
	while (**s >= '0' && **s <= '9')
	{
		num_new = num * 10 + (**s - '0');
		if (num_new < num)
		{
			*error = 1;
			return (*error);
		}
		num = num_new;
		(*s)++;
	}
	return (num);
}
