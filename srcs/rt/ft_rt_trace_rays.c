/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt_trace_rays.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:21:08 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/12 16:27:12 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_rt.h"
#include "../../includes/ft_render.h"
#include "../../includes/ft_maths.h"
#include "../includes/ft_olst.h"

void ft_rt_trace_rays(t_scene *sc, int *has_inter)
{
	int i;
	int j;
	t_cam cur_cam;
	t_light light;
	t_sphere sp;
	
	j = 0;
	cur_cam = (ft_olst_return_obj_by_id(&sc->olst, sc->cur_cam))->cam;
	light = (ft_olst_return_first_obj_by_type(&sc->olst, 'l'))->light;
	sp = (ft_olst_return_first_obj_by_type(&sc->olst, 'l'))->sphere;
	while (j < sc->res_h)
	{
		i = 0;
		while (i < sc->res_w)
		{
			ft_vec_set(&sc->ray.dir, i - sc->res_w / 2, j - sc->res_h / 2, -sc->res_w / (2 * tan(cur_cam.fov / 2)));
			ft_vec_norm(&sc->ray.dir);
			ft_vec_cpy(&sc->ray.orig, &cur_cam.pos);
			ft_ray_set(&sc->ray, &sc->ray.orig, &sc->ray.dir);
			ft_vec_set(&sc->pix_int, 0., 0., 0.);
			*has_inter = ft_inter(ray, sc->olst->sp);
			int_pix = 0;
			if (has_inter)
			{
				sc->pix_int
			}
			//sc->pix_int = *ft_vec_add(&sc->pix_int, ft_get_color(&sc->ray, &sc, &light, 5));
			sc->pix_color = ((int)round(fmin(fmax(pow(sc->pix_int.x, 0.4545), 0), 255)) + 0) << 16 | ((int)round(fmin(fmax(pow(sc->pix_int.y, 0.4545), 0), 255)) + 0) << 8 | ((int)round(fmin(fmax(pow(sc->pix_int.z, 0.4545), 0), 255)));
			my_mlx_pixel_put(sc, i, sc->res_h - j - 1, sc->pix_color);
			i++;
		}
		j++;
	}
}