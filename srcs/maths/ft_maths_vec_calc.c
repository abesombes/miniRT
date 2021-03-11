/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths_vec_calc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:43:47 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/11 14:44:06 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_maths.h"

t_vector *ft_add_vec(t_vector *u, t_vector *v)
{
    t_vector *w;

    w = (t_vector *)malloc(sizeof(t_vector));
    w->x = u->x + v->x;
    w->y = u->y + v->y;
    w->z = u->z + v->z;
    return(w);
}

t_vector *ft_sub_vec(t_vector *u, t_vector *v)
{
    t_vector *w;

    w = (t_vector *)malloc(sizeof(t_vector));
    w->x = u->x - v->x;
    w->y = u->y - v->y;
    w->z = u->z - v->z;
    return(w);
}

t_vector *ft_cross_vec(t_vector *u, t_vector *v)
{
    t_vector *w;

    w = (t_vector *)malloc(sizeof(t_vector));
	ft_set_vec(w, u->y * v->z - u->z * v->y, u->z * v->x - u->x * v->z, u->x * v->y - u->y * v->x);
	return (w);
}

t_vector *ft_mul_vec_vec(t_vector *u, t_vector *v)
{
    t_vector *w;

    w = (t_vector *)malloc(sizeof(t_vector));
    w->x = u->x * v->x;
    w->y = u->y * v->y;
    w->z = u->z * v->z;
    return (w);
}

t_vector *ft_div_vec(t_vector *u, t_vector *v)
{
    t_vector *w;

    w = (t_vector *)malloc(sizeof(t_vector));
    w->x = u->x / v->x;
    w->y = u->y / v->y;
    w->z = u->z / v->z;
    return (w);
}