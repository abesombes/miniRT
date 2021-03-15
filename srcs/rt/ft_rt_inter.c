/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt_inter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:19:31 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/15 12:32:40 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_rt.h"
#include "../../includes/ft_maths.h"
#include "../../includes/ft_olst.h"

int		ft_rt_inter(t_ray *r, t_sphere *sp, t_inter *inter)
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

int ft_rt_inter_all(t_scene *sc, t_inter *inter)
{
	while (sc->k < inter->count_sp)
	{
		if (!(inter->sp_obj = ft_olst_return_next_obj(&sc->olst, \
			inter->cur_s_id, 's')))
			break ;
		ft_rt_select_next_sp(inter);
		if ((inter->has_junc = ft_rt_inter(&sc->ray, &inter->cur_s, inter)))
		{
				if (inter->t < inter->min_t)
					ft_rt_save_min_t_pix_int(sc, inter);
		}
		sc->k++;
	}
	if(inter->min_t != 1E10)
		return (1);
	return (0);
}

int ft_rt_inter_rl_all(t_scene *sc, t_inter *inter)
{
	while (sc->k < inter->count_sp)
	{
		if (!(inter->sp_obj = ft_olst_return_next_obj(&sc->olst, \
			inter->cur_s_id, 's')))
			break ;
		ft_rt_select_next_sp(inter);
		if ((inter->has_junc = ft_rt_inter(&sc->ray_light, &inter->cur_s, inter)))
		{
				if (inter->t < inter->min_t)
					ft_rt_save_min_t_pix_int(sc, inter);
		}
		sc->k++;
	}
	if(inter->min_t != 1E10)
		return (1);
	return (0);
}