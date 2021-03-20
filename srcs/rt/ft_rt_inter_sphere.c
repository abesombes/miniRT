/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt_inter_sphere.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:15:20 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/20 12:15:28 by abesombe         ###   ########.fr       */
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