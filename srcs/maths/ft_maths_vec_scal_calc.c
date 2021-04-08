/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths_vec_scal_calc.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:55:25 by abesombe          #+#    #+#             */
/*   Updated: 2021/04/08 22:29:47 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_maths.h"

t_vector *ft_vec_div_scal(t_vector *u, double a)
{
    t_vector *w;

    w = (t_vector *)malloc(sizeof(t_vector));
    w->x = u->x / a;
    w->y = u->y / a;
    w->z = u->z / a;
    return(w);
}

t_vector *ft_vec_mul_scal(t_vector *u, double a)
{
    t_vector *w;

    w = (t_vector *)malloc(sizeof(t_vector));
    w->x = u->x * a;
    w->y = u->y * a;
    w->z = u->z * a;
    return (w);
}

void ft_vec_ms(t_vector *w, t_vector *u, double a)
{
    w->x = u->x * a;
    w->y = u->y * a;
    w->z = u->z * a;
}

void ft_vec_ms_clamp(t_vector *w, t_vector *u, double a, double clamp)
{
    w->x = fmin(u->x * a, clamp);
    w->y = fmin(u->y * a, clamp);
    w->z = fmin(u->z * a, clamp);
}

double ft_vec_mul(t_vector *u, t_vector *v)
{
    return (u->x * v->x + u->y * v->y + u->z * v->z);
}