/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 16:06:39 by mminkjan       #+#    #+#                */
/*   Updated: 2019/12/10 17:26:33 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <fcntl.h>
# include <math.h>

# include <stdio.h> // delete later!

# define USAGE_ERR	"usage error: input valid map\n"
# define FILE_ERR	"error: opening file\n"
# define MALLOC_ERR	"error: malloc\n"
# define INVAL_ERR	"error: invalid map\n"

# define W 13
# define S 1
# define E 14
# define Q 12
# define D 2
# define A 0
# define PLUS 24
# define MIN 27
# define ESC 53
# define DEL 51
# define C 8
# define M 46
# define ONE 18
# define TWO 19
# define THREE 20
# define FOUR 21

# define ONE_START 0x000084
# define ONE_END 0x1cb5e0
# define TWO_START 0x304352
# define TWO_END 0xd7d2cc
# define THREE_START 0xdc2424
# define THREE_END 0x4a569d
# define FOUR_START 0xe55d87
# define FOUR_END 0x5fc3e4

# define PI 3.14159265359

# define WIDTH	1900
# define HEIGHT 1200

typedef	struct			s_line
{
	double				delta_x;
	double				delta_y;
	double				delta_x_abs;
	double				delta_y_abs;
	double				error_x;
	double				error_y;
	double				delta_alt;

}						t_line;

typedef struct			s_events
{
	int					reset;
	double				extend;
	int					color_set;
	int					smooth_exit;
	int					rot_x;
	int					rot_y;
	int					rot_z;
	int					mouse_press;
	double				move_x;
	double				move_y;
	double				zoom;
}						t_events;

typedef struct			s_color
{
	int					start;
	int					end;
}						t_color;

typedef struct			s_points
{
	double				alt;
	double				x;
	double				y;
	double				z;
	int					color;
	struct s_points		*next_x;
	struct s_points		*next_y;

}						t_points;

typedef struct			s_fdf
{
	void				*mlx_ptr;
	void				*window_ptr;
	void				*image_ptr;
	char				*map_name;
	char				*addr_str;
	int					bpp;
	int					size_line;
	double				max_x;
	double				max_y;
	double				map_width;
	double				map_height;
	int					tile_size;
	double				alt_max;
	double				alt_min;
	double				alt_mode;
	t_points			*points;
	t_color				color;
	t_events			events;
}						t_fdf;

int						main(int argc, char **argv);
void					mlx_setup(t_fdf *fdf);
void					import_map(t_fdf *fdf, t_points **points, char **argv);
void					calculate_points(t_fdf *fdf, t_points *points);
int						map_manager(t_fdf *fdf);
void					draw_line(t_fdf *fdf, t_points start, t_points end);
int						get_color(t_fdf *fdf, double altitude);

int						key_press(int key_code, t_fdf *fdf);
int						mouse_release(int button, int x, int y, t_fdf *fdf);
int						mouse_press(int button, int x, int y, t_fdf *fdf);
int						mouse_move(int x, int y, t_fdf *fdf);

t_fdf					*fdf_init(void);
void					order_list(t_fdf *fdf, t_points *points);
void					swap_points(t_points *a, t_points *b);

void					event_rot_x(int pos, t_points *alt_point);
void					event_rot_y(int pos, t_points *alt_point);
void					event_rot_z(int pos, t_points *alt_point);
void					iso_projection(t_points *alt_point);

void					event_zoom(double zoom, t_points *alt_point);
void					event_extend(double extend, t_points *alt_point);
void					event_reset(t_events *event);

void					print_interface(t_fdf *fdf);

#endif
