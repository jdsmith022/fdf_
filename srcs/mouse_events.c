/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mouse_events.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 15:07:16 by jesmith        #+#    #+#                */
/*   Updated: 2020/02/29 18:05:56 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		mouse_move(int x, int y, t_fdf *fdf)
{
	if (fdf->events.mouse_press == 1)
	{
		fdf->events.move_x += (fdf->events.hold_x - x);
		fdf->events.move_y += (fdf->events.hold_y - y);
		fdf->events.hold_x = x;
		fdf->events.hold_y = y;
	}
	return (0);
}

int		mouse_press(int button, int x, int y, t_fdf *fdf)
{
	if (button == SCROLL_DOWN && fdf->events.zoom > 0.1)
		fdf->events.zoom -= 0.1;
	else if (button == SCROLL_UP)
		fdf->events.zoom += 0.1;
	else if (button == MOUSE_PRESS)
	{
		fdf->events.mouse_press = 1;
		fdf->events.hold_x = x;
		fdf->events.hold_y = y;
	}
	return (0);
}

int		mouse_release(int button, int x, int y, t_fdf *fdf)
{
	x = 0;
	y = 0;
	if (button == MOUSE_PRESS)
		fdf->events.mouse_press = 0;
	return (0);
}

int		close_window(t_fdf *fdf)
{
	free_structs(fdf);
	exit(0);
}
