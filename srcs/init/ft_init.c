/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 00:53:23 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/14 11:34:03 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int ft_init_sc(t_scene *sc)
{
	sc->res_w = 0;
	sc->res_h = 0;
	return (1);
}

void ft_init_inter(t_inter *inter)
{
	inter->a = 0;
	inter->b = 0;
	inter->c = 0;
	inter->delta = 0;
	inter->t = 0;
	inter->t1 = 0;
	inter->t2 = 0;
}