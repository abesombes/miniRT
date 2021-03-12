/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt_inter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:19:31 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/12 20:49:04 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_rt.h"
#include "../../includes/ft_maths.h"

int     ft_rt_inter(t_ray *r, t_sphere *sp, t_inter *inter)
{
	inter->a = 1;
	inter->b = 2 * ft_vec_mul(&r->dir, ft_vec_sub(&r->orig, &sp->orig));
	inter->c = ft_vec_sqnorm(ft_vec_sub(&r->orig, &sp->orig)) - pow(sp->radius, 2);
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
	inter->p = *ft_vec_add(&r->orig, ft_vec_mul_scal(&r->dir, inter->t));
	inter->n = *ft_vec_normvec(ft_vec_sub(&inter->p, &sp->orig));
	return (1);
}