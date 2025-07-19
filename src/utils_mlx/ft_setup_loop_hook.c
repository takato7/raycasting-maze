/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup_loop_hook.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:22:59 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/10 15:44:10 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_setup_loop_hook(void *mlx, int (*funct)(), void *param)
{
	mlx_loop_hook(mlx, funct, param);
}
