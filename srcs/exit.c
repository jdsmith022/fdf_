/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: JessicaSmith <JessicaSmith@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/23 21:18:57 by JessicaSmit    #+#    #+#                */
/*   Updated: 2020/03/23 21:26:55 by JessicaSmit   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void        mlx_free(t_fdf *fdf)
{
	if (fdf->mlx_ptr)
	{
		ft_bzero(fdf->mlx_ptr, sizeof(fdf->mlx_ptr));
		free(fdf->mlx_ptr);
	}
	if (fdf->window_ptr)
	{
		ft_bzero(fdf->window_ptr, sizeof(fdf->window_ptr));
		free(fdf->window_ptr);
	}
	if (fdf->image_ptr)
	{
		ft_bzero(fdf->image_ptr, sizeof(fdf->image_ptr));
		free(fdf->image_ptr);
	}
    if (fdf->addr_str)
	{
		ft_bzero(fdf->addr_str, sizeof(fdf->addr_str));
		free(fdf->addr_str);
	}
}

void		ft_exit(char *str, int fd, t_fdf *fdf)
{
	ft_putstr(str);
	close(fd);
    mlx_free(fdf);
	if (fdf != NULL)
	{
		ft_bzero(fdf, sizeof(fdf));
		free(fdf);
	}
	exit(0);
}