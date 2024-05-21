/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:54:18 by dmdemirk          #+#    #+#             */
/*   Updated: 2024/05/21 15:15:46 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	error_exit(char *reason);
void	check_args(int argc, char **argv, t_data *data);
void	img_pix_put(t_image *data, int x, int y, int color);

void	error_exit(char *reason)
{
	perror(reason);
	exit (EXIT_FAILURE);
}

void	check_args(int argc, char **argv, t_data *data)
{
	if (argc != 2 || argv[1] == NULL)
	{
		free(data);
		error_exit("Usage: ./fdf <filename>");
	}
}

void	img_pix_put(t_image *img, int x, int y, int color)
{
	char	*destination;

	destination = img->addr + (y * img->line_length + \
			x * (img->bits_per_pixel / 8));
	*(unsigned int *)destination = color;
}
