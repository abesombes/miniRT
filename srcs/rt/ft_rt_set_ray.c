/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt_set_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:25:54 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/24 12:24:12 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_rt.h"
#include "../../includes/ft_maths.h"

void    ft_ray_set(t_ray *r, t_vector *origin, t_vector *direction)
{
    ft_vec_set(&r->orig, origin->x, origin->y, origin->z);
    ft_vec_set(&r->dir, direction->x, direction->y, direction->z);
}

void	ft_light_set(t_light *light, t_vector *light_pos, double light_int)
{
	light->pos = *light_pos;
	light->intst = light_int;
}