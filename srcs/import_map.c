/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   import_map.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 10:03:52 by jesmith        #+#    #+#                */
/*   Updated: 2019/12/04 18:40:59 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void			free_str(char **alt_values)
{
	size_t index;

	index = 0;
	while (alt_values[index])
	{
		ft_bzero(alt_values[index], 1);
		free(alt_values[index]);
		index++;
	}
	free(alt_values);
}

static t_points		*lst_addback(t_points **points,
						t_points *alt)
{
	t_points *temp;

	temp = *points;
	if (temp == NULL)
	{
		*points = alt;
		return (*points);
	}
	while (temp->next_x != NULL)
		temp = temp->next_x;
	temp->next_x = alt;
	return (*points);
}

static t_points		*new_alt_node(char *alt_values)
{
	t_points	*new_node;
	char		**new_str;
	int			value;

	new_node = (t_points*)ft_memalloc(sizeof(t_points));
	if (new_node == NULL)
		ft_exit(MALLOC_ERR);
	new_str = ft_strsplit(alt_values, ',');
	if (new_str == NULL)
		ft_exit(MALLOC_ERR);
	value = (int)ft_atoi(new_str[0]);
	new_node->alt = value;
	new_node->next_x = NULL;
	free_str(new_str);
	return (new_node);
}

static void			line_extract(t_points **points,
						char **alt_values,
						t_fdf *fdf)
{
	int	length;

	length = 0;
	while (*alt_values)
	{
		(*points) = lst_addback(&(*points), new_alt_node(*(alt_values)));
		alt_values++;
		length++;
	}
	if (fdf->map_width == 0)
		fdf->map_width = length;
	else
	{
		if (fdf->map_width != length)
			ft_exit(INVAL_ERR);
	}
}

void				import_map(t_fdf *fdf,
						t_points **points,
						char **argv)
{
	int		ret_val;
	char	*line;
	char	**alt_values;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_exit(FILE_ERR);
	while ((ret_val = get_next_x_line(fd, &line)) > 0)
	{
		alt_values = ft_strsplit(line, ' ');
		if (alt_values == NULL)
			ft_exit(MALLOC_ERR);
		line_extract(points, alt_values, fdf);
		fdf->map_height += 1;
		free_str(alt_values);
	}
	order_list()
}