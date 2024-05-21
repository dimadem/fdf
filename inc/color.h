/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:47:06 by dmdemirk          #+#    #+#             */
/*   Updated: 2024/05/21 16:25:10 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct s_trgb
{
	int	t;
	int	r;
	int	g;
	int	b;
}		t_trgb;

/* basic */
# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00

/* custom */
# define CHARCOAL 0x36454F
# define GLAUCOUS 0x6082B6
# define PLATINUM 0xE5E4E2
# define NEONORANGE 0xFF5F1F
# define IRIS 0x5D3FD3

/*  color_utils */
int		trgb_to_hex(t_trgb color);
t_trgb	hex_to_trgb(int color);
int		add_shade(float distance, int color);
int		invert(int color);
int		lerp_color(int start_c, int end_c, float t);

#endif
