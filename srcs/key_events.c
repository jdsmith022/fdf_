/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_events.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/29 18:06:22 by jesmith        #+#    #+#                */
/*   Updated: 2020/03/23 21:25:55 by JessicaSmit   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		key_press2(int key_code,
					t_fdf *fdf)
{
	if (key_code == ONE)
		fdf->events.color_set = 1;
	else if (key_code == TWO)
		fdf->events.color_set = 2;
	else if (key_code == THREE)
		fdf->events.color_set = 3;
	else if (key_code == FOUR)
		fdf->events.color_set = 4;
	else if (key_code == FIVE)
		fdf->events.color_set = 5;
	else if (key_code == ZERO)
	{
		fdf->events.iso = 0;
		fdf->events.top = 1;
	}
	else if (key_code == I)
	{
		fdf->events.top = 0;
		fdf->events.iso = 1;
	}
	else if (key_code == ESC)
	{
		mlx_free(fdf);
		free_structs(fdf);
		exit(0);
	}
}

int				key_press(int key_code,
					t_fdf *fdf)
{
	if (key_code == DEL)
		fdf->events.reset = 1;
	else if (key_code == W)
		fdf->events.rot_x++;
	else if (key_code == S)
		fdf->events.rot_x--;
	else if (key_code == E)
		fdf->events.rot_y++;
	else if (key_code == Q)
		fdf->events.rot_y--;
	else if (key_code == D)
		fdf->events.rot_z--;
	else if (key_code == A)
		fdf->events.rot_z++;
	else if (key_code == PLUS)
		fdf->events.extend++;
	else if (key_code == MIN)
		fdf->events.extend--;
	key_press2(key_code, fdf);
	return (0);
}
