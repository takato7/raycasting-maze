/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:56:56 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/15 16:34:05 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

enum e_errors
{
	ERRNO,
	ENUMPARAM,
	EFILEFORMAT,
	EMALLOC,
	EUNEXPECTED,
	EMISSINGTEX,
	EMISSINGCOL,
	EDUPENTRIES,
	EWALL,
	ENUMPLAYERS,
	EMLXINIT,
	EMLXWIN,
	EMLXLOADTEX,
	EMLXNEWIMG,
	EGETTIME,
	EMAP,
	EDOORS,
	ECOLORFORMAT
};

enum e_elements
{
	NOELEMENT,
	TEXNORTH,
	TEXEAST,
	TEXWEST,
	TEXSOUTH,
	TEXDOOR,
	TEXDOORSIDE,
	TEXSQUIRREL_ZERO,
	TEXSQUIRREL_ONE,
	TEXSQUIRREL_TWO,
	TEXSQUIRREL_THREE,
	COLFLOOR,
	COLCEILING
};

enum e_colors
{
	RED,
	GREEN,
	BLUE
};

enum e_cell
{
	FLOOR_CELL,
	WALL_CELL,
	CLOSED_DOOR_CELL_H,
	OPEN_DOOR_CELL_H,
	CLOSED_DOOR_CELL_V,
	OPEN_DOOR_CELL_V,
	PLAYER_CELL,
	SQUIRREL_CELL,
	BACKGROUND_CELL
};

enum e_dir
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

typedef enum e_side
{
	ROW_SIDE,
	COL_SIDE,
}	t_side;

typedef enum e_img_field
{
	NO,
	SO,
	WE,
	EA,
	SPRITE_0,
	SPRITE_1,
	SPRITE_2,
	SPRITE_3,
	DOOR,
	DOOR_SIDE,
	MAX_IMAGE,
}	t_img_field;

typedef enum e_status
{
	CLOSE,
	CLOSING,
	OPENING,
	OPEN,
}	t_status;

#endif
