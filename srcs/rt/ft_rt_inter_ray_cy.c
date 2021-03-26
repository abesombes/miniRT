/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt_inter_ray_cy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:43:04 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/26 16:58:29 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_rt.h"
#include "../../includes/ft_maths.h"
#include "../../includes/ft_olst.h"

int		ft_rt_inter_ray_cy(t_ray *r, t_cylinder *cy, t_inter *inter)
{

	inter->denom = ft_vec_mul(&sq->v, &r->dir);
	if (fabs(inter->denom) > 1E-6)
	{
		ft_vec_s(&inter->polo, &sq->u, &r->orig);
		inter->t = ft_vec_mul(&inter->polo, &sq->v) / inter->denom;
 		ft_vec_ms(&inter->trd, &r->dir, inter->t);
		ft_vec_a(&inter->p, &r->orig, &inter->trd);
        inter->n = sq->v;
        ps = ft_vec_mul(&r->dir, &inter->n);
        if (fabs(ps) == 1)
            ft_vec_ms(&inter->n, &inter->n, -1.0);
		if (inter->t >= 0)
		{ 
			if (fabs(inter->p.x - sq->u.x) > (sq->l / 2) \
				|| fabs((inter->p.y - sq->u.y)) > (sq->l / 2) \
					|| fabs((inter->p.z - sq->u.z)) > (sq->l / 2))
				return (0);
            // printf("\nIntersection dans le square");
			return (1);
		}
		return (0);
	}
	return (0);
}

t_v3		get_cylinder_normal(t_v3 point, t_cylinder cylinder)
{
	t_v3 ctp;
	t_v3 normal;

	ctp = substract(point, cylinder.p);
	normal = substract(ctp, v3_multiply(cylinder.normal,
										dot_product(cylinder.normal, ctp)));
	normalize_vector(&normal);
	return (normal);
}

void		check_t(double *t, t_cylinder cylinder, t_ray ray)
{
	t_v3 q;
	t_v3 p2;

	p2 = v3_add(cylinder.p, v3_multiply(cylinder.normal, cylinder.height));
	q = v3_add(ray.origin, v3_multiply(ray.direction, *t));
	if (dot_product(cylinder.normal, substract(q, cylinder.p)) <= 0)
		*t = -1;
	if (dot_product(cylinder.normal, substract(q, p2)) >= 0)
		*t = -1;
}

int			cyl_get_roots(double *t0, double *t1, t_cylinder cylinder,
								t_ray ray)
{
	t_v3	a_sqrt;
	t_v3	right;
	double	a;
	double	b;
	double	c;

	a_sqrt = substract(ray.direction,
								v3_multiply(cylinder.normal,
								dot_product(ray.direction, cylinder.normal)));
	a = dot_product(a_sqrt, a_sqrt);
	right = substract(substract(ray.origin, cylinder.p),
						v3_multiply(cylinder.normal,
							dot_product(substract(ray.origin, cylinder.p),
							cylinder.normal)));
	b = 2 * dot_product(a_sqrt, right);
	c = dot_product(right, right) - (cylinder.radius * cylinder.radius);
	if (!solve_quadratic(new_qparams(a, b, c), t0, t1))
		return (0);
	return (1);
}

int			intersect_cylinder(t_ray ray, t_cylinder cylinder, double *t)
{
	double t0;
	double t1;

	if (!cyl_get_roots(&t0, &t1, cylinder, ray))
		return (0);
	if (t0 > 0)
		check_t(&t0, cylinder, ray);
	if (t1 > 0)
		check_t(&t1, cylinder, ray);
	if (t0 < 0 && t1 < 0)
		return (0);
	if (t1 < t0)
		if (t1 > 0)
			*t = t1;
		else
			*t = t0;
	else
	{
		if (t0 > 0)
			*t = t0;
		else
			*t = t1;
	}
	return (1);
}