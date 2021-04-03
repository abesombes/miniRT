/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt_inter_ray_cy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:43:04 by abesombe          #+#    #+#             */
/*   Updated: 2021/04/03 23:27:23 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_rt.h"
#include "../../includes/ft_maths.h"
#include "../../includes/ft_olst.h"

/*
int 	ft_rt_inter_ray_cy(t_ray *r, t_cylinder *cy, t_inter *inter)
{
	t_vector    ori_to_cent;
    t_vector    dir;
    t_vector    tmp_vec;
    t_vector    ocdir;
	t_vector	center, tmp;
	double 		a, b, c, t0, t1, dist1, dist2, delta;

    ft_vec_s(&ori_to_cent, &r->orig, &cy->u);
    ft_vec_ms(&tmp_vec, &cy->v, ft_vec_mul(&r->dir, &cy->v));
    ft_vec_s(&dir, &r->dir, &tmp_vec);
    ft_vec_ms(&tmp_vec, &cy->v, ft_vec_mul(&ori_to_cent, &cy->v));
	ft_vec_s(&ocdir, &ori_to_cent, &tmp_vec);
    a = ft_vec_sqnorm(&dir);
    b = 2 * ft_vec_mul(&dir, &ocdir);
  	c = ft_vec_sqnorm(&ocdir) - pow(cy->radius * 2, 2);
    delta = pow(b, 2) - (4 * a * c);
	if (delta < 0)
		return (0);
	t0 = (-b - pow(delta, 0.5))/ (2.0 * a);
	t1 = (-b + pow(delta, 0.5))/ (2.0 * a);
	inter->t = t0;
	if (t0 <= 0.0001)
		inter->t = t1;
	if (t1 <= 0.0001)
		return (0);
	ft_vec_ms(&inter->rdt, &r->dir, inter->t);
	ft_vec_a(&inter->p, &r->orig, &inter->rdt);
	ft_vec_set(&inter->n, 0.0, 1.0, 0);
	dist1 = 0.0;
	dist2 = 0.0;
	dist1 = pow(cy->u.x - inter->p.x, 2.) + pow(cy->u.y - inter->p.y, 2.) + pow(cy->u.z - inter->p.z, 2.);
	if (pow(cy->radius, 2.0) >= dist1)
		dist2 = pow(pow(cy->radius, 2.0) - dist1, 0.5);
	if (dist2 > cy->height / 2.0)
		return (0);
	ft_vec_ms(&tmp, &cy->v, dist2);
	ft_vec_a(&center, &cy->u, &tmp);
	ft_vec_s(&inter->n, &inter->p, &center);
	ft_vec_a(&inter->n, &inter->p, &inter->n);
	ft_vec_norm(&inter->n);
	return (1);
}
*/

/* FOR ANY CYLINDER ORIENTATION */

static int	ft_rt_calc_cy_normal(t_ray *r, t_cylinder *cy, t_inter *inter)
{
	t_vector tmp, center;
	
	(void)r;
	ft_vec_ms(&tmp, &cy->v, inter->dist2);
	ft_vec_a(&center, &cy->u, &tmp);
	ft_vec_s(&inter->n, &inter->p, &center);
	ft_vec_norm(&inter->n);
	ft_vec_a(&inter->n, &inter->p, &inter->n);
	if (ft_vec_mul(&inter->n, &r->dir) > 0)
		ft_vec_ms(&inter->n, &inter->n, -1.0);
	// ft_vec_ms(&tmp, &inter->n, 0.000001);
	// ft_vec_a(&inter->p, &inter->p, &tmp);
	return (1);
}

void	ft_rt_calc_dist1_dist2(t_ray *r, t_cylinder *cy, t_inter *inter)
{
	ft_vec_ms(&inter->rdt, &r->dir, inter->t);
	ft_vec_a(&inter->p, &r->orig, &inter->rdt);
	inter->dist1 = pow(pow(cy->u.x - inter->p.x, 2.) + pow(cy->u.y - inter->p.y, 2.) + pow(cy->u.z - inter->p.z, 2.), 0.5);
	inter->dist2 = pow(pow(inter->dist1, 2.) - pow(cy->radius, 2.0), 0.5);
}

int		ft_rt_inter_ray_cy(t_ray *r, t_cylinder *cy, t_inter *inter)
{
	double a, b, c, t0, t1, delta;
	t_vector rdxcd, roxcd, coxcd;
		
	ft_vec_cross(&rdxcd, &r->dir, &cy->v);
	ft_vec_cross(&roxcd, &r->orig, &cy->v);
	ft_vec_cross(&coxcd, &cy->u, &cy->v);
	ft_vec_set(&inter->p, 0, 0, 0);
	a = ft_vec_mul(&rdxcd, &rdxcd);
	b = 2.0 * ft_vec_mul(&rdxcd, &roxcd) - 2.0 * ft_vec_mul(&rdxcd, &coxcd); 
	c = ft_vec_mul(&coxcd, &coxcd) + ft_vec_mul(&roxcd, &roxcd) - 2.0 * ft_vec_mul(&roxcd, &coxcd) - pow(cy->radius, 2.);
	delta = pow(b, 2.) - 4.0 * a * c;
	if (delta < 0)
		return (0);
	t0 = (-b - pow(delta, 0.5))/ (2.0 * a);
	t1 = (-b + pow(delta, 0.5))/ (2.0 * a);
	inter->t = t0;
	if (t0 < 0.000001)
		inter->t = t1;
	else if (t0 >= 0.000001)
	{
		ft_rt_calc_dist1_dist2(r, cy, inter);	
		if (inter->dist2 > cy->height / 2.0)
			inter->t = t1;
		else
			return (ft_rt_calc_cy_normal(r, cy, inter));
	}
	if (t1 < 0.000001)
		return (0);
	else if (t1 >= 0.000001)
	{
		ft_rt_calc_dist1_dist2(r, cy, inter);	
		if (inter->dist2 > cy->height / 2.0)
			return (0);
		else
			return (ft_rt_calc_cy_normal(r, cy, inter));
	}
	return (0);
}