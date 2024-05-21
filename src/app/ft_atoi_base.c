/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:13:36 by dmdemirk          #+#    #+#             */
/*   Updated: 2024/05/21 15:20:59 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_fit_a(const char *str, int i, int str_base);
int	is_fit_ca(const char *str, int i, int str_base);
int	ft_atoi_base(const char *str, int str_base);

int	is_fit_a(const char *str, int i, int str_base)
{
	return (str_base > 10 && str[i] >= 'a' && str[i] <= (str_base - 11) + 'a');
}

int	is_fit_ca(const char *str, int i, int str_base)
{
	return (str_base > 10 && str[i] >= 'A' && str[i] <= (str_base - 11) + 'A');
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	n;
	int	s;

	i = 0;
	s = 1;
	n = 0;
	if (str[i] == '-')
	{
		s *= (-1);
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= (str_base - 1) + '0')
			n = n * str_base + str[i] - '0';
		else if (is_fit_ca(str, i, str_base))
			n = n * str_base + str[i] - 55;
		else if (is_fit_a(str, i, str_base))
			n = n * str_base + str[i] - 87;
		else
			break ;
		i++;
	}
	return (n * s);
}
