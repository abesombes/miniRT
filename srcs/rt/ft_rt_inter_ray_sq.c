/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt_inter_ray_sq.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:15:22 by abesombe          #+#    #+#             */
/*   Updated: 2021/04/08 22:06:07 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/minirt.h"
#include "../../includes/ft_rt.h"
#include "../../includes/ft_maths.h"
#include "../../includes/ft_olst.h"

int		ft_rt_inter_ray_sq(t_ray *r, t_square *sq, t_inter *inter)
{
    double ps;
    
	inter->denom = ft_vec_mul(&sq->v, &r->dir);
	if (fabs(inter->denom) > 1E-6)
	{
		ft_vec_s(&inter->polo, &sq->u, &r->orig);
		inter->t = ft_vec_mul(&inter->polo, &sq->v) / inter->denom;
 		ft_vec_ms(&inter->trd, &r->dir, inter->t);
		ft_vec_a(&inter->p, &r->orig, &inter->trd);
        inter->n = sq->v;
        ps = ft_vec_mul(&r->dir, &inter->n);
	//	printf("\nfabs(ps): [%f]", fabs(ps));
        if (ps == 1)
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