/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt_cam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:26:13 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/24 21:09:46 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_rt.h"
#include "../../includes/ft_maths.h"
#include "../../includes/ft_olst.h"

void ft_rt_cam_compute(t_scene *sc, t_cam *cam, t_ray *new_ray)
{
    t_vector dx;
    t_vector dy;
    t_vector v_axis;
    t_vector v0;
    t_vector v1;
    t_vector hfdx;
    t_vector hfdy;
    t_vector n_hfdy;
    t_vector tmpx;
    t_vector tmpy;
    t_vector tmp;
    double a;

    ft_vec_set(&v_axis, 0, 1, 0);
    a = ft_vec_mul(&cam->orient, &v_axis);
    printf("\nnorm(cam->orient): [%f]", sqrt(ft_vec_sqnorm(&cam->orient)));
    if (a == 1 || a == -1)
        ft_vec_set(&dy, 0, -1, 0);
    ft_vec_cross(&dy, &cam->orient, &v_axis);
    ft_vec_cross(&dx, &cam->orient, &dy);
    a = 2.0 * tan(cam->fov / 200.0);
    ft_vec_ms(&dx, &dx, a);
    a = a * sc->res_h / sc->res_w;
    ft_vec_ms(&dy, &dy, a);
    ft_vec_ms(&hfdy, &dy, 0.5);
    ft_vec_ms(&hfdx, &dx, 0.5);
    ft_vec_s(&n_hfdy, &cam->orient, &hfdy);
    ft_vec_s(&v0, &n_hfdy, &hfdx);
    ft_vec_norm(&v0);
    ft_vec_ms(&tmpx, &dx, sc->i / sc->res_w);
    ft_vec_ms(&tmpy, &dy, sc->j / sc->res_h);
    ft_vec_s(&tmp, &v0, &tmpx);
    ft_vec_a(&v1, &tmp, &tmpy);
    ft_ray_set(new_ray, &cam->pos, &v1);
}