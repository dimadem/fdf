/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:52:54 by dmdemirk          #+#    #+#             */
/*   Updated: 2024/05/21 15:51:40 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_handle(int key, t_data *data);
int		is_key(int key);

int	is_key(int key)
{
	return (key == XK_Escape || key == XK_Up || key == XK_Down
		|| key == XK_Left || key == XK_Right || key == XK_bracketright
		|| key == XK_bracketleft || key == XK_equal || key == XK_minus
		|| key == XK_space || key == XK_Return || key == XK_Tab
		|| key == XK_a || key == XK_s || key == XK_d
		|| key == XK_q || key == XK_w || key == XK_e
		|| key == XK_1 || key == XK_2 || key == XK_3);
}

int	key_handle(int key, t_data *data)
{
	if (is_key(key))
	{
		basic_actions(key, data);
		rotation_actions(key, data);
		translation_actions(key, data);
		projection_variants(key, data);
		draw(data);
	}
	return (0);
}
