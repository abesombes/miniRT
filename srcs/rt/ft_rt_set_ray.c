/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt_set_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:25:54 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/11 15:26:23 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_rt.h"

void    ft_set_ray(t_ray *r, t_vector *origin, t_vector *direction)
{
    r->origin = (t_vector *)malloc(sizeof(t_vector));
    r->direction = (t_vector *)malloc(sizeof(t_vector));
    ft_set_vec(r->origin, origin->x, origin->y, origin->z);
    ft_set_vec(r->direction, direction->x, direction->y, direction->z);
}

void	ft_set_light(t_light *light, t_vector *light_pos, double light_int)
{
	light->light_pos = light_pos;
	light->light_int = light_int;
}