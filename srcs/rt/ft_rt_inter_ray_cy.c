/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt_inter_ray_cy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:43:04 by abesombe          #+#    #+#             */
/*   Updated: 2021/04/01 22:00:34 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_rt.h"
#include "../../includes/ft_maths.h"
#include "../../includes/ft_olst.h"

/* FOR ANY CYLINDER ORIENTATION */
/*
int		ft_rt_inter_ray_cy(t_ray *r, t_cylinder *cy, t_inter *inter)
{
	t_vector	rdv, rov;
	t_vector	rdvr2;
	double 		a, b, c, v2, d1, d2;
	
	ft_vec_cross(&rdv, &r->dir, &cy->v);
	ft_vec_cross(&rov, &r->orig, &cy->v);
	a = ft_vec_mul(&rdv, &rov);
	ft_vec_ms(&rdvr2, &rdv, pow(cy->radius, 2));
	b = ft_vec_mul(&rdv, &rdvr2);
	v2 = ft_vec_mul(&cy->v, &cy->v);
	c = pow(ft_vec_mul(&r->orig, &rdv), 2);
	c = c * v2;
	d1 = (a + pow(b - c, 0.5)) / (ft_vec_mul(&rdv, &rdv));
	d2 = (a - pow(b - c, 0.5)) / (ft_vec_mul(&rdv, &rdv)); 
	if (d1 < 0)
		return (0);
	if (d1 > 0)
		inter->t = d1;
	else
		inter->t = d2;
	// ft_vec_ms(&inter->rdt, &r->dir, inter->t);
	// ft_vec_s(&tmp, &inter->rdt, &cy->u);
	// ft_vec_mv(&inter->p, &r->orig, &inter->rdt);
	ft_vec_ms(&inter->rdt, &r->dir, inter->t);
	ft_vec_a(&inter->p, &r->orig, &inter->rdt);
//	ft_vec_s(&inter->pspo, &inter->p, &cy->u);
	ft_vec_set(&inter->n, 0, 0, 0.7);
	return (1);
}*/
/*
int		ft_rt_inter_ray_cy(t_ray *r, t_cylinder *cy, t_inter *inter)
{
	t_vector	rdv, rov;
	t_vector	rdvr2;
	t_vector	bu, tmp, tmp2;
	t_vector	cyvt;
	t_vector	drd;
	double 		a, b, c, v2, d1, d2;
	
	ft_vec_s(&bu, &cy->u, &r->orig);
	ft_vec_mv(&rdv, &r->dir, &cy->v);
	ft_vec_mv(&rov, &bu, &cy->v);
	a = ft_vec_mul(&rdv, &rov);
	ft_vec_ms(&rdvr2, &rdv, pow(cy->radius, 2));
	b = ft_vec_mul(&rdv, &rdvr2);
	v2 = ft_vec_mul(&cy->v, &cy->v);
	c = pow(ft_vec_mul(&bu, &rdv), 2);
	c = c * v2;
	d1 = (a + pow(b - c, 0.5)) / (ft_vec_mul(&rdv, &rdv));
	d2 = (a - pow(b - c, 0.5)) / (ft_vec_mul(&rdv, &rdv)); 
	if (d1 < 0)
		return (0);
	if (d1 > 0)
	{
		ft_vec_ms(&drd, &r->dir, d1);
		ft_vec_s(&tmp2, &drd, &bu);
		inter->t = ft_vec_mul(&cy->v, &tmp2);
	}
	else
	{
		ft_vec_ms(&drd, &r->dir, d2);
		ft_vec_s(&tmp2, &drd, &bu);
		inter->t = ft_vec_mul(&cy->v, &tmp2);
	}
	ft_vec_ms(&inter->rdt, &r->dir, inter->t);
	ft_vec_s(&tmp, &inter->rdt, &bu);
	ft_vec_ms(&cyvt, &cy->v, inter->t);
	ft_vec_s(&inter->n, &tmp, &cyvt);
	ft_vec_norm(&inter->n);
	ft_vec_ms(&inter->rdt, &r->dir, inter->t);
	ft_vec_a(&inter->p, &r->orig, &inter->rdt);
	return (1);
}
*/
/*
// CYLINDRE SUR AXE X
int		ft_rt_inter_ray_cy(t_ray *r, t_cylinder *cy, t_inter *inter)
{
	double a, b, c, det;
	a = pow(r->dir.y, 2) + pow(r->dir.z, 2);
	b = 2 * (r->dir.y * r->orig.y + r->dir.z * r->orig.z);
	c = pow(r->orig.y, 2) + pow(r->orig.z, 2) - pow(cy->radius, 2);
	det = pow(b, 2) - 4 * a * c;
	if (det < 0)
		return (0);
	a = 2 * a;
	det = sqrt(det);
	inter->t1 = (-b - det) / a;
	inter->t2 = (-b + det) / a;
	if (inter->t2 < 0)
		return (0);
	if (inter->t1 > 0)
		inter->t = inter->t1;
	else
		inter->t = inter->t2;
	ft_vec_ms(&inter->rdt, &r->dir, inter->t);
	ft_vec_a(&inter->p, &r->orig, &inter->rdt);
	ft_vec_s(&inter->pspo, &inter->p, &cy->u);
	ft_vec_set(&inter->n, 0, 0, 1);
//	ft_vec_s(&inter->n, &inter->p, &inter-> 
	return (1);
}
*/

