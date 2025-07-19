/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:02:38 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/15 16:11:44 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "enums.h"
# include "macros.h"
# include "cleanup.h"

int			ft_error(int e, const char *detail);
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
int			ft_putstr(const char *s, int fd);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_is_printable(char c);
int			ft_open(const char *path, int *fd);
u_int8_t	ft_colortoi(char **s, int *overflow);
int			ft_bgra(int b, int g, int r, int a);
long		ft_getcurrenttime(void);
char		*ft_itoa(int num);
int			ft_found_player(char c);
void		ft_set_img_addr(t_imgs *imgs);
void		ft_put_img_to_win(void *img, t_cub3d *cub3d);
double		ft_get_time_diff_sec(struct timeval curr, struct timeval prev);

#endif
