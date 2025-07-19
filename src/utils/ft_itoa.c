/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 08:45:21 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/15 15:32:28 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	ft_get_ndig(int num, int ndig)
{
	if (num >= 10 || num <= -10)
		return (ft_get_ndig(num / 10, ndig + 1));
	if (num < 0)
		ndig++;
	return (ndig);
}

static void	ft_itoa_rec(int num, int ndig, char *s)
{
	if (num >= 10 || num <= -10)
		ft_itoa_rec(num / 10, ndig - 1, s);
	if (num < 0)
		s[ndig] = ((num % 10) * -1) + '0';
	else
		s[ndig] = (num % 10) + '0';
}

char	*ft_itoa(int num)
{
	char	*s;
	int		ndig;

	ndig = 1;
	ndig = ft_get_ndig(num, ndig);
	s = malloc(ndig + 1);
	if (!s)
	{
		ft_error(EMALLOC, NULL);
		return (NULL);
	}
	if (num < 0)
		s[0] = '-';
	ft_itoa_rec(num, ndig - 1, s);
	s[ndig] = '\0';
	return (s);
}
