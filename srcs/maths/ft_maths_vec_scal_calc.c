/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths_vec_scal_calc.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:55:25 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/20 17:43:22 by abesombe         ###   ########.fr       */
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

void	ft_vec_ds(t_vector *w, t_vector *u, double a)
{
    w->x = u->x / a;
    w->y = u->y / a;
    w->z = u->z / a;
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

double ft_vec_mul(t_vector *u, t_vector *v)
{
    return (u->x * v->x + u->y * v->y + u->z * v->z);
}