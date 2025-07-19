/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:46:25 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/10 16:20:04 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "utils.h"
# include "enums.h"
# include "macros.h"
# include "structs.h"
# include "get_next_line.h"
# include "cleanup.h"

int		ft_validate_file(t_file *f);
int		ft_validate_file_content(t_file *f);
int		ft_validate_elements(t_file *f);
int		ft_get_element_info(t_file *f, char *el, int el_id);
int		ft_get_elements(t_file *f);
int		ft_new_tex(t_tex **head, char *el, int el_id);
int		ft_new_col(t_col **head, char *el, int el_id);
size_t	ft_skip_space(char *s);
size_t	ft_move_past_element(char *s);
int		ft_found_map(char *line);
int		ft_end_of_map(char *line);
int		ft_get_map(t_file *f, size_t y);
int		ft_is_valid_map_char(char c);
int		ft_only_trailing_spaces(char *line);
size_t	ft_get_line_length(char *line);
int		ft_malloc_map(t_map *map);
int		ft_validate_texture_info(t_tex *tex);
int		ft_validate_color_info(t_col *col);
int		ft_validate_map(t_map *m);
int		ft_copy_map_with_border(char ***dst, char **src, t_map_val *mval);
int		ft_validate_wall(t_map_val *map);
int		ft_validate_player(t_map *map);
int		ft_validate_playable_area(t_map_val *map);
int		ft_validate_doors(t_map_val *map);

#endif
