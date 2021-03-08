/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths_vec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 22:52:05 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/08 22:52:20 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void    ft_set_vec(t_vector *v, double x, double y, double z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}

t_vector *ft_vec(double x, double y, double z)
{
	t_vector *u;

	if (!(u = (t_vector*)malloc(sizeof(t_vector))))
		return (NULL);
	u->x = x;
	u->y = y;
	u->z = z;
	return (u);
}

t_vector *ft_dup_vec(t_vector *v)
{
    t_vector *w;

    w = (t_vector *)malloc(sizeof(t_vector));
    w->x = v->x;
    w->y = v->y;
    w->z = v->z;
    return (w);
}