// CYLINDRE SUR AXE Y
int		ft_rt_inter_ray_cy(t_ray *r, t_cylinder *cy, t_inter *inter)
{
	t_vector 	cross;
	t_vector	cross2;
	t_vector	center;
	t_vector 	tmp;
	// t_vector	hv;
	// t_vector	cohv;
	// t_vector	copo;
	t_vector	sub;
	double 		a, b, c, det, dist1, dist2;
	double ps;

	ps = ft_vec_mul(&r->dir, &cy->v);
	if (fabs(ps) == 1)
		ft_vec_set(&cross, 1, 0, 1);
	else 
		ft_vec_cross(&cross, &r->dir, &cy->v);
	ft_vec_s(&sub, &r->orig, &cy->u);
	ft_vec_cross(&cross2, &sub, &cy->v);
	a = ft_vec_mul(&cross, &cross);
	b = 2 * ft_vec_mul(&cross, &cross2);
	c = ft_vec_mul(&cross2, &cross2) - (pow(cy->radius / 2, 2)
		* ft_vec_mul(&cy->v, &cy->v));
	det = pow(b, 2) - (4 * a * c);
	if (det < 0)
		return (0);
	a = 2 * a;
	det = sqrt(det);
	inter->t1 = (-b - det) / a;
	inter->t2 = (-b + det) / a;
	// ft_vec_ms(&inter->trd, &r->dir, inter->t2);
	// ft_vec_a(&ray, &r->orig, &inter->trd);
	//|| inter->t2 > ray.y
	if (inter->t2 < 0)
		return (0);
	if (inter->t1 > 0)
		inter->t = inter->t1;
	else
		inter->t = inter->t2;
	ft_vec_ms(&inter->rdt, &r->dir, inter->t);
	ft_vec_a(&inter->p, &r->orig, &inter->rdt);
//	ft_vec_s(&inter->pspo, &inter->p, &cy->u);
	dist1 = pow(cy->u.x - inter->p.x, 2) + pow(cy->u.y - inter->p.y, 2) + pow(cy->u.z - inter->p.z, 2);
	dist2 = pow(pow(cy->radius, 2) - dist1, 0.5);
	// if (dist2 > cy->height / 2)
		// return (0);
	ft_vec_ms(&tmp, &cy->v, dist2);
	ft_vec_a(&center, &cy->u, &tmp);
	ft_vec_s(&inter->n, &inter->p, &center);
	ft_vec_a(&inter->n, &inter->p, &inter->n);
	//ft_vec_set(&inter->n, 0, 0, 1);
//	ft_vec_ms(&hv, &cy->v, cy->height/2);
//	ft_vec_a(&cohv, &cy->u, &hv);
//	ft_vec_s(&copo, &inter->p, &cohv);
//	ft_vec_a(&inter->n, &inter->p, &copo);
	return (1);
}
/*
int		ft_rt_inter_ray_cy(t_ray *r, t_cylinder *cy, t_inter *inter)
{
	inter->a = 1;
	ft_vec_s(&inter->romspo, &r->orig, &cy->u); 
	inter->b = 2 * ft_vec_mul(&r->dir, &inter->romspo);
	inter->sqd_romspo = ft_vec_sqnorm(&inter->romspo);
	inter->c = inter->sqd_romspo - pow(cy->radius, 2);
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
	ft_vec_s(&inter->pspo, &inter->p, &cy->u);
	ft_vec_nv(&inter->n, &inter->pspo);
	return (1);
}


int		ft_rt_inter_ray_cy(t_ray *r, t_cylinder *cy, t_inter *inter)
{
	double alpha;
	double a;
	double b;
	double c;
	t_vector dv;
	t_vector adp;
	t_vector q;
	t_vector trd;
	
	ft_vec_ms(&dv, &cy->v, cy->height);
	a = ft_vec_mul(&r->orig, &dv);
	b = ft_vec_mul(&r->dir, &dv);
	c = ft_vec_mul(&cy->u, &dv);
	alpha = (a + b - c) / ft_vec_mul(&dv, &dv);
	ft_vec_ms(&adp, &cy->v, alpha);
	ft_vec_ms(&trd, &r->dir, alpha);
	ft_vec_a(&q, &r->orig, &trd);
	ft_vec_s(&q, &q, &cy->u);
	ft_vec_s(&q, &q, &adp);
	ft_vec_a(&inter->p, &cy->u, &adp);
	ft_vec_a(&inter->p, &inter->p, &q);
	ft_vec_s(&inter->n, &inter->p, &q);
	inter->t = alpha;
	if (alpha > 1 || alpha < 0)
		return (0);
	return (1);
}


int		ft_rt_inter_ray_cy(t_ray *r, t_cylinder *cy, t_inter *inter)
{

	double t0;
	double t1;

	if (!ft_rt_cy_get_sol(&t0, &t1, cy, r))
		return (0);
	if (t0 > 0)
		check_t(&t0, cy, r);
	if (t1 > 0)
		check_t(&t1, cy, r);
	if (t0 < 0 && t1 < 0)
		return (0);
	if (t1 < t0)
		if (t1 > 0)
			inter->t = t1;
		else
			inter->t = t0;
	else
	{
		if (t0 > 0)
			inter->t = t0;
		else
			inter->t = t1;
	}
	return (1);
}

void		swap_doubles(double *a, double *b)
{
	double buffer;

	buffer = *a;
	*a = *b;
	*b = buffer;
}

t_qparams	new_qparams(double a, double b, double c)
{
	t_qparams params;

	params.a = a;
	params.b = b;
	params.c = c;
	return (params);
}*/
/*
int			ft_rt_solve_quadratic(t_qparams params, double *x0, double *x1)
{
	double discr;
	double q;

	discr = pow(params.b, 2) - 4 * params.a * params.c;
	if (discr < 0)
		return (0);
	else if (discr == 0)
	{
		*x0 = -0.5 * params.b / params.a;
		*x1 = -0.5 * params.b / params.a;
	}
	else
	{
		if (params.b > 0)
			q = -1 * (params.b + sqrt(discr)) / 2;
		else
			q = -1 * (params.b - sqrt(discr)) / 2;
		*x0 = q / params.a;
		*x1 = params.c / q;
	}
	if (*x0 > *x1)
		swap_doubles(x0, x1);
	return (1);
}



t_v3		ft_rt_cy_getnormal(t_v3 point, t_cylinder cylinder)
{
	t_v3 ctp;
	t_v3 normal;

	ctp = substract(point, cylinder.p);
	normal = substract(ctp, v3_multiply(cylinder.normal,
										dot_product(cylinder.normal, ctp)));
	normalize_vector(&normal);
	return (normal);
}

void		check_t(double *t, t_cylinder cy, t_ray r)
{
	t_vector q;
	t_vector p2;
	t_vector cnch;
	t_vector trd;
	t_vector qcu;
	t_vector qp2;
	
	ft_vec_ms(&cnch, cy.normal, cy.height);
	ft_vec_a(&p2, &cy->u, &cnch);
	ft_vec_a(&q, &r->orig, &trd);
	ft_vec_ms(&trd, &r.dir, t);
	ft_vec_s(&qcu, &q, &cy->u);
	if (ft_vec_mul(&cy.normal, &qcu) <= 0)
		*t = -1;
	ft_vec_s(&qp2, &q, &p2);
	if (ft_vec_mul(&cy.normal, &qp2) >= 0)
		*t = -1;
}*/

/*

int			ft_rt_cy_get_sol(double *t0, double *t1, t_cylinder cy,
								t_ray r)
{
	t_vector	a_sqrt;
	t_vector	right;
	t_vector	cn_rdcn;
	double	a;
	double	b;
	double	c;
	double 	ps;

	ps = ft_vec_mul(&r->dir, &cy->normal);
	ft_vec_ms(&cn_rdcn, &cy->normal, ps);
	ft_vec_s(a_sqrt, r->dir, &cn_rdcn);
	a = ft_vec_mul(a_sqrt, a_sqrt);
	right = substract(substract(ray.origin, cylinder.p),
						v3_multiply(cylinder.normal,
							dot_product(substract(ray.origin, cylinder.p),
							cylinder.normal)));
	b = 2 * ft_vec_mul(&a_sqrt, &right);
	c = ft_vec_mul(&right, &right) - (cy.radius * cy.radius);
	if (!ft_rt_solve_quadratic(new_qparams(a, b, c), t0, t1))
		return (0);
	return (1);
}*/