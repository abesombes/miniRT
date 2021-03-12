/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths_vec_calc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:43:47 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/12 16:23:39 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_maths.h"

t_vector *ft_vec_add(t_vector *u, t_vector *v)
{
    t_vector *w;

    w = (t_vector *)malloc(sizeof(t_vector));
    w->x = u->x + v->x;
    w->y = u->y + v->y;
    w->z = u->z + v->z;
    return(w);
}

t_vector *ft_vec_sub(t_vector *u, t_vector *v)
{
    t_vector *w;

    w = (t_vector *)malloc(sizeof(t_vector));
    w->x = u->x - v->x;
    w->y = u->y - v->y;
    w->z = u->z - v->z;
    return(w);
}

t_vector *ft_vec_cross(t_vector *u, t_vector *v)
{
    t_vector *w;

    w = (t_vector *)malloc(sizeof(t_vector));
	ft_vec_set(w, u->y * v->z - u->z * v->y, u->z * v->x - u->x * v->z, u->x * v->y - u->y * v->x);
	return (w);
}

t_vector *ft_vec_mul_vec(t_vector *u, t_vector *v)
{
    t_vector *w;

    w = (t_vector *)malloc(sizeof(t_vector));
    w->x = u->x * v->x;
    w->y = u->y * v->y;
    w->z = u->z * v->z;
    return (w);
}

t_vector *ft_vec_div(t_vector *u, t_vector *v)
{
    t_vector *w;

    w = (t_vector *)malloc(sizeof(t_vector));
    w->x = u->x / v->x;
    w->y = u->y / v->y;
    w->z = u->z / v->z;
    return (w);
}