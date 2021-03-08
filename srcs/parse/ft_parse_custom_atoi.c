/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_custom_atoi.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:18:01 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/08 14:59:32 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_parse.h"

int		ft_atoi(char **str, int *nb_digits)
{
	long long	res;
	long long	sign;

	*nb_digits = 0;
	res = 0;
	sign = 1;
	if (**str == '-')
	{
		sign = -1;
		(*str)++;
	}
	while (**str >= '0' && **str <= '9')
	{
		res = res * 10 + **str - 48;
		(*str)++;
		(*nb_digits)++;
	}
	return ((int)(res * sign));
}

double	ft_atoif(char **str, int *nb_digits)
{
	double	sign;
	double	int_part;
	double	dec_part;
	double	nb_dec;

	nb_dec = 0;
	*nb_digits = 0;
	int_part = 0;
	dec_part = 0;
	sign = (**str == '-' ? -1 : 1);
	(*str) += (**str == '-' ? 1: 0);
	int_part = ft_atoi(str, nb_digits);
	if (**str == '.')
		(*str)++;
	while (**str >= '0' && **str <= '9')
	{
		dec_part = dec_part * 10 + **str - 48;
		(*str)++;
		nb_dec++;
		(*nb_digits)++;
	}
	return (((int_part + dec_part / pow(10, nb_dec)) * sign));
}
