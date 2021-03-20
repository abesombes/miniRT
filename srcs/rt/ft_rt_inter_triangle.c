/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt_inter_triangle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:14:33 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/20 12:16:02 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_rt.h"
#include "../../includes/ft_maths.h"
#include "../../includes/ft_olst.h"

int		ft_rt_inter_ray_tr(t_ray *r, t_triangle *tr, t_inter *inter)
{
	t_vector cro;
	t_vector trd;
	
	ft_vec_s(&inter->u, &tr->b, &tr->a);
	ft_vec_s(&inter->v, &tr->c, &tr->a);
	ft_vec_cross(&inter->uxv, &inter->u, &inter->v);
	ft_vec_nv(&inter->n, &inter->uxv);
	
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