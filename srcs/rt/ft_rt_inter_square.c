/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt_inter_square.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:15:32 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/20 15:46:43 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_rt.h"
#include "../../includes/ft_maths.h"
#include "../../includes/ft_olst.h"

int		ft_rt_inter_ray_sq(t_ray *r, t_square *sq, t_inter *inter)
{
	inter->denom = ft_vec_mul(&r->dir, &sq->v);
	if (fabs(inter->denom) > 1E-6)
	{
		ft_vec_s(&inter->polo, &sq->u, &r->orig);
		inter->t = ft_vec_mul(&inter->polo, &sq->v) / inter->denom;
 		ft_vec_ms(&inter->trd, &r->dir, inter->t);
		ft_vec_a(&inter->p, &r->orig, &inter->trd);
		if (inter->t >= 0)
		{
			if (fabs((double)(&inter->p.x - &sq->u.x)) > (sq->l / 2) \
				|| fabs((double)(&inter->p.y - &sq->u.y)) > (sq->l / 2) \
					|| fabs((double)(&inter->p.z - &sq->u.z)) > (sq->l / 2))
				return (0);
			return (1);
		}
		return (0);
	}
	return (0);
}