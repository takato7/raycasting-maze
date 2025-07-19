/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:56:46 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/10 16:19:23 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEANUP_H
# define CLEANUP_H

# include <stdlib.h>
# include "mlx.h"
# include "structs.h"

void	ft_cleanup_file(t_file *f);
void	ft_destroy_cub3d(t_cub3d *cub3d);
void	ft_cleanup_str_array(char **sa, size_t nlines);

#endif
