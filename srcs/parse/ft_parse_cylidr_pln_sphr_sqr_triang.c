/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cylidr_pln_sphr_sqr_triang.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:24:20 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/08 14:47:19 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_parse.h"
/*
int	ft_analyze_cylinder(char *line, t_scene *sc)
{
	int		err_code;
	double	bounds[2] = {-1.0, 1.0};

	err_code = 0;
	if (!(ft_add_new_obj_to_olist(sc)))
		err_code = 12
	ft_get_xyz(&line, &sc->olst->cylinder->u, 0, &err_code);
	if (err_code)
		return (err_code == -6 ? -16: err_code); 
	if (!sc->olst->cylinder->u)
		return (12);
	ft_get_xyz(&line, &sc->olst->cylinder->v, bounds, &err_code);
	if (err_code)
		return (err_code == -6 ? -10: err_code); 
	if (!sc->olst->cylinder->u)
		return (12);
	ft_move_to_next_data(&line);
	sc->olst->cylinder->radius = ft_atoif(&line, &err_code);
	if (sc->olst->cylinder->radius < 0 || !err_code)
		return (-12);
	ft_move_to_next_data(&line);
	sc->olst->cylinder->height = ft_atoif(&line, &err_code);
	if (sc->olst->cylinder->height < 0 || !err_code)
		return (-15);
	ft_get_rgb(&line, sc, &err_code);
	if (err_code)
		return (err_code); 
	if (!sc->rgb)
		return (12);
	return (0);
}

int	ft_analyze_plane(char *line, t_scene *sc)
{
	int		err_code;
	t_scene	*new_sc;
	double	bounds[2] = {-1.0, 1.0};

	err_code = 0;
	if (!(new_sc = ft_init_plane(sc)))
		err_code = 12;
	ft_get_xyz(&line, &new_sc->plane->u, 0, &err_code);
	if (err_code)
		return (err_code); 
	if (!new_sc->plane->u)
		return (12);
	ft_get_xyz(&line, &new_sc->plane->v, bounds, &err_code);
	if (err_code)
		return (err_code == -6 ? -10: err_code); 
	if (!new_sc->plane->v)
		return (12);
	ft_get_rgb(&line, sc, &err_code);
	if (err_code)
		return (err_code); 
	if (!sc->rgb)
		return (12);
	return (0);
}

int	ft_analyze_sphere(char *line, t_scene *sc)
{
	int		err_code;
	t_scene	*new_sc;

	err_code = 0;
	if (!(new_sc = ft_init_sphere(sc)))
		err_code = 12;
	ft_get_xyz(&line, &new_sc->sp->origin, 0, &err_code);
	if (err_code)
		return (err_code); 
	if (!new_sc->sp->origin)
		return (12);
	ft_move_to_next_data(&line);
	new_sc->sp->radius = ft_atoif(&line, &err_code);
	if (new_sc->sp->radius < 0 || !err_code)
		return (-12);
	ft_get_rgb(&line, sc, &err_code);
	if (err_code)
		return (err_code); 
	if (!sc->rgb)
		return (12);
	return (0);
}

int	ft_analyze_square(char *line, t_scene *sc)
{
	int		err_code;
	t_scene	*new_sc;
	double	bounds[2] = {-1.0, 1.0};

	err_code = 0;
	if (!(new_sc = ft_init_square(sc)))
		err_code = 12;
	ft_get_xyz(&line, &new_sc->square->u, 0, &err_code);
	if (err_code)
		return (err_code); 
	if (!new_sc->square->u)
		return (12);
	ft_get_xyz(&line, &new_sc->square->v, bounds, &err_code);
	if (err_code)
		return (err_code == -6 ? -10: err_code); 
	if (!new_sc->square->v)
		return (12);
	ft_move_to_next_data(&line);
	new_sc->square->l = ft_atoif(&line, &err_code);
	if (new_sc->square->l < 0 || !err_code)
		return (-14);
	ft_get_rgb(&line, sc, &err_code);
	if (err_code)
		return (err_code); 
	if (!sc->rgb)
		return (12);
	return (0);
}

int	ft_analyze_triangle(char *line, t_scene *sc)
{
	int		err_code;
	t_scene	*new_sc;

	err_code = 0;
	if (!(new_sc = ft_init_triangle(sc)))
		err_code = 12;
	ft_get_xyz(&line, &new_sc->tr->a, 0, &err_code);
	if (err_code)
		return (err_code == -6 ? -16: err_code); 
	if (!new_sc->tr->a)
		return (12);
	ft_get_xyz(&line, &new_sc->tr->b, 0, &err_code);
	if (err_code)
		return (err_code == -6 ? -16: err_code); 
	if (!new_sc->tr->b)
		return (12);
	ft_get_xyz(&line, &new_sc->tr->c, 0, &err_code);
	if (err_code)
		return (err_code == -6 ? -16: err_code); 
	if (!new_sc->tr->c)
		return (12);
	ft_get_rgb(&line, sc, &err_code);
	if (err_code)
		return (err_code); 
	if (!sc->rgb)
		return (12);
	return (0);
}
*/