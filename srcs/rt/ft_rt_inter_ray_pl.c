/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt_inter_ray_pl.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 00:12:44 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/26 16:15:02 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_rt.h"
#include "../../includes/ft_maths.h"
#include "../../includes/ft_olst.h"

int		ft_rt_inter_ray_pl(t_ray *r, t_plane *pl, t_inter *inter)
{
	t_vector trdir;
	
	inter->denom = ft_vec_mul(&pl->v, &r->dir);
	if (fabs(inter->denom) > 1E-6)
	{
		ft_vec_s(&inter->polo, &pl->u, &r->orig);
		inter->t = ft_vec_mul(&inter->polo, &pl->v) / inter->denom;
		ft_vec_ms(&trdir, &r->dir, inter->t);	
		ft_vec_a(&inter->p, &r->orig, &trdir); 
		inter->n = pl->v;
		return (inter->t >= 0);
	}
	return (0);
}