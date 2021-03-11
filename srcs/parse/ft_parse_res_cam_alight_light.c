/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_res_cam_alight_light.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:04:36 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/11 15:48:23 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_parse.h"
#include "../../includes/ft_olst.h"
#include "../../includes/ft_maths.h"

int	ft_parse_res(char *line, t_scene *sc)
{
	int nb_digits;

	nb_digits = 0;
	if (sc->res_w > 0 || sc->res_h > 0)
		return (-3);
	ft_move_to_next_data(&line);
	if ((sc->res_w = ft_atoi(&line, &nb_digits)) <= 0  || !nb_digits)
		return (-2);
	ft_move_to_next_data(&line);
	if ((sc->res_h = ft_atoi(&line, &nb_digits)) <= 0  || !nb_digits)
		return (-2);
	return (0);
}

int	ft_parse_cam(char *line, t_scene *sc)
{
	int		err_code;
	t_olst	*new_obj = NULL;
	t_vector *vec = NULL;
	double	bounds[2] = {-1.0, 1.0};

	err_code = 0;
	if (!(new_obj = ft_olst_pushback_obj(&sc->olst, 'm')))
		err_code = 12;
	vec = &new_obj->obj.cam.pos;
	ft_get_xyz(&line, &vec, 0, &err_code);
	if (err_code)
		return (err_code); 
	vec = &new_obj->obj.cam.orient;
	ft_get_xyz(&line, &vec, bounds, &err_code);
	if (err_code)
		return (err_code == -6 ? -10: err_code); 
	ft_move_to_next_data(&line);
	new_obj->obj.cam.fov = ft_atoif(&line, &err_code);
	if (!ft_within_range(new_obj->obj.cam.fov, 0, 180) || !err_code)
		return (-13);
	return (0);
}

int	ft_parse_alight(char *line, t_scene *sc)
{
	int nb_digits;
	int err_code;
	t_olst *new_obj = NULL;

	nb_digits = 0;
	err_code = 0;
	if (!(new_obj = ft_olst_pushback_obj(&sc->olst, 'a')))
		err_code = 12;
	ft_move_to_next_data(&line);
	if ((new_obj->obj.alight.alight_int = ft_atoif(&line, &nb_digits)) < 0 || !nb_digits)
		return (-9);
	ft_get_rgb(&line, new_obj, &err_code);
	return (err_code ? err_code : 0);
}

int	ft_parse_light(char *line, t_scene *sc)
{
	int		err_code;
	t_vector *vec = NULL;
	t_olst	*new_obj = NULL;

	err_code = 0;
	if (!(new_obj = ft_olst_pushback_obj(&sc->olst, 'l')))
		err_code = 12;
	printf("\nLIGHT: [%c]", new_obj->obj.obj_type);
	vec = &new_obj->obj.light.light_pos;
	ft_get_xyz(&line, &vec, 0, &err_code);
	if (err_code)
		return (err_code); 
	ft_move_to_next_data(&line);
	new_obj->obj.light.light_int = ft_atoif(&line, &err_code);
	if (!ft_within_range(new_obj->obj.light.light_int, 0, 1.0) || !err_code)
		return (-11);
	ft_get_rgb(&line, new_obj, &err_code);
	return (err_code ? err_code : 0);;
}