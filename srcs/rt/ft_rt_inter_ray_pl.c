/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt_inter_ray_pl.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 00:12:44 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/26 14:08:31 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_rt.h"
#include "../../includes/ft_maths.h"
#include "../../includes/ft_olst.h"

int		ft_rt_inter_ray_pl(t_ray *r, t_plane *pl, t_inter *inter)
{
//	double ps;
	inter->denom = ft_vec_mul(&r->dir, &pl->v);
	
	if (inter->denom > 1E-6)
	{

		ft_vec_s(&inter->polo, &pl->u, &r->orig);
		inter->t = ft_vec_mul(&inter->polo, &pl->v) / inter->denom;
		if (inter->t < 0)
			printf("\n PAS D INTERSECTION 28");
		return (inter->t >= 0);
	}
	printf("\n PAS D INTERSECTION L31");
   printf("\n %f %f %f %f", pl->v.x, pl->v.y, pl->v.z, inter->denom);
	return (0);
}