/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_get_xyz_rgb.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:16:29 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/20 10:58:39 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_parse.h"
#include "../../includes/ft_maths.h"

void ft_get_rgb(char **line, t_olst *olst, int *err_code)
{
	double rgb[3] = {-1, -1, -1};
	int nb_digits;

	*err_code = 0;
	ft_move_to_next_data(line);
	//printf("\nline: [%s]", *line);
	nb_digits = 0;
	rgb[0] = ft_atoi(line, &nb_digits);
	if (!nb_digits)
		*err_code = -8;
	if (**line == ',')
		(*line)++;
	rgb[1] = ft_atoi(line, &nb_digits);
	if (!nb_digits)
		*err_code = -8;
	if (**line == ',')
		(*line)++;
	rgb[2] = ft_atoi(line, &nb_digits);
	ft_move_to_next_data(line);
	if (**line || !nb_digits || !ft_maths_arr_val_in_range(rgb, 0.0, 255.0))
		*err_code = -8;
	olst->rgb = *ft_vec(rgb[0], rgb[1], rgb[2]);
}

void ft_get_xyz(char **line, t_vector *vec, double *bounds, int *err_code)
{
	double xyz[3] = {-1, -1, -1};
	int nb_digits;

	*err_code = 0;
	nb_digits = 0;
	ft_move_to_next_data(line);
	xyz[0] = ft_atoif(line, &nb_digits);
	if (!nb_digits)
		*err_code = -6;
	if (**line == ',')
		(*line)++;
	xyz[1] = ft_atoif(line, &nb_digits);
	if (!nb_digits)
		*err_code = -6;
	if (**line == ',')
		(*line)++;
	xyz[2] = ft_atoif(line, &nb_digits);
	if (bounds && !ft_maths_arr_val_in_range(xyz, bounds[0], bounds[1]))
		*err_code = -6;
	if (!nb_digits)
		*err_code = -6;
	ft_vec_set(vec, xyz[0], xyz[1], xyz[2]);;
}