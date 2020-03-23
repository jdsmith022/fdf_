/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_setup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 18:16:17 by mminkjan       #+#    #+#                */
/*   Updated: 2020/03/23 21:25:59 by JessicaSmit   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	mlx_setup(t_fdf *fdf)
{
	int		endian;

	endian = 0;
	fdf->mlx_ptr = mlx_init();
	fdf->window_ptr = mlx_new_window(fdf->mlx_ptr, WIDTH + 400, HEIGHT,
		fdf->map_name);
	if (fdf->window_ptr == NULL)
		ft_exit(MALLOC_ERR, 1, fdf);
	fdf->image_ptr = mlx_new_image(fdf->mlx_ptr, WIDTH, HEIGHT);
	if (fdf->image_ptr == NULL)
		ft_exit(MALLOC_ERR, 1, fdf);
	fdf->addr_str = mlx_get_data_addr(fdf->image_ptr, &fdf->bpp,
		&fdf->size_line, &endian);
	if (fdf->addr_str == NULL)
		ft_exit(MALLOC_ERR, 1, fdf);
}
