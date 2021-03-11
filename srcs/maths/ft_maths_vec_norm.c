/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths_vec_norm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:36:19 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/11 14:37:06 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_maths.h"

double  ft_get_sqnorm(t_vector *v)
{
    return (v->x * v->x + v->y * v->y + v->z * v->z);
}

t_vector *ft_get_normvec(t_vector *v)
{
    t_vector *w;

    w = ft_dup_vec(v);
    ft_norm_vec(w);
    return (w);
}

void    ft_norm_vec(t_vector *v)
{
    double norm;

    norm = sqrt(ft_get_sqnorm(v));
    v->x /= norm;
    v->y /= norm;
    v->z /= norm;
}