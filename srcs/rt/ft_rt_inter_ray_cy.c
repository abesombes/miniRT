/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt_inter_ray_cy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:43:04 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/27 14:29:34 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_rt.h"
#include "../../includes/ft_maths.h"
#include "../../includes/ft_olst.h"

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
/*
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