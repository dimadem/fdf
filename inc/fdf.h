/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:43:48 by dmdemirk          #+#    #+#             */
/*   Updated: 2024/05/21 16:24:33 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include "libft.h"

/* window */
# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 768

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	int		color;
}				t_point;

typedef struct s_obj
{
	t_point	**map;
	int		width;
	int		height;
	int		color;
}				t_obj;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_params
{
	double	window_center_x;
	double	window_center_y;
	double	rotation_x;
	double	rotation_y;
	double	rotation_z;
	double	xy_scale;
	double	z_scale;
	double	angle;
	int		projection;
	int		animation;
}				t_params;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_image		img;
	t_obj		obj;
	t_params	params;
}				t_data;

/*  init    */
void	init(t_data *data, char **argv);

/*  render  */
void	render(t_data *data);
int		draw(t_data *data);

/*  key_handle  */
int		key_handle(int key, t_data *data);

/*  key_actions */
void	basic_actions(int key, t_data *data);
void	rotation_actions(int key, t_data *data);
void	translation_actions(int key, t_data *data);
void	projection_variants(int key, t_data *data);

/*  cleanup  */
int		cleanup(t_data *data);
void	free_2d_array(void **array, int len);

/*  utils   */
void	error_exit(char *reason);
void	check_args(int argc, char **argv, t_data *data);
void	img_pix_put(t_image *img, int x, int y, int color);
int		ft_atoi_base(const char *str, int str_base);

/*  draw_fdf_obj    */
int		fdf_obj(t_data *data);

/*  read_fdf_obj */
t_obj	read_map(char *path);

/*  fdf_utils   */
int		ft_word_n_count(char *str, char c);
int		ft_open(char *path);
double	ft_get_max_value(double a, double b);
double	ft_abs(double number);

/*  projection_utils    */
void	projection(t_point *p1, t_point *p2, t_params *params);

/*  interaction_utils   */
void	zoom(t_point *p1, t_point *p2, t_params *params);
void	rotation(t_point *p1, t_point *p2, t_params *params);

/*  param_utils */
void	window_center(t_point *p1, t_point *p2, t_params *params);
void	obj_center(t_obj *obj);

/*	ft_atoi_base	*/
int		ft_atoi_base(const char *str, int str_base);

#endif
