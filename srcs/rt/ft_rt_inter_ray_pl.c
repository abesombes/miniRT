/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt_inter_ray_pl.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 00:12:44 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/26 00:56:12 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_rt.h"
#include "../../includes/ft_maths.h"
#include "../../includes/ft_olst.h"

int		ft_rt_inter_ray_pl(t_ray *r, t_plane *pl, t_inter *inter)
{
	//double ps;
	
	inter->denom = ft_vec_mul(&r->dir, &pl->v);
	printf("\nhello");
	if (fabs(inter->denom) > 1E-6)
	{
		ft_vec_s(&inter->polo, &pl->u, &r->orig);
	//	ps = ft_vec_mul(&inter->polo, &r->dir);
	//	if (ps > 0)
	//		ft_vec_ms(&inter->polo, &inter->polo, -1);
		inter->t = ft_vec_mul(&inter->polo, &pl->v) / inter->denom;
		if (inter->t >= 0)
		printf("\n intersection !");
		return (inter->t >= 0);
	}
	return (0);
}
/*
int	ft_rt_inter_ray_pl(t_ray *r, t_plane *pl, t_inter *inter)
{
	double a, b, t1;
	t_vector tmp;

	ft_vec_s(&tmp, &r->orig, &pl->u);
	a = ft_vec_mul(&tmp, &pl->v);
	b = ft_vec_mul(&r->dir, &pl->v);
	if (b == 0 || (a < 0 && b < 0) || (a > 0 && b > 0))
		return (0);
	t1 = -a / b;
	if (t1 < 0 || inter->t < t1)
		return (0);
	inter->t = t1;
	return (1);
}*/