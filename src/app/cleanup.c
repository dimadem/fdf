/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:53:48 by dmdemirk          #+#    #+#             */
/*   Updated: 2024/05/21 14:00:56 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		cleanup(t_data *data);
void	free_2d_array(void **array, int len);
void	free_obj(t_obj obj);

int	cleanup(t_data *data)
{
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->obj.map)
		free_2d_array((void **)data->obj.map, data->obj.height);
	data->img.img = (void *)0;
	data->img.addr = (void *)0;
	data->win = (void *)0;
	data->mlx = (void *)0;
	data->obj.map = (void *)0;
	free(data);
	exit(0);
}

void	free_2d_array(void **array, int len)
{
	int	i;

	i = -1;
	while (++i < len)
	{
		free(array[i]);
		array[i] = (void *)0;
	}
	free(array);
}
