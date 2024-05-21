/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:49:53 by dmdemirk          #+#    #+#             */
/*   Updated: 2024/05/21 15:52:03 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	basic_actions(int key, t_data *data);
void	rotation_actions(int key, t_data *data);
void	translation_actions(int key, t_data *data);
void	projection_variants(int key, t_data *data);

void	basic_actions(int key, t_data *data)
{
	if (key == XK_Escape)
		cleanup(data);
	else if (key == XK_Tab)
		data->params.animation = !data->params.animation;
	else if (key == XK_space)
	{
		data->params.window_center_x = WINDOW_WIDTH / 2;
		data->params.window_center_y = WINDOW_HEIGHT / 2;
		data->params.rotation_x = 0;
		data->params.rotation_y = 0;
		data->params.rotation_z = 0;
		data->params.xy_scale = 20;
		data->params.z_scale = 1;
	}
}

void	rotation_actions(int key, t_data *data)
{
	if (key == XK_s)
		data->params.rotation_x -= data->params.xy_scale / 100;
	else if (key == XK_w)
		data->params.rotation_x += data->params.xy_scale / 100;
	else if (key == XK_a)
		data->params.rotation_y -= data->params.xy_scale / 100;
	else if (key == XK_d)
		data->params.rotation_y += data->params.xy_scale / 100;
	else if (key == XK_q)
		data->params.rotation_z += data->params.xy_scale / 100;
	else if (key == XK_e)
		data->params.rotation_z -= data->params.xy_scale / 100;
}

void	translation_actions(int key, t_data *data)
{
	if (key == XK_Up)
		data->params.window_center_y -= data->params.xy_scale * 10;
	else if (key == XK_Down)
		data->params.window_center_y += data->params.xy_scale * 10;
	else if (key == XK_Left)
		data->params.window_center_x -= data->params.xy_scale * 10;
	else if (key == XK_Right)
		data->params.window_center_x += data->params.xy_scale * 10;
	else if (key == XK_bracketright)
		data->params.z_scale += 1;
	else if (key == XK_bracketleft)
		data->params.z_scale -= 1;
	else if (key == XK_equal)
		data->params.xy_scale += 1;
	else if (key == XK_minus)
		data->params.xy_scale -= 1;
}

void	projection_variants(int key, t_data *data)
{
	if (key == XK_1)
	{
		data->params.projection = 1;
		data->params.rotation_x = 0;
		data->params.rotation_y = 0;
		data->params.rotation_z = 0;
	}
	else if (key == XK_2)
	{
		data->params.projection = 2;
		data->params.angle = 0.577;
		data->params.rotation_x = 0;
		data->params.rotation_y = 0;
		data->params.rotation_z = 0;
	}
	else if (key == XK_3)
	{
		data->params.projection = 3;
		data->params.angle = 0.5;
		data->params.rotation_x = 1;
		data->params.rotation_y = 0;
		data->params.rotation_z = 0;
	}
}
