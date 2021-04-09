/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt_inter_ray_pl.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 00:12:44 by abesombe          #+#    #+#             */
/*   Updated: 2021/04/09 15:32:08 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_rt.h"
#include "../../includes/ft_maths.h"
#include "../../includes/ft_olst.h"

int		ft_rt_inter_ray_pl(t_ray *r, t_plane *pl, t_inter *inter)
{
	t_vector	trdir;
	double 		ps;
	
	inter->denom = ft_vec_mul(&pl->v, &r->dir);
//	printf("\ninter->denom: [%f]", inter->denom);
	if (fabs(inter->denom) > 1E-6)
	{
		ft_vec_s(&inter->polo, &pl->u, &r->orig);
		ft_vec_norm(&inter->polo);
		inter->t = ft_vec_mul(&inter->polo, &pl->v) / inter->denom;
		ft_vec_ms(&trdir, &r->dir, inter->t);	
		ft_vec_a(&inter->p, &r->orig, &trdir); 
		inter->n = pl->v;
		ps = ft_vec_mul(&inter->n, &r->dir);
		if (ps == 1)
			ft_vec_ms(&inter->n, &inter->n, -1.0);
	//	printf("\ninter->t: [%f]", inter->t);
		return (inter->t >= 0);
	}
	return (0);
}