/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:51:56 by dmdemirk          #+#    #+#             */
/*   Updated: 2024/05/21 14:00:21 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int		ft_word_n_count(char *str, char c);
int		ft_open(char *path);
double	ft_get_max_value(double a, double b);
double	ft_abs(double number);

int	ft_word_n_count(char *str, char c)
{
	int	i;
	int	result;

	i = -1;
	result = 0;
	while (str[++i] != '\0')
	{
		if (i == 0 && str[i] != c)
			++result;
		if (i > 0 && str[i] != c && str[i - 1] == c)
			++result;
	}
	return (result);
}

int	ft_open(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_exit("open");
	return (fd);
}

double	ft_get_max_value(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}

double	ft_abs(double number)
{
	if (number < 0)
		return (-number);
	return (number);
}
