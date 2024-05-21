/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:45:49 by dmdemirk          #+#    #+#             */
/*   Updated: 2024/05/21 14:00:13 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "color.h"

int		fdf_obj(t_data *data);
void	draw_fdf_line(t_data *data, t_point p1, t_point p2);
int		in_viewport(t_point *point);
void	update_params(t_point *p1, t_point *p2, t_params *params);

int	fdf_obj(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->obj.height)
	{
		x = 0;
		while (x < data->obj.width)
		{
			if (x < data->obj.width - 1)
				draw_fdf_line(data, data->obj.map[y][x],
					data->obj.map[y][x + 1]);
			if (y < data->obj.height - 1)
				draw_fdf_line(data, data->obj.map[y][x],
					data->obj.map[y + 1][x]);
			++x;
		}
		++y;
	}
	return (0);
}

void	draw_fdf_line(t_data *data, t_point p1, t_point p2)
{
	double	x_step;
	double	y_step;
	double	max;
	int		color;

	update_params(&p1, &p2, &data->params);
	x_step = p2.x - p1.x;
	y_step = p2.y - p1.y;
	max = ft_get_max_value(ft_abs(x_step), ft_abs(y_step));
	x_step /= max;
	y_step /= max;
	color = lerp_color(p1.color, p2.color, 0.5);
	while ((int)(p1.x - p2.x) || (int)(p1.y - p2.y))
	{
		if (in_viewport(&p1))
			img_pix_put(&data->img, p1.x, p1.y, color);
		p1.x += x_step;
		p1.y += y_step;
	}
}

int	in_viewport(t_point *point)
{
	if (point->x < 0 || point->x >= WINDOW_WIDTH
		|| point->y < 0 || point->y >= WINDOW_HEIGHT)
		return (0);
	return (1);
}

void	update_params(t_point *p1, t_point *p2, t_params *params)
{
	zoom(p1, p2, params);
	rotation(p1, p2, params);
	projection(p1, p2, params);
	window_center(p1, p2, params);
}
