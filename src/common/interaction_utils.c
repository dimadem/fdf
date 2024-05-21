/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:06:27 by dmdemirk          #+#    #+#             */
/*   Updated: 2024/05/21 13:58:46 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(t_point *p1, t_point *p2, t_params *params);
void	rotate_x(t_point *point, double angle);
void	rotate_y(t_point *point, double angle);
void	rotate_z(t_point *point, double angle);
void	rotation(t_point *p1, t_point *p2, t_params *params);

void	zoom(t_point *p1, t_point *p2, t_params *params)
{
	p1->x *= params->xy_scale;
	p2->x *= params->xy_scale;
	p1->y *= params->xy_scale;
	p2->y *= params->xy_scale;
	p1->z *= params->z_scale;
	p2->z *= params->z_scale;
}

void	rotate_x(t_point *point, double angle)
{
	double	y;
	double	z;

	y = point->y;
	z = point->z;
	point->y = y * cos(angle) - z * sin(angle);
	point->z = y * sin(angle) + z * cos(angle);
}

void	rotate_y(t_point *point, double angle)
{
	double	x;
	double	z;

	x = point->x;
	z = point->z;
	point->x = x * cos(angle) + z * sin(angle);
	point->z = -x * sin(angle) + z * cos(angle);
}

void	rotate_z(t_point *point, double angle)
{
	double	x;
	double	y;

	x = point->x;
	y = point->y;
	point->x = x * cos(angle) - y * sin(angle);
	point->y = x * sin(angle) + y * cos(angle);
}

void	rotation(t_point *p1, t_point *p2, t_params *params)
{
	rotate_x(p1, params->rotation_x);
	rotate_x(p2, params->rotation_x);
	rotate_y(p1, params->rotation_y);
	rotate_y(p2, params->rotation_y);
	rotate_z(p1, params->rotation_z);
	rotate_z(p2, params->rotation_z);
}
