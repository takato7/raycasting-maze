/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:31:03 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/10 15:02:40 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "structs.h"
# include "utils.h"

void	ft_init_file(t_file *f, char *av[]);
void	ft_init_cub3d(t_cub3d *cub3d, t_map *map);

#endif
