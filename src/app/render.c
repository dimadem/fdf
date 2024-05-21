/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:54:43 by dmdemirk          #+#    #+#             */
/*   Updated: 2024/05/21 14:51:10 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		draw(t_data *data);
void	render(t_data *data);
void	update(t_data *data);
void	animation(t_data *data);

void	render(t_data *data)
{
	mlx_loop_hook(data->mlx, &draw, data);
	mlx_key_hook(data->win, &key_handle, data);
	mlx_hook(data->win, 17, 0, &cleanup, data);
	mlx_loop(data->mlx);
}

void	update(t_data *data)
{
	if (data->img.img)
	{
		mlx_destroy_image(data->mlx, data->img.img);
		data->img.img = NULL;
		data->img.addr = NULL;
	}
	data->img.img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

int	draw(t_data *data)
{
	update(data);
	fdf_obj(data);
	animation(data);
	return (0);
}

void	animation(t_data *data)
{
	if (data->params.animation)
	{
		data->params.rotation_x += 0.0009;
		data->params.z_scale = cos(data->params.rotation_x) * 6;
	}
}
