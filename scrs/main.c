/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 16:02:56 by mminkjan       #+#    #+#                */
/*   Updated: 2019/12/02 18:45:28 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int argc, char **argv)
{
	t_fdf		*fdf;
	// t_points	points;
	
	(void)argv;
	if (argc != 2)
		ft_exit(USAGE_ERR);
	fdf = (t_fdf*)ft_memalloc(sizeof(t_fdf));
	if (fdf == NULL)
		ft_exit(USAGE_ERR);
	ft_bzero(fdf, sizeof(t_fdf));
	fdf->map_name = ft_strdup(argv[1]);
	mlx_setup(fdf);
	// import_map(&fdf, &points, argv);
	// calculate_points(&fdf, &points); //keep track of head of list here
	mlx_loop(fdf->mlx_ptr);
}
