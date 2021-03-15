/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths_sp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 10:53:08 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/15 10:57:21 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_maths.h"

void    ft_sp_cpy(t_sphere *sp1, t_sphere *sp2)
{
    sp1->radius = sp2->radius;
    ft_vec_cpy(&sp1->orig, &sp2->orig);
}