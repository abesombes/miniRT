/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cylidr_pln_sphr_sqr_triang.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:24:20 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/11 17:02:46 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_parse.h"
#include "../../includes/ft_olst.h"

int	ft_parse_cylinder(char *line, t_scene *sc, int err_code, int *obj_id)
{
	double	bounds[2] = {-1.0, 1.0};
	t_vector *vec = NULL;
	t_olst	*new_obj = NULL;

	err_code = 0;
	if (!(new_obj = ft_olst_pushback_obj(&sc->olst, 'y', obj_id)))
		err_code = 12;
	printf("\n\n--------------------\n");
	printf("------CYLINDER------\n");
	printf("--------------------\n");
	vec = &new_obj->obj.cylinder.u;
	ft_get_xyz(&line, &vec, 0, &err_code);
	if (err_code)
		return (err_code == -6 ? -16: err_code); 
	vec = &new_obj->obj.cylinder.v;
	ft_get_xyz(&line, &vec, bounds, &err_code);
	if (err_code)
		return (err_code == -6 ? -10: err_code); 
	ft_move_to_next_data(&line);
	new_obj->obj.cylinder.radius = ft_atoif(&line, &err_code);	
	if (new_obj->obj.cylinder.radius < 0 || !err_code)
		return (-12);
	ft_move_to_next_data(&line);
	new_obj->obj.cylinder.height = ft_atoif(&line, &err_code);
	if (new_obj->obj.cylinder.height < 0 || !err_code)
		return (-15);
	ft_get_rgb(&line, new_obj, &err_code);
	return (err_code ? err_code : 0);
}

int	ft_parse_plane(char *line, t_scene *sc, int *obj_id)
{
	int		err_code;
	t_olst	*new_obj = NULL;
	t_vector *vec = NULL;
	double	bounds[2] = {-1.0, 1.0};

	err_code = 0;
	if (!(new_obj = ft_olst_pushback_obj(&sc->olst, 'p', obj_id)))
		err_code = 12;
	vec = &new_obj->obj.plane.u;
	printf("\n\n--------------------\n");
	printf("------PLANE------\n");
	printf("--------------------\n");
	ft_get_xyz(&line, &vec, 0, &err_code);
	ft_display_vec(vec);
	if (err_code)
		return (err_code);
	vec = &new_obj->obj.plane.v;
	ft_get_xyz(&line, &vec, bounds, &err_code);
	if (err_code)
		return (err_code == -6 ? -10: err_code); 
	ft_display_vec(vec);
	ft_get_rgb(&line, new_obj, &err_code);
	ft_display_vec(&new_obj->obj.rgb);
	return (err_code ? err_code : 0);
}

int	ft_parse_sphere(char *line, t_scene *sc, int *obj_id)
{
	int		err_code;
	t_olst	*new_obj = NULL;
	t_vector *vec = NULL;

	err_code = 0;
	if (!(new_obj = ft_olst_pushback_obj(&sc->olst, 's', obj_id)))
		err_code = 12;
	vec = &new_obj->obj.sp.origin;
	printf("\n\n--------------------\n");
	printf("------SPHERE------\n");
	printf("--------------------\n");
	ft_get_xyz(&line, &vec, 0, &err_code);
	if (err_code)
		return (err_code);
	ft_display_vec(vec); 
	ft_move_to_next_data(&line);
	new_obj->obj.sp.radius = ft_atoif(&line, &err_code);
	printf("\nradius: %f", new_obj->obj.sp.radius);
	if (new_obj->obj.sp.radius < 0 || !err_code)
		return (-12);
	ft_get_rgb(&line, new_obj, &err_code);
	ft_display_vec(&new_obj->obj.rgb);
	return (err_code ? err_code : 0);
}

int	ft_parse_square(char *line, t_scene *sc, int *obj_id)
{
	int		err_code;
	t_olst	*new_obj = NULL;
	t_vector *vec = NULL;
	double	bounds[2] = {-1.0, 1.0};

	err_code = 0;
	if (!(new_obj = ft_olst_pushback_obj(&sc->olst, 'q', obj_id)))
		err_code = 12;
	printf("\n\n--------------------\n");
	printf("------SQUARE------\n");
	printf("--------------------\n");
	vec = &new_obj->obj.square.u;
	ft_get_xyz(&line, &vec, 0, &err_code);
	ft_display_vec(vec);
	if (err_code)
		return (err_code); 
	vec = &new_obj->obj.square.v;
	ft_get_xyz(&line, &vec, bounds, &err_code);
	ft_display_vec(vec);
	if (err_code)
		return (err_code == -6 ? -10: err_code);
	ft_move_to_next_data(&line);
	new_obj->obj.square.l = ft_atoif(&line, &err_code);
	if (new_obj->obj.square.l < 0 || !err_code)
		return (-14);
	ft_get_rgb(&line, new_obj, &err_code);
	ft_display_vec(&new_obj->obj.rgb);
	return (err_code ? err_code : 0);
}

int	ft_parse_triangle(char *line, t_scene *sc, int *obj_id)
{
	int		err_code;
	t_olst	*new_obj = NULL;
	t_vector *vec = NULL;

	err_code = 0;
	if (!(new_obj = ft_olst_pushback_obj(&sc->olst, 't', obj_id)))
		err_code = 12;
	vec = &new_obj->obj.tr.a;
	printf("\n\n--------------------\n");
	printf("------TRIANGLE------\n");
	printf("--------------------\n");
	ft_get_xyz(&line, &vec, 0, &err_code);
	if (err_code)
		return (err_code == -6 ? -16: err_code); 
	vec = &new_obj->obj.tr.b;
	ft_get_xyz(&line, &vec, 0, &err_code);
	if (err_code)
		return (err_code == -6 ? -16: err_code); 
	vec = &new_obj->obj.tr.c;
	ft_get_xyz(&line, &vec, 0, &err_code);
	if (err_code)
		return (err_code == -6 ? -16: err_code); 
	ft_get_rgb(&line, new_obj, &err_code);
	return (err_code ? err_code : 0);
}