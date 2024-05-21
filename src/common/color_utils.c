/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:06:17 by dmdemirk          #+#    #+#             */
/*   Updated: 2024/05/21 13:59:04 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "color.h"

int		trgb_to_hex(t_trgb color);
t_trgb	hex_to_trgb(int color);
int		add_shade(float distance, int color);
int		invert(int color);
int		lerp_color(int start_c, int end_c, float t);

/*	the color int standart      */
/*	TRGB 0-255 => 0xTTRRGGBB    */	

int	trgb_to_hex(t_trgb color)
{
	return (color.t << 24 | color.r << 16 | color.g << 8 | color.b);
}

t_trgb	hex_to_trgb(int color)
{
	t_trgb	result;

	result.t = (color >> 24) & 0xFF;
	result.r = (color >> 16) & 0xFF;
	result.g = (color >> 8) & 0xFF;
	result.b = color & 0xFF;
	return (result);
}

int	add_shade(float distance, int color)
{
	t_trgb	result;
	int		shade_color;

	if (distance < 0)
		distance = 0;
	if (distance > 1)
		distance = 1;
	result = hex_to_trgb(color);
	result.r = (int)(result.r * (1 - distance));
	result.g = (int)(result.g * (1 - distance));
	result.b = (int)(result.b * (1 - distance));
	shade_color = trgb_to_hex(result);
	return (shade_color);
}

int	invert(int color)
{
	t_trgb	result;
	int		invert_color;

	result = hex_to_trgb(color);
	result.r = 255 - result.r;
	result.g = 255 - result.g;
	result.b = 255 - result.b;
	invert_color = trgb_to_hex(result);
	return (invert_color);
}

int	lerp_color(int start_c, int end_c, float t)
{
	t_trgb	start_color;
	t_trgb	end_color;
	t_trgb	result_color;
	int		lerp_result;

	start_color = hex_to_trgb(start_c);
	end_color = hex_to_trgb(end_c);
	result_color.r = start_color.r + (end_color.r - start_color.r) * t;
	result_color.g = start_color.g + (end_color.g - start_color.g) * t;
	result_color.b = start_color.b + (end_color.b - start_color.b) * t;
	lerp_result = trgb_to_hex(result_color);
	return (lerp_result);
}
