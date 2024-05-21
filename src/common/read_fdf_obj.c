/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fdf_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:49:20 by dmdemirk          #+#    #+#             */
/*   Updated: 2024/05/21 15:20:18 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "color.h"

t_obj	read_map(char *path);
t_point	**points_alloc(int width, int height);
int		get_width(char *path);
int		get_height(char *path);
void	get_point(char *line, t_point **matrix, int y);
void	get_color(char *line, t_point **matrix, int y);

t_obj	read_map(char *path)
{
	t_obj	obj;
	int		fd;
	char	*line;
	int		y;

	y = 0;
	obj.width = get_width(path);
	obj.height = get_height(path);
	obj.map = points_alloc(obj.width, obj.height);
	fd = ft_open(path);
	line = ft_get_next_line(fd);
	while (line != (void *)0)
	{
		get_point(line, obj.map, y++);
		free(line);
		line = ft_get_next_line(fd);
	}
	close(fd);
	obj_center(&obj);
	return (obj);
}

t_point	**points_alloc(int width, int height)
{
	t_point	**map;
	int		i;

	i = 0;
	map = (t_point **)malloc(sizeof(t_point *) * (height + 1));
	if (map == NULL)
		return (NULL);
	while (i < height)
	{
		map[i] = (t_point *)malloc(sizeof(t_point) * (width + 1));
		if (map[i] == NULL)
		{
			free_2d_array((void **)map, i);
			return (NULL);
		}
		++i;
	}
	map[height] = (void *)0;
	return (map);
}

int	get_width(char *path)
{
	int		width;
	int		fd;
	char	*line;

	fd = ft_open(path);
	width = 0;
	line = ft_get_next_line(fd);
	width = ft_word_n_count(line, ' ');
	free(line);
	close(fd);
	return (width);
}

int	get_height(char *path)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = ft_open(path);
	line = ft_get_next_line(fd);
	while (line != (void *)0)
	{
		++height;
		free(line);
		line = ft_get_next_line(fd);
	}
	return (height);
}

void	get_point(char *line, t_point **matrix, int y)
{
	char	**points;
	int		x;

	x = 0;
	points = ft_split(line, ' ');
	while (points[x] != (void *)0)
	{
		matrix[y][x].x = (double)x;
		matrix[y][x].y = (double)y;
		matrix[y][x].z = (double)ft_atoi(points[x]);
		if (ft_strchr(points[x], ','))
			matrix[y][x].color = ft_atoi_base(
					(ft_strchr(points[x], ',')) + 3, 16);
		else
			matrix[y][x].color = GLAUCOUS;
		x++;
	}
	free_2d_array((void **)points, x);
}
