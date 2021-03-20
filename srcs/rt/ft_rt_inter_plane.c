/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt_inter_plane.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:15:13 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/20 12:43:26 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_rt.h"
#include "../../includes/ft_maths.h"
#include "../../includes/ft_olst.h"

int		ft_rt_inter_ray_pl(t_ray *r, t_plane *pl, t_inter *inter)
{
	inter->denom = ft_vec_mul(&r->dir, &pl->v);
	if (fabs(inter->denom) > 1E-6)
	{
		ft_vec_s(&inter->polo, &pl->u, &r->orig);
		inter->t = ft_vec_mul(&inter->polo, &pl->v) / inter->denom;
		return (inter->t >= 0);
	}
	return (0);
}