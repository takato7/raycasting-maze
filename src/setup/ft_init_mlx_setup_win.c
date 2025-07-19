/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx_setup_win.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:15:13 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/15 15:32:03 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"

static void	ft_set_win_dimesions(t_cub3d *cub)
{
	int	screen_x;
	int	screen_y;

	cub->win_y = WIN_Y_DEFAULT;
	cub->win_x = WIN_Y_DEFAULT * 4 / 3;
	mlx_get_screen_size(cub->mlx, &screen_x, &screen_y);
	if ((screen_y * 19 / 20) < cub->win_y)
	{
		cub->win_y = screen_y * 19 / 20;
		cub->win_x = cub->win_y * 4 / 3;
	}
	else if (screen_x < cub->win_x)
	{
		cub->win_x = screen_x;
		cub->win_y = cub->win_x * 3 / 4;
	}
}

int	ft_init_mlx_setup_win(t_cub3d *cub)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
		return (ft_error(EMLXINIT, NULL));
	ft_set_win_dimesions(cub);
	cub->win = mlx_new_window(cub->mlx, cub->win_x, cub->win_y, TITLE);
	if (!cub->win)
		return (ft_error(EMLXWIN, NULL));
	return (1);
}
