/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_res_cam_alight_light.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:04:36 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/09 16:39:43 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_parse.h"
#include "../../includes/ft_olst.h"

int	ft_parse_alight(char *line, t_scene *sc)
{
	int nb_digits;
	int err_code;
	t_olst *new_obj = NULL;

	nb_digits = 0;
	err_code = 0;
	if (!(new_obj = ft_olst_pushback_obj(&sc->olst)))
		err_code = 12;
	ft_move_to_next_data(&line);
	if ((new_obj->obj.alight.alight_int = ft_atoif(&line, &nb_digits)) < 0 || !nb_digits)
		return (-9);
	printf("\nalight_int: %f", new_obj->obj.alight.alight_int);
	ft_get_rgb(&line, new_obj, &err_code);
	ft_display_vec(&new_obj->obj.rgb);
	if (err_code)
		return (err_code); 
	return (0);
}
/*
int	ft_parse_cam(char *line, t_scene *sc)
{
	int		err_code;
	t_scene	*new_sc;
	double	bounds[2] = {-1.0, 1.0};

	err_code = 0;
	if (!(new_obj = ft_olst_pushback_obj(&sc->olst)))
		err_code = 12;
	ft_get_xyz(&line, &sc->olst->obj.cam.pos, 0, &err_code);
	if (err_code)
		return (err_code); 
	if (!new_sc->cam->pos)
		return (12);
	ft_get_xyz(&line, &sc->olst->obj.cam.orient, bounds, &err_code);
	if (err_code)
		return (err_code == -6 ? -10: err_code); 
	if (!new_sc->cam->orient)
		return (12);
	ft_move_to_next_data(&line);
	new_sc->cam->fov = ft_atoif(&line, &err_code);
	if (!ft_within_range(new_sc->cam->fov, 0, 180) || !err_code)
		return (-13);
	return (0);
}

int	ft_analyze_light(char *line, t_scene *sc)
{
	int		err_code;
	t_scene	*new_sc;

	err_code = 0;
	if (!(new_sc = ft_init_light(scene)))
		err_code = 12;
	ft_get_xyz(&line, &new_sc->light->light_pos, 0, &err_code);
	if (err_code)
		return (err_code); 
	if (!new_sc->light->light_pos)
		return (12);
	ft_move_to_next_data(&line);
	new_sc->light->light_int = ft_atoif(&line, &err_code);
	if (!ft_within_range(new_sc->light->light_int, 0, 1.0) || !err_code)
		return (-11);
	ft_get_rgb(&line, scene, &err_code);
	if (err_code)
		return (err_code); 
	if (!scene->rgb)
		return (12);
	return (0);
}*/

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