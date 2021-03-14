/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt_trace_rays.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:21:08 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/14 21:01:02 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_rt.h"
#include "../../includes/ft_render.h"
#include "../../includes/ft_maths.h"
#include "../includes/ft_olst.h"

void ft_rt_select_cur_cam_light(t_scene *sc, t_inter *inter)
{
	sc->j = -1;
	inter->cur_c = (ft_olst_return_obj_by_id(&sc->olst, sc->cur_cam))->cam;
	inter->cur_l = ft_olst_return_first_obj_by_type(&sc->olst, 'l')->light;
}

void ft_rt_init_ray(t_scene *sc, t_inter *inter)
{
	inter->min_t = 1E10;
	inter->cur_s_id = ft_olst_return_first_obj_by_type(&sc->olst, 's')->id - 1;
	ft_vec_set(&sc->ray.dir, sc->i - sc->res_w / 2, sc->j - sc->res_h / 2, \
		-sc->res_w / (2 * tan(inter->cur_c.fov / 200)));
	ft_vec_norm(&sc->ray.dir);
	ft_vec_cpy(&sc->ray.orig, &inter->cur_c.pos);
	ft_ray_set(&sc->ray, &sc->ray.orig, &sc->ray.dir);
	ft_vec_nul(&sc->pix_int);
	sc->k = 0;
}

void ft_rt_select_next_sp(t_inter *inter)
{
	inter->cur_s = inter->sp_obj->sp;
	inter->cur_s_id = inter->sp_obj->id;
	ft_init_inter(inter);
}

void ft_rt_save_min_t_pix_int(t_scene *sc, t_inter *inter)
{
	inter->min_t = inter->t;
	sc->pix_int = *ft_vec_mul_scal(&inter->sp_obj->rgb, 20000000 * \
		inter->cur_l.intst * fmax(0, ft_vec_mul(ft_vec_normvec(\
			ft_vec_sub(&inter->cur_l.pos, &inter->p)), &inter->n) \
				/ ft_vec_sqnorm(ft_vec_sub(&inter->cur_l.pos, &inter->p))));
}

void ft_rt_calc_pix_color(t_scene *sc)
{
		sc->pix_color = ((int)round(fmin(fmax(pow(sc->pix_int.x, 0.4545), 0), \
			255)) + 0) << 16 | ((int)round(fmin(fmax(pow(sc->pix_int.y, 0.4545), \
				0), 255)) + 0) << 8 | ((int)round(fmin(fmax(pow(sc->pix_int.z, \
					0.4545), 0), 255)));
}

void ft_rt_trace_rays(t_scene *sc, t_inter *inter)
{
	//  t_inter inter_l;
	
	ft_rt_select_cur_cam_light(sc, inter);
	while (++sc->j < sc->res_h)
	{
		sc->i = -1;
		while (++sc->i < sc->res_w)
		{
			ft_rt_init_ray(sc, inter);
			while (sc->k < inter->count_sp)
			{
				if (!(inter->sp_obj = ft_olst_return_next_obj(&sc->olst, \
					inter->cur_s_id, 's')))
					break ;
				ft_rt_select_next_sp(inter);
				if ((inter->has_junc = ft_rt_inter(&sc->ray, &inter->cur_s, inter)))
				{
				/*	ft_vec_add(&sc->ray_light.orig, &inter->p, ft_vec_mul_scal(&inter->n, 0.01)));
					ft_vec_cpy(&sc->ray_light.dir, ft_vec_normvec(ft_vec_sub(&inter->cur_l.pos, &inter->p)));
					inter_l.has_junc = ft_rt_inter(&sc->ray_light, &inter->cur_s, &inter_l);
					inter_l.sqr_dlight = ft_vec_sqnorm(ft_vec_sub(&inter->cur_l.pos, &inter->p));
					if (inter_l.has_junc && pow(inter_l.t, 2) < inter_l.sqr_dlight)
						ft_vec_nul(&sc->pix_int);*/
					if (inter->t < inter->min_t)
						ft_rt_save_min_t_pix_int(sc, inter);
				}
				sc->k++;
			}
			ft_rt_calc_pix_color(sc);
			ft_render_pixel_put(sc, sc->i, sc->res_h - sc->j - 1, sc->pix_color);
		}
	}
	mlx_put_image_to_window(sc->mlx, sc->mlx_win, sc->img, 0, 0);
}