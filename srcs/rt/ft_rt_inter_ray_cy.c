/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt_inter_ray_cy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:43:04 by abesombe          #+#    #+#             */
/*   Updated: 2021/04/05 11:18:02 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_rt.h"
#include "../../includes/ft_maths.h"
#include "../../includes/ft_olst.h"

static int	ft_rt_calc_cy_normal(t_ray *r, t_cylinder *cy, t_inter *inter)
{
	t_vector tmp, center;
	
	(void)r;
	ft_vec_ms(&tmp, &cy->v, inter->dist2);
	ft_vec_a(&center, &cy->u, &tmp);
	ft_vec_s(&inter->n, &inter->p, &center);
	ft_vec_norm(&inter->n);
	//ft_vec_a(&inter->n, &inter->p, &inter->n);
	ft_vec_norm(&inter->n);
	if (ft_vec_mul(&inter->n, &r->dir) > 0)
		ft_vec_ms(&inter->n, &inter->n, -1.0);
	// ft_vec_ms(&tmp, &inter->n, 0.000001);
	// ft_vec_a(&inter->p, &inter->p, &tmp);
	return (1);
}

void	ft_rt_solve_cy(t_ray *r, t_cylinder *cy, t_inter *inter)
{
	t_vector rdxcd;
	t_vector roxcd;
	t_vector coxcd;
	
	ft_vec_cross(&rdxcd, &r->dir, &cy->v);
	ft_vec_cross(&roxcd, &r->orig, &cy->v);
	ft_vec_cross(&coxcd, &cy->u, &cy->v);
	ft_vec_set(&inter->p, 0, 0, 0);
	inter->a = ft_vec_mul(&rdxcd, &rdxcd);
	inter->b = 2.0 * ft_vec_mul(&rdxcd, &roxcd) - 2.0 * ft_vec_mul(&rdxcd, &coxcd); 
	inter->c = ft_vec_mul(&coxcd, &coxcd) + ft_vec_mul(&roxcd, &roxcd) - 2.0 * \
		ft_vec_mul(&roxcd, &coxcd) - pow(cy->radius, 2.);
	inter->delta = pow(inter->b, 2.) - 4.0 * inter->a * inter->c;
	if (inter->delta >= 0)
	{
	inter->t1 = (-inter->b - pow(inter->delta, 0.5))/ (2.0 * inter->a);
	inter->t2 = (-inter->b + pow(inter->delta, 0.5))/ (2.0 * inter->a);
	}
}

double ft_rt_calc_dist(t_vector *a, t_vector *b)
{
	return (pow(pow(a->x - b->x, 2.) + pow(a->y - b->y, 2.) + pow(a->z - b->z, 2.), 0.5));
}

void	ft_rt_calc_dist1_dist2(t_ray *r, t_cylinder *cy, t_inter *inter)
{
	ft_vec_ms(&inter->rdt, &r->dir, inter->t);
	ft_vec_a(&inter->p, &r->orig, &inter->rdt);
	inter->dist1 = ft_rt_calc_dist(&cy->u, &inter->p);
	if (pow(inter->dist1, 2.) - pow(cy->radius, 2.0) < 0 \
		&& pow(inter->dist1, 2.) - pow(cy->radius, 2.0) > -0.000001)
		inter->dist2 = 0;
	else
		inter->dist2 = pow(pow(inter->dist1, 2.) - pow(cy->radius, 2.0), 0.5);
}

int		ft_rt_inter_ray_cy(t_ray *r, t_cylinder *cy, t_inter *inter)
{
	ft_rt_solve_cy(r, cy, inter);	
	if (inter->delta < 0)
		return (0);
	inter->t = inter->t1;
	if (inter->t1 < 0.000001)
		inter->t = inter->t2;
	else if (inter->t1 >= 0.000001)
	{
		ft_rt_calc_dist1_dist2(r, cy, inter);	
		if (inter->dist2 > cy->height / 2.0)
			inter->t = inter->t2;
		else
			return (ft_rt_calc_cy_normal(r, cy, inter));
	}
	if (inter->t2 < 0.000001)
		return (0);
	else if (inter->t2 >= 0.000001)
	{
		ft_rt_calc_dist1_dist2(r, cy, inter);	
		if (inter->dist2 > cy->height / 2.0)
			return (0);
		else
			return (ft_rt_calc_cy_normal(r, cy, inter));
	}
	return (0);
}