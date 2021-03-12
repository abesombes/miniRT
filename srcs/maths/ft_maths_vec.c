/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths_vec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 22:52:05 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/12 11:34:06 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_maths.h"

void        ft_vec_set(t_vector *v, double x, double y, double z)
{
	v->x = x;
	v->y = y;
	v->z = z;
}

t_vector    *ft_vec(double x, double y, double z)
{
	t_vector *u;

	if (!(u = (t_vector*)malloc(sizeof(t_vector))))
		return (NULL);
	u->x = x;
	u->y = y;
	u->z = z;
	return (u);
}

void		ft_vec_cpy(t_vector *vec1, t_vector *vec2)
{
	vec1->x = vec2->x;
	vec1->y = vec2->y;
	vec1->z = vec2->z;
}

t_vector    *ft_vec_dup(t_vector *v)
{
	t_vector *w;

	w = (t_vector *)malloc(sizeof(t_vector));
	w->x = v->x;
	w->y = v->y;
	w->z = v->z;
	return (w);
}