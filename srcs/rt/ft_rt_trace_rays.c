/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt_trace_rays.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:21:08 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/11 16:22:26 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_rt.h"
#include "../../includes/ft_render.h"

void ft_rt_trace_rays(t_scene *sc)
{
	int i;
	int j;
	
	j = 0;
	while (j < h)
	{
		i = 0;
		while (i < w)
		{
			ft_set_vec(sc->ray.direction, i - w / 2, j - h / 2, -w / (2 * tan(fov / 2)));
			ft_norm_vec(sc->ray.direction);
			ft_set_vec(sc->ray.origin, sc->cam)
			ft_set_ray(ray, origin, direction);
			ft_set_vec(pix_int, 0., 0., 0.);
			pix_int = ft_add_vec(pix_int, ft_get_color(ray, sc, light, 5));
			pix_color = ((int)round(fmin(fmax(pow(pix_int->x, 0.4545), 0), 255)) + 0) << 16 | ((int)round(fmin(fmax(pow(pix_int->y, 0.4545), 0), 255)) + 0) << 8 | ((int)round(fmin(fmax(pow(pix_int->z, 0.4545), 0), 255)));
			my_mlx_pixel_put(&img, i, h - j - 1, pix_color);
			i++;
		}
		j++;
	}
}