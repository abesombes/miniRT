/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt_trace_rays.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:21:08 by abesombe          #+#    #+#             */
/*   Updated: 2021/04/09 15:33:16 by abesombe         ###   ########.fr       */
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
	if (sc->change_cam)
		inter->cur_c = (ft_olst_return_obj_by_id(&sc->olst, sc->cur_cam))->cam;
	else
		inter->cur_c = ft_olst_return_first_obj_by_type(&sc->olst, 'm')->cam;
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

void	ft_rt_switch_to_next_light(int k, t_inter *inter, t_scene *sc)
{
		if (k == 0)
		{
			inter->cur_l = ft_olst_return_first_obj_by_type(&sc->olst, 'l')->light;
			inter->cur_l_id = ft_olst_return_first_obj_by_type(&sc->olst, 'l')->id;
			inter->cur_l_rgb = ft_olst_return_first_obj_by_type(&sc->olst, 'l')->rgb;
		}
		else if (k > 0)
		{
		inter->cur_l_id = ft_olst_return_next_obj_id_by_type(&sc->olst, inter->cur_l_id, 'l');
		inter->cur_l_rgb = (ft_olst_return_obj_by_id(&sc->olst, inter->cur_l_id))->rgb;
		inter->cur_l = (ft_olst_return_obj_by_id(&sc->olst, inter->cur_l_id))->light;
		}
}

void 	ft_rt_get_light_color_sum(t_scene *sc, t_inter *inter)
{
	t_inter inter_l;
	int k;
	t_vector tmp;
	double alpha;
	
	k = 0;
	ft_vec_nul(&sc->light_color);
	ft_vec_ms(&inter->alpha_n, &inter->min_n, 0.00001);
	ft_vec_a(&sc->ray_light.orig, &inter->min_p, &inter->alpha_n);
//	ft_vec_norm(&sc->ray_light.orig);
	while (k < sc->count_lights)
	{
		ft_rt_switch_to_next_light(k, inter, sc);
		ft_vec_s(&inter->lpp, &inter->cur_l.pos, &inter->min_p);
		ft_vec_nv(&inter->norm_lpp, &inter->lpp);
		ft_vec_cpy(&sc->ray_light.dir, &inter->norm_lpp);
		ft_display_vec(&sc->ray_light.orig);
		ft_display_vec(&sc->ray_light.dir);
		ft_init_inter(&inter_l);
		inter_l.min_t = 1E10;
		printf("\nINTERSECTION RAYON LIGHT AVEC OBJETS DE LA SCENE?");
		inter_l.has_junc = ft_rt_inter_all(sc, &sc->ray_light, &inter_l, 0);
		inter_l.sqd_dlight = ft_vec_sqnorm(&inter->lpp);
		if (!((inter_l.has_junc && pow(inter_l.min_t, 2) < inter_l.sqd_dlight)))
		{
			alpha = 15000 * sqrt(inter->cur_l.intst) * fmax(0, ft_vec_mul(&sc->ray_light.dir, &inter->min_n) / inter_l.sqd_dlight);
			ft_vec_ms_clamp(&tmp, &inter->cur_l_rgb, alpha, 255);
			ft_vec_ac(&sc->light_color, &sc->light_color, &tmp);
		}
		else if (inter_l.has_junc)
			printf("\nINTERSECTION LUMIERE CONFIRMED [%f] [%f]", pow(inter_l.min_t, 2), inter_l.sqd_dlight);
		k++;
	}
	printf("\nLIGHT_COLOR: [%f, %f, %f]", sc->light_color.x, sc->light_color.y, sc->light_color.z);
}

void ft_rt_save_min_t_pix_int(t_scene *sc, t_inter *inter, int opt)
{
	ft_vec_cpy(&inter->min_p, &inter->p);
	ft_vec_cpy(&inter->min_n, &inter->n);
	inter->min_t = inter->t;
	if (opt == 1)
	{
		ft_rt_get_light_color_sum(sc, inter);
		ft_vec_mv(&sc->pix_int, &inter->cur_obj->rgb, &sc->light_color);
	}
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
	sc->j = -1;
	ft_rt_select_cur_cam_light(sc, inter);
	while (++sc->j < sc->res_h)
	{
		sc->i = -1;
		while (++sc->i < sc->res_w)
		{
			ft_rt_init_ray(sc, inter);
			ft_rt_cam_compute(sc, &inter->cur_c, &sc->ray);
			ft_vec_nul(&sc->pix_int);
			printf("\nINTERSECTION RAYON CAM AVEC OBJETS DE LA SCENE?");
			inter->has_junc = ft_rt_inter_all(sc, &sc->ray, inter, 1);
			ft_rt_calc_pix_color(sc);
			ft_render_pixel_put(sc, sc->i, sc->j, sc->pix_color);
		}
	}
	mlx_put_image_to_window(sc->mlx, sc->mlx_win, sc->img, 0, 0);
}