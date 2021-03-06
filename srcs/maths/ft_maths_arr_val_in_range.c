/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths_arr_val_in_range.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 22:49:56 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/11 14:40:26 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_maths.h"

int	ft_maths_arr_val_in_range(double *arr, double min_b, double max_b)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (arr[i] > max_b || arr[i] < min_b)
		return (0);
		i++;
	}
	return (1);
}

int	ft_within_range(double nb, double min_b, double max_b)
{
	if (nb > max_b || nb < min_b)
		return (0);
	return (1);
}