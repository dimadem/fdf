/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:08:59 by dmdemirk          #+#    #+#             */
/*   Updated: 2024/05/21 16:16:56 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	window_center(t_point *p1, t_point *p2, t_params *params);
void	obj_center(t_obj *obj);

void	window_center(t_point *p1, t_point *p2, t_params *params)
{
	p1->x += params->window_center_x;
	p2->x += params->window_center_x;
	p1->y += params->window_center_y;
	p2->y += params->window_center_y;
}

void	calculate_sums(t_obj *obj, double *sum_x, double *sum_y, double *sum_z)
{
	int	i;
	int	j;

	*sum_x = 0.0;
	*sum_y = 0.0;
	*sum_z = 0.0;
	i = 0;
	while (i < obj->height)
	{
		j = 0;
		while (j < obj->width)
		{
			*sum_x += obj->map[i][j].x;
			*sum_y += obj->map[i][j].y;
			*sum_z += obj->map[i][j].z;
			j++;
		}
		i++;
	}
}

void	center_object(t_obj *obj, double sum_x, double sum_y, double sum_z)
{
	int		i;
	int		j;
	double	center_x;
	double	center_y;
	double	center_z;

	center_x = sum_x / (obj->width * obj->height);
	center_y = sum_y / (obj->width * obj->height);
	center_z = sum_z / (obj->width * obj->height);
	i = 0;
	while (i < obj->height)
	{
		j = 0;
		while (j < obj->width)
		{
			obj->map[i][j].x -= center_x;
			obj->map[i][j].y -= center_y;
			obj->map[i][j].z -= center_z;
			j++;
		}
		i++;
	}
}

void	obj_center(t_obj *obj)
{
	double	sum_x;
	double	sum_y;
	double	sum_z;

	calculate_sums(obj, &sum_x, &sum_y, &sum_z);
	center_object(obj, sum_x, sum_y, sum_z);
}
