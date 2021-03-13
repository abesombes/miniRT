/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt_trace_rays.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:21:08 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/13 23:05:13 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_rt.h"
#include "../../includes/ft_render.h"
#include "../../includes/ft_maths.h"
#include "../includes/ft_olst.h"

void ft_rt_trace_rays(t_scene *sc, t_inter *inter)
{
	int i;
	int j;
	t_cam cur_c;
	t_light cur_l;
	t_sphere cur_s;
	t_olst *sp_obj;
	
	j = 0;
	cur_c = (ft_olst_return_obj_by_id(&sc->olst, sc->cur_cam))->cam;
	cur_l = ft_olst_return_first_obj_by_type(&sc->olst, 'l')->light;
	sp_obj = ft_olst_return_first_obj_by_type(&sc->olst, 's');
	cur_s = (ft_olst_return_first_obj_by_type(&sc->olst, 's'))->sp;
	while (j < sc->res_h)
	{
		i = 0;
		while (i < sc->res_w)
		{
			ft_vec_set(&sc->ray.dir, i - sc->res_w / 2, j - sc->res_h / 2, -sc->res_w / (2 * tan(cur_c.fov / 2)));
			ft_vec_norm(&sc->ray.dir);
			ft_vec_cpy(&sc->ray.orig, &cur_c.pos);
			ft_ray_set(&sc->ray, &sc->ray.orig, &sc->ray.dir);
			ft_vec_set(&sc->pix_int, 0., 0., 0.);
			ft_init_inter(inter);
			printf("\n-------------------------------------------------------\n");
			printf("-------------------------------------------------------\n");
			printf("\n[%i, %i]", i, j);
			printf("\nNORMED RAY DIR:");
			ft_display_vec(&sc->ray.dir);
			inter->has_junc = ft_rt_inter(&sc->ray, &cur_s, inter);
			if (inter->has_junc)
			{
				printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
				printf("\nintersect @ [%i, %i]", i, sc->res_h - j - 1);
				sc->pix_int = *ft_vec_mul_scal(&sp_obj->rgb, 100000000 * cur_l.intst * fmax(0, ft_vec_mul(ft_vec_normvec(ft_vec_sub(&cur_l.pos, &inter->p)), &inter->n) / ft_vec_sqnorm(ft_vec_sub(&cur_l.pos, &inter->p))));
			}
			sc->pix_color = ((int)round(fmin(fmax(pow(sc->pix_int.x, 0.4545), 0), 255)) + 0) << 16 | ((int)round(fmin(fmax(pow(sc->pix_int.y, 0.4545), 0), 255)) + 0) << 8 | ((int)round(fmin(fmax(pow(sc->pix_int.z, 0.4545), 0), 255)));
			ft_render_pixel_put(sc, i, sc->res_h - j - 1, sc->pix_color);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(sc->mlx, sc->mlx_win, sc->img, 0, 0);
}