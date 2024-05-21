/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:09:05 by dmdemirk          #+#    #+#             */
/*   Updated: 2024/05/21 15:56:19 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	two_d_projection(t_point *p1, t_point *p2);
void	isometric_projection(t_point *p, double angle);
void	cabinet_projection(t_point *p1, t_point *p2, double angle);
void	projection(t_point *p1, t_point *p2, t_params *params);

void	two_d_projection(t_point *p1, t_point *p2)
{
	p1->z = 0;
	p2->z = 0;
}

void	isometric_projection(t_point *p, double angle)
{
	double	x;
	double	y;
	double	z;

	x = p->x;
	y = p->y;
	z = p->z;
	p->x = (x - y) * cos(angle);
	p->y = (x + y) * sin(angle) - z;
}

void	cabinet_projection(t_point *p1, t_point *p2, double angle)
{
	p1->x = p1->x + 0.5 * p1->z * cos(angle);
	p1->y = p1->y + 0.5 * p1->z * sin(angle);
	p2->x = p2->x + 0.5 * p2->z * cos(angle);
	p2->y = p2->y + 0.5 * p2->z * sin(angle);
}

void	projection(t_point *p1, t_point *p2, t_params *params)
{
	if (params->projection == 1)
		two_d_projection(p1, p2);
	else if (params->projection == 2)
	{
		isometric_projection(p1, params->angle);
		isometric_projection(p2, params->angle);
	}
	else if (params->projection == 3)
		cabinet_projection(p1, p2, params->angle);
}
