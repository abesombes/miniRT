/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt_inter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:19:31 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/24 12:07:59 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_rt.h"
#include "../../includes/ft_maths.h"
#include "../../includes/ft_olst.h"

int		ft_rt_inter_ray_sp(t_ray *r, t_sphere *sp, t_inter *inter)
{
	inter->a = 1;
	ft_vec_s(&inter->romspo, &r->orig, &sp->orig); 
	inter->b = 2 * ft_vec_mul(&r->dir, &inter->romspo);
	inter->sqd_romspo = ft_vec_sqnorm(&inter->romspo);
	inter->c = inter->sqd_romspo - pow(sp->radius, 2);
	inter->delta = inter->b * inter->b - 4 * inter->a * inter->c;
	if (inter->delta < 0)
		return (0);
	inter->t1 = (-inter->b - sqrt(inter->delta))  / (2 * inter->a);
	inter->t2 = (-inter->b + sqrt(inter->delta))  / (2 * inter->a);
	if (inter->t2 < 0)
		return (0);
	if (inter->t1 > 0)
		inter->t = inter->t1;
	else
		inter->t = inter->t2;
	ft_vec_ms(&inter->rdt, &r->dir, inter->t);
	ft_vec_a(&inter->p, &r->orig, &inter->rdt);
	ft_vec_s(&inter->pspo, &inter->p, &sp->orig);
	ft_vec_nv(&inter->n, &inter->pspo);
	return (1);
}

int		ft_rt_inter_ray_tr(t_ray *r, t_triangle *tr, t_inter *inter)
{
	t_vector	cro;
	t_vector	trd;
	double		ps;

	ft_vec_s(&inter->u, &tr->b, &tr->a);
	ft_vec_s(&inter->v, &tr->c, &tr->a);
	ft_vec_cross(&inter->uxv, &inter->u, &inter->v);
	ft_vec_nv(&inter->n, &inter->uxv);
	ps = ft_vec_mul(&inter->n, &r->dir);
	if (ps > 0)
		ft_vec_ms(&inter->n, &inter->n, -1);
	ft_vec_s(&cro, &tr->c, &r->orig);
	inter->t = ft_vec_mul(&cro, &inter->n)/ft_vec_mul(&r->dir, &inter->n);
	if (inter->t < 0)
		return (0);
	ft_vec_ms(&trd, &r->dir, inter->t);
	ft_vec_a(&inter->p, &r->orig, &trd);
	ft_vec_s(&inter->w, &inter->p, &tr->a);
	inter->m11 = ft_vec_sqnorm(&inter->u);
	inter->m12 = ft_vec_mul(&inter->u, &inter->v);
	inter->m22 = ft_vec_sqnorm(&inter->v);
	inter->detm = inter->m11 * inter->m22 - inter->m12 * inter->m12;
	inter->b11 = ft_vec_mul(&inter->w, &inter->u);
	inter->b21 = ft_vec_mul(&inter->w, &inter->v);
	inter->detb = inter->b11 * inter->m22 - inter->b21 * inter->m12;
	inter->beta = inter->detb / inter->detm;
	inter->g12 = inter->b11;
	inter->g22 = inter->b21;
	inter->detg = inter->m11 * inter->g22 - inter->m12 * inter->g12;
	inter->gamma = inter->detg / inter->detm;
	inter->alpha = 1 - inter->beta - inter->gamma;
	if ((inter->alpha < 0 || inter->alpha > 1) || (inter->beta < 0 ||\
		 inter->beta > 1) || (inter->gamma < 0 || inter->gamma > 1))
		return (0);
	return (1);
}

int ft_rt_inter_all(t_scene *sc, t_ray *ray, t_inter *inter, int opt)
{	
	sc->k = 0;
	inter->min_t = 1E10;
	inter->cur_obj_id = 0;
	while (sc->k < sc->count_obj)
	{
		if (!(inter->cur_obj = ft_olst_return_next_obj_from_group(&sc->olst, inter->cur_obj_id, "st")))
			break ;
		inter->cur_obj_id = inter->cur_obj->id;
		if (inter->cur_obj->obj_type == 's')
		{
			inter->cur_s = inter->cur_obj->sp;
			inter->cur_s_id = inter->cur_obj->id;
			ft_init_inter(inter);
			if ((inter->has_junc = ft_rt_inter_ray_sp(ray, &inter->cur_s, inter)))
			{
				if (inter->t < inter->min_t)
					ft_rt_save_min_t_pix_int(sc, inter, opt);
			}
		}
		if (inter->cur_obj->obj_type == 't')
		{
			inter->cur_t = inter->cur_obj->tr;
			inter->cur_t_id = inter->cur_obj->id;
			ft_init_inter(inter);
			if ((inter->has_junc = ft_rt_inter_ray_tr(ray, &inter->cur_t, inter)))
			{
				if (inter->t < inter->min_t)
					ft_rt_save_min_t_pix_int(sc, inter, opt);
			}
		}
		sc->k++;
	}
	if(inter->min_t != 1E10)
		return (1);
	return (0);
}
