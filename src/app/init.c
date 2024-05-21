/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:55:30 by dmdemirk          #+#    #+#             */
/*   Updated: 2024/05/21 14:01:32 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	init(t_data *data, char **argv)
{
	data->params.window_center_x = WINDOW_WIDTH / 2;
	data->params.window_center_y = WINDOW_HEIGHT / 2;
	data->params.xy_scale = 20;
	data->params.z_scale = 1;
	data->params.angle = 0.577;
	data->params.rotation_x = 0;
	data->params.rotation_y = 0;
	data->params.rotation_z = 0;
	data->params.projection = 2;
	data->params.animation = 0;
	data->mlx = mlx_init();
	data->obj = read_map(argv[1]);
	data->win = mlx_new_window(data->mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT, "fdf");
	data->img.img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
}
