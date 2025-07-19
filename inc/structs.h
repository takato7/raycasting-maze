/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:21:43 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/15 16:21:23 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/time.h>
# include "enums.h"

typedef struct s_pos
{
	int	x;
	int	y;
}			t_pos;

typedef struct s_map_val
{
	char	**map;
	int		valid;
	int		height;
	int		width;
	int		old_width;
	int		old_height;
}			t_map_val;

typedef struct s_tex
{
	char			*tex_path;
	int				id;
	struct s_tex	*next;
}					t_tex;

typedef struct s_col
{
	u_int8_t		r;
	u_int8_t		g;
	u_int8_t		b;
	int				id;
	struct s_col	*next;
}					t_col;

typedef struct s_map
{
	char	**map;
	size_t	height;
	size_t	width;
	t_pos	player;
}			t_map;

typedef struct s_file
{
	const char	*file_path;
	char		**file;
	size_t		nlines;
	t_tex		*tex;
	t_col		*col;
	t_map		map;
}				t_file;

typedef struct s_imgs
{
	void	*img;
	char	*data;
	int		bpp;
	int		sl;
	int		endian;
	int		x;
	int		y;
}			t_imgs;

typedef struct s_ray
{
	double	dir_row;
	double	dir_col;
}			t_ray;

typedef struct s_dist
{
	double	side_row;
	double	side_col;
	double	delta_row;
	double	delta_col;
}			t_dist;

typedef struct s_dda
{
	double		wall_dist;
	int			step_row;
	int			step_col;
	int			map_row;
	int			map_col;
	char		hit_type;
	int			side;
	double		hit_x;
	t_img_field	img;
}				t_dda;

typedef struct s_rcast
{
	t_ray	ray;
	t_dist	dist;
	t_dda	dda;
}			t_rcast;

typedef struct s_draw
{
	int		len_win;
	int		len_tex;
	int		begin;
	int		end;
}			t_draw;

typedef struct s_collision
{
	double	add_row;
	double	add_col;
	double	pos_row;
	double	pos_col;
	int		nexmap_row;
	int		nexmap_col;
	int		side_row;
	int		side_col;
}			t_collision;

typedef struct s_sprite
{
	int		id;
	int		map_row;
	int		map_col;
	double	pos_row;
	double	pos_col;
	double	x_on_camera;
	double	y_on_camera;
	int		x_on_win;
	int		y_on_win;
	int		hight;
	int		width;
	double	dist;
}			t_sprite;

typedef struct s_door
{
	t_side		dir;
	double		row;
	double		col;
	t_status	status;
	double		open_ratio;
	int			texid;
}				t_door;

typedef struct s_mm_cols
{
	int	wall;
	int	background;
	int	floor;
	int	player;
	int	squirrel;
	int	door_closed;
	int	door_open;
}		t_mm_cols;

typedef struct s_mmap
{
	void		*mlx;
	void		*win;
	int			map_width;
	int			map_height;
	int			width;
	int			height;
	int			vis_dist;
	int			cell_size;
	int			player_border;
	t_imgs		img;
	char		**map;
	char		*mmap;
	double		*pos_x;
	double		*pos_y;
	t_mm_cols	cols;
	int			can_toggle;
	int			visible;
}				t_mmap;

typedef struct s_settings
{
	int		show_info;
	long	start_show;
	double	value;
	int		set_x;
	int		set_y;
}			t_settings;

typedef struct s_rot
{
	double		*dir_row;
	double		*dir_col;
	double		*plane_row;
	double		*plane_col;
	int			sens;
	int			can_adjust;
	t_settings	set;
}				t_rot;

typedef struct s_mouse
{
	void	*mlx;
	void	*win;
	int		max_x;
	int		max_y;
	int		min_x;
	int		min_y;
	int		center_x;
	int		center_y;
	int		x_prev;
	int		max_diff;
	int		skip;
	int		focus;
	t_rot	rot;
}			t_mouse;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	m;
	int	minus;
	int	plus;
	int	zero;
	int	mult;
	int	div;
	int	equal;
	int	f;
	int	left;
	int	right;
	int	esc;
	int	space;
}		t_keys;

typedef struct s_fov
{
	double		fov_factor;
	int			can_adjust;
	t_settings	set;
}				t_fov;

typedef struct s_fps_counter
{
	double	*frame_time;
	int		x;
	int		y;
	int		can_toggle;
	int		visible;
}		t_fps_counter;

typedef struct s_cub3d
{
	void			*mlx;
	void			*win;
	t_imgs			*imgs;
	t_imgs			fov;
	int				win_x;
	int				win_y;
	char			**map;
	double			pos_row;
	double			pos_col;
	double			dir_row;
	double			dir_col;
	double			plane_row;
	double			plane_col;
	double			wall_dist;
	struct timeval	time;
	struct timeval	prev_time;
	double			frame_time;
	double			move_speed;
	double			rot_speed;
	int				f_color;
	int				c_color;
	size_t			num_sprite;
	t_sprite		*sprite;
	double			*wall_dists;
	struct timeval	anim_time;
	t_door			**doors;
	int				door_act;
	t_mmap			mmap;
	t_map			*map_data;
	t_mouse			mouse;
	t_keys			keys;
	t_fov			fov_data;
	t_fps_counter	fps_counter;
}					t_cub3d;

#endif
