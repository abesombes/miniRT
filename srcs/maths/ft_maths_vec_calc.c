/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths_vec_calc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:43:47 by abesombe          #+#    #+#             */
/*   Updated: 2021/04/08 22:34:28 by abesombe         ###   ########.fr       */
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

void ft_vec_a(t_vector *w, t_vector *u, t_vector *v)
{
    w->x = u->x + v->x;
    w->y = u->y + v->y;
    w->z = u->z + v->z;
}

void ft_vec_ac(t_vector *w, t_vector *u, t_vector *v)
{
    w->x = pow(pow(u->x, 2) + pow(v->x, 2), 0.5);
    w->y = pow(pow(u->y, 2) + pow(v->y, 2), 0.5);
    w->z = pow(pow(u->z, 2) + pow(v->z, 2), 0.5);
}
/*
void ft_vec_ac(t_vector *w, t_vector *u, t_vector *v)
{
    w->x = fmin(pow(pow(u->x, 2) + pow(v->x, 2), 0.5), 255.);
    w->y = fmin(pow(pow(u->y, 2) + pow(v->y, 2), 0.5), 255.);
    w->z = fmin(pow(pow(u->z, 2) + pow(v->z, 2), 0.5), 255.);
}*/

t_vector *ft_vec_sub(t_vector *u, t_vector *v)
{
    t_vector *w;

    w = (t_vector *)malloc(sizeof(t_vector));
    w->x = u->x - v->x;
    w->y = u->y - v->y;
    w->z = u->z - v->z;
    return(w);  
}

void ft_vec_s(t_vector *w, t_vector *u, t_vector *v)
{
    w->x = u->x - v->x;
    w->y = u->y - v->y;
    w->z = u->z - v->z;
}

void ft_vec_cross(t_vector *w, t_vector *u, t_vector *v)
{
	ft_vec_set(w, u->y * v->z - u->z * v->y, u->z * v->x - u->x * v->z, u->x * v->y - u->y * v->x);
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
void ft_vec_mv(t_vector *w, t_vector *u, t_vector *v)
{
    w->x = u->x * v->x;
    w->y = u->y * v->y;
    w->z = u->z * v->z;
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