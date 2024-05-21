/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:00:27 by dmdemirk          #+#    #+#             */
/*   Updated: 2024/05/21 14:07:36 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_handle(int button, t_data *data);
int	is_button(int button);

int	is_button(int button)
{
	return (button == 1);
}

int	mouse_handle(int button, t_data *data)
{
	if (is_button(button))
	{
		draw(data);
	}
	return (0);
}
