/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt_trace_rays.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:21:08 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/19 11:16:49 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_rt.h"
#include "../../includes/ft_render.h"
#include "../../includes/ft_maths.h"
#include "../includes/ft_olst.h"

void ft_display_inter(t_inter *inter)
{
	printf("\n---------------------------------------");
	printf("\n---------------------------------------");
	printf("\nhas_junc: [%i]", inter->has_junc);
	printf("\na: [%f]", inter->a);
	printf("\nb: [%f]", inter->b);
	printf("\nc: [%f]", inter->c);
	printf("\ndelta: [%f]", inter->delta);
	printf("\nt: [%f]", inter->t);
	printf("\nt1: [%f]", inter->t1);
	printf("\nt2: [%f]", inter->t2);
	printf("\nmin_t: [%f]", inter->min_t);
	printf("\nsqd_dlight: [%f]", inter->sqd_dlight);
}

void ft_rt_select_cur_cam_light(t_scene *sc, t_inter *inter)
{
	inter->cur_c = (ft_olst_return_obj_by_id(&sc->olst, sc->cur_cam))->cam;
	if (ft_olst_return_next_obj(&sc->olst, 0, 'l'))
		inter->cur_l = ft_olst_return_next_obj(&sc->olst, 0, 'l')->light;
//	inter->cur_l = ft_olst_return_first_obj_by_type(&sc->olst, 'l')->light;
}

void ft_rt_init_ray(t_scene *sc, t_inter *inter)
{
	ft_vec_set(&sc->ray.dir, sc->i - sc->res_w / 2, sc->j - sc->res_h / 2, \
			-sc->res_w / (2 * tan(inter->cur_c.fov / 200)));
	ft_vec_norm(&sc->ray.dir);
	ft_vec_cpy(&sc->ray.orig, &inter->cur_c.pos);
	ft_ray_set(&sc->ray, &sc->ray.orig, &sc->ray.dir);
}

void ft_rt_select_next_sp(t_inter *inter)
{
	inter->cur_s = inter->sp_obj->sp;
	inter->cur_s_id = inter->sp_obj->id;
	ft_init_inter(inter);
}

void ft_rt_save_min_t_pix_int(t_scene *sc, t_inter *inter, int opt)
{
	inter->min_t = inter->t;
	if (opt == 1)
	{
		ft_vec_ms(&sc->pix_int, &inter->cur_obj->rgb, 20000000 * \
			inter->cur_l.intst * fmax(0, ft_vec_mul(ft_vec_normvec(\
				ft_vec_sub(&inter->cur_l.pos, &inter->p)), &inter->n) \
					/ ft_vec_sqnorm(ft_vec_sub(&inter->cur_l.pos, &inter->p))));
	}
	ft_vec_cpy(&inter->min_p, &inter->p);
	ft_vec_cpy(&inter->min_n, &inter->n);
}

void	ft_rt_calc_alight(t_scene *sc)
{
	int i;
	t_olst	cur_al;
	double		cur_al_intst;
	t_vector	cur_al_light;
	
	i = 0;
	while (ft_olst_return_next_obj(&sc->olst, i, 'a'))
	{
		cur_al = *ft_olst_return_next_obj(&sc->olst, i, 'a');
		cur_al_intst = cur_al.alight.intst;
		ft_vec_ms(&cur_al_light, &cur_al.rgb, cur_al_intst);
		ft_vec_a(&sc->alight_sum, &sc->alight_sum, &cur_al_light);
		i++;
	}
}

void	ft_rt_calc_pix_color(t_scene *sc)
{
		sc->pix_color = ((int)round(fmin(fmax(pow(sc->pix_int.x + 5 * sc->alight_sum.x, 0.4545), 0), \
			255)) + 0) << 16 | ((int)round(fmin(fmax(pow(sc->pix_int.y + 5 * sc->alight_sum.y, 0.4545), \
				0), 255)) + 0) << 8 | ((int)round(fmin(fmax(pow(sc->pix_int.z + 5 * sc->alight_sum.z, \
					0.4545), 0), 255)));
}

void ft_rt_trace_rays(t_scene *sc, t_inter *inter)
{
	t_inter inter_l;
	
	sc->j = -1;
	ft_rt_select_cur_cam_light(sc, inter);
	ft_rt_calc_alight(sc);
	while (++sc->j < sc->res_h)
	{
		sc->i = -1;
		while (++sc->i < sc->res_w)
		{
			//inter->cur_s_id = ft_olst_return_first_obj_by_type(&sc->olst, 's')->id - 1;
			ft_rt_init_ray(sc, inter);
			ft_vec_nul(&sc->pix_int);
			inter->has_junc = ft_rt_inter_all(sc, &sc->ray, inter, 1);
			ft_vec_ms(&inter->alpha_n, &inter->min_n, 0.00001);
			ft_vec_a(&sc->ray_light.orig, &inter->min_p, &inter->alpha_n);
			ft_vec_s(&inter->lpp, &inter->cur_l.pos, &inter->min_p);
			ft_vec_nv(&inter->norm_lpp, &inter->lpp);
			ft_vec_cpy(&sc->ray_light.dir, &inter->norm_lpp);
			ft_init_inter(&inter_l);
			inter_l.min_t = 1E10;
			//inter_l.cur_s_id = ft_olst_return_first_obj_by_type(&sc->olst, 's')->id;
			inter_l.has_junc = ft_rt_inter_all(sc, &sc->ray_light, &inter_l, 0);
			inter_l.sqd_dlight = ft_vec_sqnorm(&inter->lpp);
			if ((inter_l.has_junc && pow(inter_l.min_t, 2) < inter_l.sqd_dlight))
				ft_vec_nul(&sc->pix_int);
			ft_rt_calc_pix_color(sc);
			ft_render_pixel_put(sc, sc->i, sc->res_h - sc->j - 1, sc->pix_color);
		}
	}
	mlx_put_image_to_window(sc->mlx, sc->mlx_win, sc->img, 0, 0);
}